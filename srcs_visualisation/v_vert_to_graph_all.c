/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_vert_to_graph_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/10 20:29:31 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

void	ft_vert_to_graph_x(t_vertices *vert, t_graph *graph)
{
	int			i;
	int			j;

	j = 0;
	i = graph->indexes + 1;
	graph->x = (int *)malloc(sizeof(int) * i);
	while (i)
	{
		graph->x[j] = vert->x;
		vert = vert->next;
		j++;
		i--;
	}
}

void	ft_vert_to_graph_y(t_vertices *vert, t_graph *graph)
{
	int			i;
	int			j;

	j = 0;
	i = graph->indexes + 1;
	graph->y = (int *)malloc(sizeof(int) * i);
	while (i)
	{
		graph->y[j] = vert->y;
		vert = vert->next;
		j++;
		i--;
	}
}

void	ft_vert_to_graph_names(t_vertices *vert, t_graph *graph)
{
	int		i;
	int		j;

	j = 0;
	i = graph->indexes + 1;
	graph->name = (char **)malloc(sizeof(char *) * i);
	while (i)
	{
		graph->name[j] = (char *)malloc(sizeof(char) *
				ft_strlen(vert->name) + 1);
		ft_strcpy(graph->name[j], vert->name);
		vert = vert->next;
		j++;
		i--;
	}
}

void	ft_vert_to_graph_connects_help(t_array *from, t_array *to)
{
	unsigned	i;
	int			j;

	if (!from || !to)
		return ;
	j = 0;
	i = from->id;
	while (i)
	{
		add(to, from->data[j]);
		j++;
		i--;
	}
}

void	ft_vert_to_graph_connects(t_vertices *vert, t_graph *graph)
{
	int		i;
	int		j;

	j = 0;
	i = graph->indexes + 1;
	graph->connects = (t_array **)malloc(sizeof(t_array *) * i);
	while (i)
	{
		graph->connects[j] = create(1);
		if (vert->haveadj == 1)
			ft_vert_to_graph_connects_help(vert->adjacent, graph->connects[j]);
		else
			add(graph->connects[j], -1);
		vert = vert->next;
		j++;
		i--;
	}
}
