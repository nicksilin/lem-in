/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:32:37 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/09 11:52:54 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void				delete_last_way(t_way *way, t_queue *queue)
{
	size_t			i_way;
	size_t			i_queue;

	if (!way || !queue)
		return ;
	i_way = 0;
	i_queue = queue->i_end;
	while (i_way < way->size && queue->node[i_queue])
	{
		queue->node[i_queue]->in = way->in[i_way];
		queue->node[i_queue]->out = way->out[i_way];
		i_way++;
		i_queue = queue->prev[i_queue];
	}
}

void				way_save(t_way *way, t_queue *queue)
{
	size_t			i;

	if (!way || !queue)
		return ;
	way->size = 0;
	i = queue->i_end;
	while (i > 0)
	{
		if (!queue->node || !queue->node[i])
			return ;
		way->in[way->size] = queue->node[i]->in;
		way->out[way->size++] = queue->node[i]->out;
		i = queue->prev[i];
	}
}

void				delete_way(t_way **way)
{
	if (!way || !*way)
		return ;
	if ((*way)->in)
	{
		free((*way)->in);
		(*way)->in = NULL;
	}
	if ((*way)->out)
	{
		free((*way)->out);
		(*way)->out = NULL;
	}
	free(*way);
	*way = NULL;
}

t_way				*create_way(size_t mem)
{
	t_way			*way;

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return (NULL);
	if (!(way->in = (t_node **)malloc(sizeof(t_node *) * mem)))
	{
		delete_way(&way);
		return (NULL);
	}
	if (!(way->out = (t_node **)malloc(sizeof(t_node *) * mem)))
	{
		delete_way(&way);
		return (NULL);
	}
	way->size = 0;
	way->mem = mem;
	return (way);
}
