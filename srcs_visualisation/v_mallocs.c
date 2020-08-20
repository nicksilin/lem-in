/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_mallocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 12:34:45 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

void			ft_refresh_vert(t_vertices *vert)
{
	vert->name = NULL;
	vert->x = -1;
	vert->y = -1;
	vert->next = NULL;
	vert->haveadj = 0;
	vert->index = 0;
}

void			ft_refresh_graph(t_graph *graph)
{
	graph->start = -1;
	graph->end = -1;
	graph->connects = NULL;
	graph->name = NULL;
	graph->x = 0;
	graph->y = 0;
	graph->visit = 0;
	graph->ants = 0;
	graph->indexes = -1;
	graph->space = 0;
	graph->transfer = 0;
}

int				ft_malloc_vert(t_vertices **vert)
{
	*vert = (t_vertices*)malloc(sizeof(t_vertices));
	if (!*vert)
		return (0);
	ft_refresh_vert(*vert);
	return (1);
}

int				ft_malloc_graph(t_graph **graph)
{
	*graph = (t_graph*)malloc(sizeof(t_graph));
	if (!*graph)
		return (0);
	ft_refresh_graph(*graph);
	return (1);
}

void			ft_help_print(t_graph *graph, t_vis *vis, int n, int j)
{
	if (graph->visit[graph->connects[j]->data[n]] == 0 ||
			graph->visit[j] == 0)
		graph->vis->color = 0x696969;
	vis->x = graph->x[j];
	vis->y = graph->y[j];
	if (graph->connects[j]->data[0] != -1)
		ft_draw_line(graph->x[graph->connects[j]->data[n]],
				graph->y[graph->connects[j]->data[n]], vis);
}
