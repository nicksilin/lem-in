/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_write_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:11:03 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/10 20:30:58 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

int		ft_add_adj_help(t_vertices *vert, int ind_x, int ind_y)
{
	while (vert->index != ind_x)
		vert = vert->next;
	if (vert->haveadj == 0)
	{
		vert->adjacent = create(1);
		vert->haveadj = 1;
	}
	add(vert->adjacent, ind_y);
	return (1);
}

int		ft_add_adj_x(t_vertices *vert, int ind_x, int ind_y)
{
	if (ft_add_adj_help(vert, ind_x, ind_y) == 0 ||
			ft_add_adj_help(vert, ind_y, ind_x) == 0)
		return (0);
	return (1);
}

int		ft_find_ind(t_vertices *vert, char *i)
{
	while (vert)
	{
		if (ft_strcmp(vert->name, i) == 0)
			return (vert->index);
		vert = vert->next;
	}
	return (-1);
}

int		ft_write_links(t_vertices *vert, char *x, char *y)
{
	int		ind_x;
	int		ind_y;

	ind_x = ft_find_ind(vert, x);
	ind_y = ft_find_ind(vert, y);
	if (ind_x == -1 || ind_y == -1)
		return (0);
	if (ft_add_adj_x(vert, ind_x, ind_y) == 0)
		return (0);
	return (1);
}

int		ft_name_not_dub(t_vertices *vert, char *value)
{
	if (vert->name == NULL)
		return (1);
	while (vert)
	{
		if (ft_strcmp(vert->name, value) == 0)
			return (0);
		vert = vert->next;
	}
	return (1);
}
