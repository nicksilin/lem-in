/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:09:42 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/10 14:47:59 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	add_connect(t_node *node1, t_node *node2)
{
	size_t	i;

	if (!node1 || !node2 || !node1->connect || !node2->connect)
		return (0);
	if (node1 == node2)
		return (1);
	i = 0;
	while (i < node1->connect->size && node1->connect->data[i] != (void *)node2)
		i++;
	if (i < node1->connect->size)
		return (1);
	return (add_arr(node1->connect, (void *)node2)
			&& add_arr(node2->connect, (void *)node1));
}

static void	update_buff(t_buff *buff, char flag)
{
	char	*end_line;
	size_t	i;
	size_t	delta;

	end_line = ft_strchr(buff->data, '\0');
	if (flag)
		end_line = ft_strchr(end_line + 1, '\0');
	i = 0;
	delta = (size_t)(end_line - buff->data) + 1;
	while (i + delta < buff->size)
	{
		buff->data[i] = buff->data[i + delta];
		i++;
	}
	buff->data[i] = '\0';
	buff->size -= delta - 1;
	buff->size -= buff->size ? 1 : 0;
}

static int	valid_connect(t_buff *buff, t_farm *farm, int *flag)
{
	t_node	*node1;
	t_node	*node2;

	if (gnl_buff(buff) < 1 && !buff->size)
		return (0);
	(flag && !*flag) ? *flag = 1 : ft_putendl(&buff->data[buff->i]);
	if (is_comment(buff))
	{
		buff->i = 0;
		update_buff(buff, 0);
		return (1);
	}
	get_nodes(&node1, &node2, farm, buff);
	if (!node1 || !node2)
		return (0);
	if (!add_connect(node1, node2))
		return (0);
	update_buff(buff, 1);
	return (1);
}

int			valid_line(t_buff *buff, t_farm *farm)
{
	int		flag;

	flag = 0;
	while (valid_connect(buff, farm, &flag))
		;
	if (buff->size)
		return (0);
	return (1);
}
