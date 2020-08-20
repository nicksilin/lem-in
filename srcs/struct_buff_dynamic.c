/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_dynamic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 11:36:15 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/08 11:50:26 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			copy_buff_line(t_buff *from, t_buff *to)
{
	while (to->size + from->i < from->size)
	{
		to->data[to->size] = from->data[to->size + from->i];
		if (!to->data[to->size])
			to->data[to->size] = '\n';
		to->size++;
	}
	to->data[to->size] = '\0';
}

static void		copy_buff(char *to, const char *from, size_t size)
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
	to[i] = '\0';
}

int				resize_buff(t_buff *buff, size_t new_size)
{
	char		*new_data;

	if (!(new_data = (char *)malloc(sizeof(char) * (new_size + 1))))
		return (0);
	copy_buff(new_data, buff->data, buff->size);
	free(buff->data);
	buff->data = NULL;
	buff->data = new_data;
	buff->mem = new_size;
	return (1);
}

void			delete_buff(t_buff **buff)
{
	if (!buff || !*buff)
		return ;
	if ((*buff)->data)
		free((*buff)->data);
	(*buff)->data = NULL;
	free(*buff);
	*buff = NULL;
}

t_buff			*create_buff(size_t mem)
{
	t_buff		*buff;
	size_t		i;

	if (!(buff = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	if (!(buff->data = (char *)malloc(sizeof(char) * (mem + 1))))
	{
		free(buff);
		return (NULL);
	}
	buff->i = 0;
	buff->size = 0;
	buff->mem = mem;
	i = 0;
	while (i <= mem)
		buff->data[i++] = '\0';
	return (buff);
}
