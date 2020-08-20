/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_dynamic_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:49:08 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/11 11:51:51 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

t_array		*create(unsigned size)
{
	t_array		*new_array;

	if (!(new_array = (t_array *)malloc(sizeof(t_array))))
		return (NULL);
	new_array->id = 0;
	new_array->size = size;
	if (!(new_array->data = (int *)malloc(sizeof(int) * size)))
	{
		free(new_array);
		return (NULL);
	}
	return (new_array);
}

int			add(t_array *array, int data)
{
	if (!array)
		return (0);
	if (array->id == array->size)
	{
		if (!resize(array, (array->size) * 2))
			return (0);
	}
	array->data[array->id++] = data;
	return (1);
}

int			del(t_array *array, int *data)
{
	if (!array || (int)array->id == -1)
		return (0);
	if (data)
		*data = array->data[array->id];
	array->id--;
	if (array->id * 2 < array->size)
		return (resize(array, array->size / 2));
	return (1);
}

void		ft_copy(int *to, const int *from, unsigned size)
{
	unsigned	i;

	if (!to || !from)
		return ;
	i = 0;
	while (i < size)
	{
		to[i] = from[i];
		i++;
	}
}

int			resize(t_array *array, unsigned new_size)
{
	int			*buff;

	if (!(buff = (int *)malloc(sizeof(int) * array->size)))
		return (0);
	ft_copy(buff, array->data, array->id);
	free(array->data);
	if (!(array->data = (int *)malloc(sizeof(int) * new_size)))
	{
		free(buff);
		return (0);
	}
	ft_copy(array->data, buff, array->id);
	free(buff);
	array->size = new_size;
	return (1);
}
