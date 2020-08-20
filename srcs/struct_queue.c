/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:49:49 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/09 07:49:49 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			delete_queue(t_queue **queue)
{
	if (!queue || !*queue)
		return ;
	if ((*queue)->node)
		free((*queue)->node);
	if ((*queue)->prev)
		free((*queue)->prev);
	if ((*queue)->revs)
		free((*queue)->revs);
	(*queue)->node = NULL;
	(*queue)->prev = NULL;
	(*queue)->revs = NULL;
	free(*queue);
	*queue = NULL;
}

t_queue			*create_queue(size_t mem)
{
	t_queue		*queue;
	size_t		i;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	if (!(queue->node = (t_node **)malloc(sizeof(t_node *) * mem)))
	{
		delete_queue(&queue);
		return (NULL);
	}
	if (!(queue->prev = (size_t *)malloc(sizeof(size_t) * mem)))
	{
		delete_queue(&queue);
		return (NULL);
	}
	if (!(queue->revs = (char *)malloc(sizeof(char) * mem)))
	{
		delete_queue(&queue);
		return (NULL);
	}
	i = 0;
	while (i < mem)
		queue->revs[i++] = 0;
	queue->mem = mem;
	return (queue);
}
