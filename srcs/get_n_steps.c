/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:52:23 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/10 16:00:41 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

size_t			len_way(t_farm *farm, t_node *node)
{
	size_t		len;

	if (!farm || !node || node->in != farm->start)
		return (0);
	len = 1;
	while (node != farm->end)
	{
		len++;
		node = node->out;
	}
	return (len);
}

static void		sort_way_lens(t_arr *way_lens)
{
	size_t		i;
	size_t		j;
	size_t		buff;

	i = 0;
	while (i < way_lens->size)
	{
		j = 0;
		while (j < way_lens->size - 1)
		{
			if (way_lens->data[j] > way_lens->data[j + 1])
			{
				buff = (size_t)way_lens->data[j];
				way_lens->data[j] = way_lens->data[j + 1];
				way_lens->data[j + 1] = (void *)buff;
			}
			j++;
		}
		i++;
	}
}

void			update_way_lens(t_farm *farm, t_arr *way_lens)
{
	size_t		i;
	t_node		**node;

	way_lens->size = 0;
	node = (t_node **)farm->start->connect->data;
	i = 0;
	while (i < farm->start->connect->size)
	{
		if (node[i]->in == farm->start)
			add_arr(way_lens, (void *)len_way(farm, node[i]));
		i++;
	}
}

size_t			get_n_steps(t_farm *farm, t_arr *way_lens)
{
	size_t		ant;
	size_t		parallel_paths;
	size_t		step_count;

	update_way_lens(farm, way_lens);
	sort_way_lens(way_lens);
	ant = 1;
	parallel_paths = 1;
	step_count = (size_t)way_lens->data[0];
	while (parallel_paths < way_lens->size
	&& step_count == (size_t)way_lens->data[parallel_paths])
	{
		parallel_paths++;
		ant++;
	}
	while (farm->ant > (int)ant)
	{
		step_count++;
		while (parallel_paths < way_lens->size
		&& step_count == (size_t)way_lens->data[parallel_paths])
			parallel_paths++;
		ant += parallel_paths;
	}
	return ((way_lens->size > parallel_paths && (size_t)farm->ant <= ant) ? 0
	: step_count);
}
