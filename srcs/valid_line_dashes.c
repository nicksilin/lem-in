/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name_dashes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:02:44 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/11 12:13:31 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		find_nodes_dashes(t_node **node, t_farm *farm, const char *str,
				char **delimiter)
{
	char		*delimiter_next;

	if (!node || !farm || !str || !delimiter)
		return (0);
	if ((*delimiter = ft_strchr(str, '-')))
		**delimiter = '\0';
	while (1)
	{
		if ((*node = find_node((char *)str, farm)))
			return (1);
		if (!*delimiter)
			return (0);
		if ((delimiter_next = ft_strchr(*delimiter + 1, '-')))
			*delimiter_next = '\0';
		**delimiter = '-';
		*delimiter = delimiter_next;
	}
}

static void		check_double_name(t_node **node1, t_node **node2, t_farm *farm,
				t_buff *buff)
{
	char		*delimiter;
	char		*delimiter_next;
	char		*end_node1;

	if (!node1 || !node2 || !farm || !buff)
		return ;
	end_node1 = ft_strchr(buff->data, '\0');
	*end_node1 = '-';
	if ((delimiter = ft_strchr(end_node1 + 1, '-')))
		*delimiter = '\0';
	while (delimiter)
	{
		if (find_node(buff->data, farm) && find_node(delimiter + 1, farm))
		{
			*node1 = NULL;
			*node2 = NULL;
			return ;
		}
		if ((delimiter_next = ft_strchr(delimiter + 1, '-')))
			*delimiter_next = '\0';
		*delimiter = '-';
		delimiter = delimiter_next;
	}
	*end_node1 = '\0';
}

static void		get_nodes_dashes(t_node **node1, t_node **node2, t_farm *farm,
				t_buff *buff)
{
	char		*delimiter;
	char		*delimiter_next;

	if (!node1 || !node2 || !farm || !buff)
		return ;
	*node1 = NULL;
	*node2 = NULL;
	if (!find_nodes_dashes(node1, farm, buff->data, &delimiter) || !delimiter)
		return ;
	if (!find_nodes_dashes(node2, farm, delimiter + 1, &delimiter_next))
	{
		*node2 = NULL;
		return ;
	}
	check_double_name(node1, node1, farm, buff);
}

void			get_nodes(t_node **node1, t_node **node2, t_farm *farm,
				t_buff *buff)
{
	char		*delimiter;

	if (!node1 || !node2 || !farm || !buff)
		return ;
	*node1 = NULL;
	*node2 = NULL;
	if (!(delimiter = ft_strchr(buff->data, '-')))
		return ;
	*delimiter = '\0';
	*node1 = find_node(buff->data, farm);
	if (!(ft_strchr(delimiter + 1, '-')))
	{
		*node2 = find_node(delimiter + 1, farm);
		return ;
	}
	*delimiter = '-';
	get_nodes_dashes(node1, node2, farm, buff);
}
