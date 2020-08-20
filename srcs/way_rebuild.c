/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_rebuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:36:48 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/09 08:36:48 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		update_in_out(t_node *prev, t_node *current, t_node *next)
{
	if (!current || !next)
		return ;
	if (next == current->out && (prev && prev == current->in))
	{
		current->in = NULL;
		current->out = NULL;
		return ;
	}
	if (!current->out || next == current->out)
		current->out = prev;
	if (!current->in || (prev && prev == current->in))
		current->in = next;
}

void			way_rebuilding(t_farm *farm, t_queue *queue)
{
	size_t		i;
	t_node		**node;
	t_node		*prev;
	t_node		*current;
	t_node		*next;

	if (!farm || !queue || !queue->node[queue->i_end])
		return ;
	node = queue->node;
	prev = NULL;
	current = node[queue->i_end];
	i = queue->prev[queue->i_end];
	next = node[i];
	while (current && next)
	{
		update_in_out(prev, current, next);
		i = queue->prev[i];
		prev = current;
		current = next;
		next = (next == farm->start) ? NULL : node[i];
	}
	if (prev)
		farm->start->out = prev;
}
