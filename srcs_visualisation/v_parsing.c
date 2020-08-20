/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/11 16:28:17 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

void	ft_fill_rooms_zero(int *str, int index)
{
	int	i;

	i = 0;
	while (index)
	{
		str[i] = 0;
		index--;
		i++;
	}
}

int		ft_strlen_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

int		ft_find_index(char *str, char **all, int j)
{
	char	*name;
	int		i;

	i = 0;
	name = (char *)malloc(sizeof(char) * ft_strlen_space(str) + 1);
	name = ft_strcpy_no_spaces(name, str, 0);
	while (j)
	{
		if (ft_strcmp(all[i], name) == 0)
			return (i);
		i++;
		j--;
	}
	return (0);
}

int		ft_start_parsing(t_graph *graph)
{
	t_vertices	*vert;

	if (ft_malloc_vert(&vert) == 0)
		return (0);
	if (ft_read_map(graph, vert) == 0)
		return (0);
	ft_vert_to_graph(vert, graph);
	return (1);
}
