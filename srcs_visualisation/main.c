/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 16:43:12 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

int			mod(int i)
{
	return (i < 0 ? -i : i);
}

void		ft_change_x(t_graph *graph)
{
	long long int	max;
	long long int	min;
	int				flag;

	flag = 0;
	min = ft_find_min_x(graph);
	max = ft_find_max_x(graph);
	if (max == min)
	{
		flag = 1;
		max++;
	}
	if (min < 0)
		ft_move_negative_x2(graph, min, max);
	else
		ft_move_x_to_start2(graph, min, max);
	if (flag == 1)
	{
		min = ft_find_min_x(graph);
		max = ft_find_max_x(graph);
		ft_centre_x(graph, min, max);
	}
}

void		ft_centre_y(t_graph *graph, int min, int max)
{
	int		move;
	int		j;
	int		index;

	index = graph->indexes + 1;
	j = 0;
	move = ((800 - max) + min) / 2;
	while (index--)
	{
		graph->y[j] += (move - min);
		if (graph->y[j] < 16)
			graph->y[j] = 16;
		if (graph->y[j] > 784)
			graph->y[j] = 784;
		j++;
	}
}

void		ft_change_y(t_graph *graph)
{
	long long int	max;
	long long int	min;
	int				flag;

	flag = 0;
	min = ft_find_min_y(graph);
	max = ft_find_max_y(graph);
	if (max == min)
	{
		flag = 1;
		max++;
	}
	if (min < 0)
		ft_move_negative_y2(graph, min, max);
	else
		ft_move_y_to_start2(graph, min, max);
	if (flag == 1)
	{
		min = ft_find_min_y(graph);
		max = ft_find_max_y(graph);
		ft_centre_y(graph, min, max);
	}
}

int			main(void)
{
	t_graph		*graph;

	if (ft_malloc_graph(&graph) == 0)
		return (0);
	if (ft_start_parsing(graph) == 0)
	{
		write(1, "VISUALISATION ERROR\n", 20);
		exit(0);
	}
	if (graph->indexes != -1)
		ft_print_map(graph);
	exit(0);
}
