/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_node_names.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:52:28 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/12 11:30:34 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_repeat(t_arr *name)
{
	size_t		i;

	if (!name || !name->data)
		return (0);
	i = 0;
	while (i < name->size - 1)
	{
		if (!ft_strcmp(name->data[i], name->data[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static void		update_name(t_buff *buff, t_arr *name)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < name->size)
	{
		name->data[i] = &buff->data[(size_t)name->data[i]];
		j = 0;
		while (((char *)name->data[i])[j] != ' ')
			j++;
		((char *)name->data[i])[j] = '\0';
		i++;
	}
}

int				valid_names(t_buff *buff, t_arr *name, t_farm *farm)
{
	void		**array_buff;

	if (!buff || !farm || !name || !farm->start || !farm->end || !buff->data)
		return (-1);
	farm->start = (t_node *)&buff->data[(size_t)farm->start];
	farm->end = (t_node *)&buff->data[(size_t)farm->end];
	update_name(buff, name);
	if (!(array_buff = (void **)malloc(sizeof(void *) * name->size)))
		return (-1);
	merge_sort(name->data, array_buff, 0, name->size - 1);
	free(array_buff);
	farm->n_node = name->size;
	farm->node = create_node_array(name->size, name);
	if (!valid_coordinates(farm))
		return (0);
	farm->start = find_node((char *)farm->start, farm);
	farm->end = find_node((char *)farm->end, farm);
	return (check_repeat(name));
}
