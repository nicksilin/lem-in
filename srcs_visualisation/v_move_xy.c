/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_move_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 16:35:48 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

void		ft_move_negative_x2(t_graph *graph, long long int min,
		long long int max)
{
	int		ind;
	int		j;

	j = 0;
	ind = graph->indexes + 1;
	while (ind--)
	{
		graph->x[j] = (graph->x[j] - min) * 1200 / (max - min);
		if (graph->x[j] < 16)
			graph->x[j] = 16;
		if (graph->x[j] > 1184)
			graph->x[j] = 1184;
		j++;
	}
}

void		ft_move_x_to_start2(t_graph *graph, long long int min,
		long long int max)
{
	int		index;
	int		j;

	index = graph->indexes + 1;
	j = 0;
	while (index--)
	{
		graph->x[j] = (graph->x[j] - min) * 1200 / (max - min);
		if (graph->x[j] < 16)
			graph->x[j] = 16;
		if (graph->x[j] > 1184)
			graph->x[j] = 1184;
		j++;
	}
}

void		ft_move_negative_y2(t_graph *graph, long long int min,
		long long int max)
{
	int		ind;
	int		j;

	j = 0;
	ind = graph->indexes + 1;
	while (ind--)
	{
		graph->y[j] = (graph->y[j] - min) * 800 / (max - min);
		if (graph->y[j] < 16)
			graph->y[j] = 16;
		if (graph->y[j] > 784)
			graph->y[j] = 784;
		j++;
	}
}

void		ft_move_y_to_start2(t_graph *graph, long long int min,
		long long int max)
{
	int		index;
	int		j;

	index = graph->indexes + 1;
	j = 0;
	while (index--)
	{
		graph->y[j] = (graph->y[j] - min) * 800 / (max - min);
		if (graph->y[j] < 16)
			graph->y[j] = 16;
		if (graph->y[j] > 784)
			graph->y[j] = 784;
		j++;
	}
}

int			ft_help_check(char *map, t_graph *graph, t_vertices *vert)
{
	if (graph->transfer == 0)
	{
		if (ft_help_l(graph, vert) == 0)
			return (0);
	}
	if (ft_push_steps(map, graph) == 0)
		return (0);
	return (1);
}
