/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:10:55 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/12 15:48:03 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int			get_x(t_node *node)
{
	if (!node)
		return (0);
	return (ft_atoi(node->name + node->name_len + 1));
}

static int			get_y(t_node *node)
{
	size_t			i;
	char			*str;

	str = node->name + node->name_len + 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	return (ft_atoi(&str[i]));
}

static int			check_repeat(t_coordinates *coord, size_t size)
{
	size_t			i;
	size_t			j;

	if (!coord)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (coord[i].x == coord[j].x)
		{
			if (coord[i].x == coord[j].x && coord[i].y == coord[j].y)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void				init_coordinates(t_farm *farm, t_coordinates **coord)
{
	size_t			i;

	if (!farm || !coord || !*coord)
		return ;
	i = 0;
	while (i < farm->n_node)
	{
		farm->node[i]->name_len = ft_strlen(farm->node[i]->name);
		(*coord)[i].x = get_x(farm->node[i]);
		(*coord)[i].y = get_y(farm->node[i]);
		i++;
	}
}

int					valid_coordinates(t_farm *farm)
{
	t_coordinates	*coordinates;
	t_coordinates	*buff;
	int				result;

	if (!farm)
		return (0);
	if (!(coordinates = create_coordinates(farm->n_node)))
		return (0);
	if (!(buff = create_coordinates(farm->n_node)))
	{
		delete_coordinates(&coordinates);
		return (0);
	}
	init_coordinates(farm, &coordinates);
	merge_sort_xy(coordinates, buff, 0, farm->n_node - 1);
	result = check_repeat(coordinates, farm->n_node);
	delete_coordinates(&coordinates);
	delete_coordinates(&buff);
	return (result);
}
