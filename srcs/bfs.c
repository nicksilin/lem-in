/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:21:21 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/09 08:21:21 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		is_valid_line(t_node *node, t_node *next_node, char flag)
{
	if (node->mark == next_node->mark)
		return (0);
	if (node->out == next_node || next_node->in == node)
		return (0);
	if (node->in != next_node && flag)
		return (0);
	return (1);
}

static int		added_end(t_queue *queue, t_node *node, t_node *end)
{
	size_t		i;
	t_node		**next_node;

	if (!queue || !node || !end)
		return (0);
	next_node = (t_node **)node->connect->data;
	i = 0;
	while (i < node->connect->size)
	{
		if (is_valid_line(node, next_node[i], queue->revs[queue->i_begin]))
		{
			queue->node[queue->i_end] = next_node[i];
			queue->prev[queue->i_end] = queue->i_begin;
			queue->revs[queue->i_end] = 0;
			if (next_node[i]->out && (!node->out || next_node[i]->out != node))
				queue->revs[queue->i_end] = 1;
			next_node[i]->mark = node->mark;
			if (next_node[i] == end)
				return (1);
			queue->node[++queue->i_end] = NULL;
		}
		i++;
	}
	queue->i_begin++;
	return (0);
}

int				bfs(t_farm *farm, t_queue *queue)
{
	if (!farm || !queue || !farm->node || !farm->start || !farm->end
	|| !queue->node || !queue->prev || !queue->revs)
		return (0);
	farm->start->mark++;
	queue->node[0] = farm->start;
	queue->i_begin = 0;
	queue->i_end = 1;
	while (queue->i_begin < queue->i_end)
		if (added_end(queue, queue->node[queue->i_begin], farm->end))
			return (1);
	return (0);
}
