/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:20:51 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/10 12:31:16 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_node	*get_last_node(void *node_first)
{
	t_node		*node_tmp;

	if (!node_first)
		return (NULL);
	node_tmp = (t_node *)node_first;
	while (node_tmp->out && node_tmp->out->out)
		node_tmp = node_tmp->out;
	return (node_tmp);
}

static size_t	find_min_len(const size_t *arr, int len)
{
	size_t		i;
	size_t		min;

	if (!arr)
		return (0);
	min = -1;
	i = 0;
	while (i < (size_t)len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

static void		distribute_ants(t_node **way_start_arr, size_t *way_len_arr,
								int size, int ant)
{
	size_t		max_len;
	size_t		i;

	max_len = find_min_len(way_len_arr, size);
	while (ant)
	{
		i = 0;
		while (i < (size_t)size && ant)
		{
			if (way_len_arr[i] <= max_len)
			{
				way_start_arr[i]->mark++;
				ant--;
			}
			i++;
		}
		max_len++;
	}
}

static int		init_way_arrs(t_farm *farm, t_node ***node, size_t **len,
				int size)
{
	size_t		i;
	size_t		i_arr;

	if (!farm || !node || !len)
		return (0);
	if (!(*node = (t_node **)malloc(sizeof(t_node *) * size)))
		return (0);
	if (!(*len = (size_t *)malloc(sizeof(size_t) * size)))
	{
		free(*node);
		return (0);
	}
	i = -1;
	i_arr = 0;
	while (++i < farm->start->connect->size)
	{
		if (((t_node *)farm->start->connect->data[i])->in == farm->start)
		{
			(*node)[i_arr] = get_last_node(farm->start->connect->data[i]);
			(*len)[i_arr] = len_way(farm, farm->start->connect->data[i]);
			(*node)[i_arr]->mark = 0;
			i_arr++;
		}
	}
	return (1);
}

int				print_way(t_farm *farm, int n_way)
{
	t_node		**way_start_arr;
	size_t		*way_len_arr;

	if (!init_way_arrs(farm, &way_start_arr, &way_len_arr, n_way))
		return (0);
	write(1, "\n", 1);
	distribute_ants(way_start_arr, way_len_arr, n_way, farm->ant);
	print(way_start_arr, way_len_arr, n_way);
	free(way_len_arr);
	way_len_arr = NULL;
	free(way_start_arr);
	way_start_arr = NULL;
	return (1);
}
