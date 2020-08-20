/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dynamic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:15:59 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/08 10:15:59 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		copy_arr(void **to, void **from, size_t size)
{
	size_t		i;

	if (!to || !from)
		return ;
	i = 0;
	while (i < size)
	{
		to[i] = from[i];
		i++;
	}
}

static int		resize_arr(t_arr *arr, size_t new_mem)
{
	void		**new_data;

	if (!(new_data = (void **)malloc(sizeof(void *) * new_mem)))
		return (0);
	copy_arr(new_data, arr->data, arr->size);
	free(arr->data);
	arr->data = new_data;
	arr->mem = new_mem;
	return (1);
}

int				add_arr(t_arr *arr, void *val)
{
	if (!arr || !val || !arr->data)
		return (0);
	if (arr->size == arr->mem)
		if (!(resize_arr(arr, arr->mem * 2)))
			return (0);
	arr->data[arr->size++] = val;
	return (1);
}

void			delete_arr(t_arr **arr)
{
	if (!arr || !*arr)
		return ;
	if ((*arr)->data)
		free((*arr)->data);
	(*arr)->data = NULL;
	free(*arr);
	*arr = NULL;
}

t_arr			*create_arr(size_t mem)
{
	t_arr		*arr;

	if (!(arr = (t_arr *)malloc(sizeof(t_arr))))
		return (NULL);
	if (!(arr->data = (void **)malloc(sizeof(void *) * mem)))
	{
		free(arr);
		return (NULL);
	}
	arr->size = 0;
	arr->mem = mem;
	return (arr);
}
