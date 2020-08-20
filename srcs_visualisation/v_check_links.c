/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_check_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:11:03 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 16:58:35 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

int		ft_check_links_onedash(char *str, t_vertices *vert)
{
	int		i;
	char	*first;

	i = 0;
	while (str[i] != '-')
		i++;
	first = (char*)malloc(sizeof(char) * i + 1);
	first = ft_strncpy(first, str, i);
	if (ft_name_not_dub(vert, first) == 1 ||
			ft_name_not_dub(vert, str + i + 1) == 1)
	{
		free(first);
		return (0);
	}
	if (ft_write_links(vert, first, str + i + 1) == 0)
	{
		free(first);
		return (0);
	}
	free(first);
	return (1);
}

int		ft_find_room(char *str, int i, t_vertices *vert)
{
	char		*first;

	first = (char*)malloc(sizeof(char) * i + 1);
	first = ft_strncpy(first, str, i);
	if (ft_write_links(vert, first, str + i + 1) == 0)
	{
		free(first);
		return (0);
	}
	free(first);
	return (1);
}

int		ft_parse_link(char *str, t_vertices *vert)
{
	int					match;
	unsigned int		i;

	i = 1;
	match = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			if (i < ft_strlen(str) - 1)
			{
				match = match + ft_find_room(str, i, vert);
			}
		}
		i++;
	}
	if (match == 1)
		return (1);
	else
		return (0);
}

int		ft_check_links(char *str, t_vertices *vert)
{
	if (ft_check_dash(str) == 1 &&
			(str[0] == '-' || str[ft_strlen(str) - 1] == '-'))
		return (0);
	if (ft_check_dash(str) == 1)
	{
		if (ft_check_links_onedash(str, vert) == 1)
			return (1);
		else
			return (0);
	}
	else
	{
		if (ft_parse_link(str, vert) == 1)
			return (1);
		else
			return (0);
	}
}

int		ft_find_end(t_vertices *vert, t_vertices *tmp, t_graph *graph,
		int *counter)
{
	unsigned	i;
	t_vertices	*next_link;

	if (tmp->haveadj == 0)
		return (0);
	if (tmp->index == graph->end)
	{
		(*counter)++;
		return (1);
	}
	i = tmp->adjacent->id;
	while (i)
	{
		if (tmp->adjacent->id == 0)
			return (1);
		next_link = vert;
		while (next_link->index != tmp->adjacent->data[i - 1])
			next_link = next_link->next;
		del(tmp->adjacent, &tmp->adjacent->data[i - 1]);
		ft_find_end(vert, next_link, graph, counter);
		i--;
	}
	return (1);
}
