/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_vert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/10 20:31:56 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

t_vertices		*ft_last_vert(t_vertices *vert)
{
	while (vert->next)
		vert = vert->next;
	return (vert);
}

int				ft_add_info_in_vert(char *str, t_vertices *new)
{
	int		j;

	j = 0;
	while (str[j] != ' ')
		j++;
	new->name = (char*)malloc(sizeof(char) * (j + 1));
	new->name = ft_strcpy_no_spaces(new->name, str, 0);
	new->x = ft_atoi(str + j);
	j++;
	while (str[j] != ' ')
		j++;
	new->y = ft_atoi(str + j);
	return (1);
}

t_vertices		*ft_create_new_vert(char *str, t_graph *graph)
{
	t_vertices *new;

	if ((new = (t_vertices*)malloc(sizeof(t_vertices))) == NULL)
		return (NULL);
	if (ft_add_info_in_vert(str, new) != 1)
	{
		free(new);
		return (NULL);
	}
	new->haveadj = 0;
	new->index = graph->indexes;
	new->next = NULL;
	return (new);
}

t_vertices		*vert_push_back(char *str, t_vertices *vert, t_graph *graph)
{
	t_vertices	*new;
	t_vertices	*last;

	if ((new = ft_create_new_vert(str, graph)) == NULL)
		return (NULL);
	if (vert->name == NULL)
	{
		*vert = *new;
		return (vert);
	}
	last = ft_last_vert(vert);
	last->next = new;
	return (vert);
}

void			ft_vert_to_graph(t_vertices *vert, t_graph *graph)
{
	ft_vert_to_graph_x(vert, graph);
	ft_vert_to_graph_y(vert, graph);
	ft_vert_to_graph_names(vert, graph);
	ft_vert_to_graph_connects(vert, graph);
}
