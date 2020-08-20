/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:31:49 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/10 14:42:33 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				is_comment(t_buff *buff)
{
	if (!buff || !buff->data || buff->i > buff->size || !buff->data[buff->i])
		return (0);
	if (buff->data[buff->i] == '#')
	{
		if ((!ft_strcmp(&buff->data[buff->i + 1], "#start"))
			|| (!ft_strcmp(&buff->data[buff->i + 1], "#end")))
			return (0);
		buff->i += ft_strlen(buff->data + buff->i) + 1;
		return (1);
	}
	return (0);
}

int				valid_nodes(t_buff *buff, t_arr *name, t_farm *farm)
{
	int		gnl_result;

	if (!buff || !name || !farm)
		return (0);
	while ((gnl_result = gnl_buff(buff) || buff->i < buff->size))
	{
		if (gnl_result < 0)
			return (0);
		else
		{
			ft_putendl(&buff->data[buff->i]);
			if (!is_node(buff, name, farm))
				break ;
		}
	}
	if (valid_names(buff, name, farm) < 1)
		return (0);
	return (1);
}

int				valid_map(t_buff *buff, t_farm *farm)
{
	t_arr		*name;
	t_buff		*buff_line;
	int			result;

	if (!buff || !farm)
		return (0);
	if (!(name = create_arr(1)))
		return (0);
	if (!valid_nodes(buff, name, farm))
	{
		delete_arr(&name);
		return (0);
	}
	delete_arr(&name);
	if (!(buff_line = create_buff(max(BUFF_MEMORY, buff->size - buff->i))))
		return (0);
	copy_buff_line(buff, buff_line);
	result = valid_line(buff_line, farm);
	delete_buff(&buff_line);
	return (result);
}
