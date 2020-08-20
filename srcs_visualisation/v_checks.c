/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_checks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 16:34:58 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

int		ft_check_spaces(char *str)
{
	int		i;
	int		space;

	space = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	return (space);
}

int		ft_check_dash(char *str)
{
	int		i;
	int		dash;

	dash = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			dash++;
		i++;
	}
	return (dash);
}

int		ft_check_string_2(char *str, t_graph *graph, t_vertices *vert)
{
	if (ft_check_spaces(str) == 2)
	{
		graph->indexes = graph->indexes + 1;
		if (vert_push_back(str, vert, graph) == NULL)
			return (0);
		return (1);
	}
	else if (ft_check_spaces(str) == 0)
	{
		if (ft_check_links(str, vert) == 0)
			return (0);
		return (1);
	}
	else
		return (0);
}

int		ft_check_string(char *str, t_graph *graph, t_vertices *vert)
{
	if (str[1] == '#')
	{
		if (ft_strcmp(str, "##start") == 0)
			graph->start = graph->indexes + 1;
		else if (ft_strcmp(str, "##end") == 0)
			graph->end = graph->indexes + 1;
	}
	if (str[0] == '#')
		return (1);
	return (ft_check_string_2(str, graph, vert));
}

int		ft_check_map(char *map, t_graph *graph, t_vertices *vert)
{
	if (ft_strlen(map) == 0)
	{
		graph->space = 1;
		return (1);
	}
	if (map[0] == 'L')
	{
		if (ft_help_check(map, graph, vert) == 1)
			return (1);
		return (0);
	}
	if (map[0] == '#' && ft_strcmp(map, "##end") != 0 &&
			ft_strcmp(map, "##start") != 0)
		return (1);
	if (graph->ants == 0)
	{
		graph->ants = ft_atoi(map);
		return (1);
	}
	if (ft_check_string(map, graph, vert) == 0)
		return (0);
	return (1);
}
