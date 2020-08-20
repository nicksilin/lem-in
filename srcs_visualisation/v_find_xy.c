/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_find_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 11:56:40 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

long long int	ft_find_min_y(t_graph *graph)
{
	int				index;
	int				j;
	long long int	min;

	index = graph->indexes + 1;
	j = 0;
	min = 9223372036854775807;
	while (index--)
	{
		if (graph->y[j] < min)
			min = graph->y[j];
		j++;
	}
	if (min == 0)
		min++;
	return (min);
}

long long int	ft_find_max_y(t_graph *graph)
{
	int				index;
	int				j;
	long long int	max;

	index = graph->indexes + 1;
	j = 0;
	max = -9223372036854775807;
	while (index--)
	{
		if (graph->y[j] > max)
			max = graph->y[j];
		j++;
	}
	if (max == 0)
		max++;
	return (max);
}

long long int	ft_find_min_x(t_graph *graph)
{
	int				index;
	int				j;
	long long int	min;

	index = graph->indexes + 1;
	j = 0;
	min = 9223372036854775807;
	while (index--)
	{
		if (graph->x[j] < min)
			min = graph->x[j];
		j++;
	}
	if (min == 0)
		min++;
	return (min);
}

long long int	ft_find_max_x(t_graph *graph)
{
	int				index;
	int				j;
	long long int	max;

	index = graph->indexes + 1;
	j = 0;
	max = -9223372036854775807;
	while (index--)
	{
		if (graph->x[j] > max)
			max = graph->x[j];
		j++;
	}
	if (max == 0)
		max++;
	return (max);
}

void			ft_centre_x(t_graph *graph, long long int min,
		long long int max)
{
	long long int	move;
	int				j;
	int				index;

	index = graph->indexes + 1;
	j = 0;
	move = ((1200 - max) + min) / 2;
	while (index--)
	{
		graph->x[j] += (move - min);
		if (graph->x[j] < 16)
			graph->x[j] = 16;
		if (graph->x[j] > 1184)
			graph->x[j] = 1184;
		j++;
	}
}
