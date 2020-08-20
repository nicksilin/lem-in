/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:32:47 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/08 12:32:47 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			gnl_buff(t_buff *buff)
{
	char	*end_line;
	int		read_byte;

	if (!buff || !buff->data)
		return (-1);
	if (buff->size + READ_SIZE > buff->mem)
		if (!resize_buff(buff, max(buff->mem * 2, buff->size + READ_SIZE)))
			return (-1);
	if ((end_line = ft_strchr(buff->data + buff->i, '\n')))
	{
		*end_line = '\0';
		return (1);
	}
	if ((read_byte = read(FD_INPUT, buff->data + buff->size, READ_SIZE)) > 0)
	{
		buff->size += read_byte;
		buff->data[buff->size] = '\0';
		return (gnl_buff(buff));
	}
	if (buff->data[buff->size] != '\0')
	{
		buff->data[buff->size] = '\0';
		return (1);
	}
	return (read_byte);
}
