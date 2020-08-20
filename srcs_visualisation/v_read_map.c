/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/10 12:22:41 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

int		ft_read_map(t_graph *graph, t_vertices *vert)
{
	char	*map;

	while (get_next_line(0, &map))
	{
		if (ft_check_map(map, graph, vert) != 1)
		{
			free(map);
			return (0);
		}
		free(map);
	}
	if (graph->space == 1)
		return (0);
	return (1);
}
