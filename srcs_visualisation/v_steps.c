/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_steps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 16:29:06 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

int			ft_mark_rooms(int *istr, char *str, t_graph *graph)
{
	int		i;

	if (graph->name == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'L')
		{
			i++;
			i += ft_strlen(ft_itoa(ft_atoi(str + i))) + 1;
			istr[ft_find_index(str + i, graph->name, graph->indexes + 1)] = 1;
			graph->visit[ft_find_index(str + i, graph->name,
					graph->indexes + 1)] = 1;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (1);
}

t_steps		*ft_create_new_step(char *str, t_graph *graph)
{
	t_steps *new;

	if ((new = (t_steps*)malloc(sizeof(t_steps))) == NULL)
		return (NULL);
	if ((new->rooms = (int*)malloc(sizeof(int) * graph->indexes + 10)) == NULL)
		return (NULL);
	ft_fill_rooms_zero(new->rooms, graph->indexes + 1);
	if (ft_mark_rooms(new->rooms, str, graph) == 0)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_steps		*ft_last_step(t_steps *step)
{
	while (step->next != NULL)
		step = step->next;
	return (step);
}

int			ft_push_steps(char *str, t_graph *graph)
{
	t_steps	*new;
	t_steps	*last;

	new = ft_create_new_step(str, graph);
	if (new == NULL)
		return (0);
	last = ft_last_step(graph->steps);
	new->prev = last;
	last->next = new;
	return (1);
}

int			ft_help_l(t_graph *graph, t_vertices *vert)
{
	graph->space = 0;
	ft_vert_to_graph(vert, graph);
	graph->steps = ft_create_new_step(" ", graph);
	if (graph->steps == NULL)
		return (0);
	graph->transfer = 1;
	graph->visit = (int *)malloc(sizeof(int) * graph->indexes + 10);
	ft_fill_rooms_zero(graph->visit, graph->indexes + 1);
	graph->visit[graph->start] = 1;
	return (1);
}
