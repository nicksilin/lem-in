/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:59:58 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/10 15:55:54 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		fast_print(t_farm *farm)
{
	int			ant;

	write(1, "\n", 1);
	ant = 1;
	while (ant <= farm->ant)
	{
		write(1, "L", 1);
		ft_putnbr(ant);
		write(1, "-", 1);
		write(1, farm->end->name, farm->end->name_len);
		write(1, " ", 1);
		ant++;
	}
	write(1, "\n", 1);
}

static int		fast_way(t_farm *farm)
{
	size_t		i;

	i = 0;
	while (i < farm->start->connect->size)
	{
		if (((t_node *)farm->start->connect->data[i]) == farm->end)
		{
			fast_print(farm);
			return (1);
		}
		i++;
	}
	return (0);
}

static int		find_best_way(t_farm *farm, t_queue *queue, t_arr *way_lens,
				t_way *way)
{
	int			n_way;
	int			n_step;
	int			best_n_step;

	n_way = 0;
	best_n_step = 2147483647;
	if (!farm || !queue || !way_lens)
		return (0);
	while (bfs(farm, queue))
	{
		way_save(way, queue);
		way_rebuilding(farm, queue);
		if (!(n_step = get_n_steps(farm, way_lens)) || n_step > best_n_step)
		{
			delete_last_way(way, queue);
			break ;
		}
		best_n_step = n_step;
		n_way++;
	}
	return (n_way);
}

int				solve(t_farm *farm)
{
	t_queue		*queue;
	t_way		*way;
	t_arr		*way_lens;
	int			result;

	if (fast_way(farm))
		return (1);
	queue = create_queue(farm->n_node);
	way = (queue == NULL) ? NULL : create_way(farm->n_node);
	way_lens = (way == NULL) ? NULL :
	create_arr(min(farm->start->connect->size, farm->end->connect->size));
	if (!queue || !way || !way_lens)
	{
		delete_queue(&queue);
		delete_way(&way);
		delete_arr(&way_lens);
		return (0);
	}
	if ((result = find_best_way(farm, queue, way_lens, way)))
		result = print_way(farm, result);
	delete_queue(&queue);
	delete_way(&way);
	delete_arr(&way_lens);
	return (result);
}
