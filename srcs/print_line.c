/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:54:01 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/10 13:23:28 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		print_node(t_node *node)
{
	if (!node)
		return ;
	write(1, "L", 1);
	ft_putnbr(node->ant);
	write(1, "-", 1);
	write(1, node->name, node->name_len);
	write(1, " ", 1);
}

static void		print_line(t_node *node, int *ant_name)
{
	t_node		*tmp;

	tmp = node;
	while (1)
	{
		tmp->out->ant = tmp->ant;
		if (tmp->ant)
			print_node(tmp->out);
		if (!tmp->in->in)
			break ;
		tmp = tmp->in;
	}
	if (!node->mark)
	{
		tmp->ant = 0;
		return ;
	}
	tmp->ant = *ant_name;
	print_node(tmp);
	*ant_name += 1;
	node->mark--;
}

static int		get_steps(t_node **way_start, const size_t *way_len, int n_way)
{
	size_t		i;
	int			maximum;
	int			tmp;

	if (!way_start || !way_len)
		return (0);
	maximum = 0;
	i = 0;
	while (i < (size_t)n_way)
	{
		tmp = (int)way_start[i]->mark + (int)way_len[i] - 1;
		if (tmp > maximum)
			maximum = tmp;
		i++;
	}
	return (maximum);
}

void			print(t_node **way_start_arr, size_t *way_len_arr, int n_way)
{
	int			ant_name;
	int			n_steps;
	int			i;

	ant_name = 1;
	n_steps = get_steps(way_start_arr, way_len_arr, n_way);
	while (n_steps)
	{
		i = 0;
		while (i < n_way)
		{
			print_line(way_start_arr[i], &ant_name);
			i++;
		}
		write(1, "\n", 1);
		n_steps--;
	}
}
