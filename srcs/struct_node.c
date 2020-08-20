/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 11:50:30 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/09 08:46:49 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		delete_node(t_node **node)
{
	if (!node || !*node)
		return ;
	if ((*node)->connect)
		delete_arr(&(*node)->connect);
	free(*node);
	*node = NULL;
}

void		*delete_node_array(t_node ***array, size_t size)
{
	size_t	i;

	if (!array || !*array)
		return (NULL);
	i = 0;
	while (i < size)
		delete_node(&(*array)[i++]);
	free(*array);
	*array = NULL;
	return (NULL);
}

t_node		*create_node(char *name)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (!(node->connect = create_arr(1)))
	{
		free(node);
		return (NULL);
	}
	node->name = name;
	node->name_len = -1;
	node->in = NULL;
	node->out = NULL;
	node->mark = 0;
	node->ant = 0;
	return (node);
}

t_node		**create_node_array(size_t size, t_arr *name)
{
	t_node	**array;
	size_t	i;

	if (!name)
		return (NULL);
	if (!(array = (t_node **)malloc(sizeof(t_node *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(array[i] = create_node((char *)name->data[i])))
			return ((t_node **)delete_node_array(&array, i));
		i++;
	}
	return (array);
}
