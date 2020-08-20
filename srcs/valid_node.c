/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:15:53 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/12 11:48:33 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		is_ant(t_buff *buff, t_farm *farm)
{
	size_t		len;
	int			n;

	if (!buff || !farm || !buff->data || buff->i > buff->size
	|| !buff->data[buff->i])
		return (0);
	len = (size_t)is_number(buff);
	n = (len) ? ft_atoi(&buff->data[buff->i]) : -1;
	if (!buff->data[buff->i + len] && n > 0)
	{
		farm->ant = n;
		buff->i += len + 1;
		return (1);
	}
	return (0);
}

static int		check_node_name(t_buff *buff)
{
	char		*str;
	size_t		i;

	if (!buff || !buff->data || buff->i > buff->size || !buff->data[buff->i])
		return (0);
	str = buff->data;
	i = buff->i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	if (str[buff->i] == 'L' || buff->i == i || str[i] == '\0')
		return (0);
	buff->i = i;
	if (!(i = is_number(buff)))
		return (0);
	buff->i += i;
	if (!(i = is_number(buff)))
		return (0);
	buff->i += i;
	if (!str[buff->i])
	{
		buff->i++;
		return (1);
	}
	return (0);
}

static int		check_start_end(t_buff *buff, t_farm *farm, t_node ***node)
{
	int			gnl_result;
	size_t		i;

	if (!buff || !buff->data || buff->i > buff->size || !buff->data[buff->i]
	|| !farm)
		return (0);
	if (!ft_strcmp(&buff->data[buff->i], "##end")
	|| !ft_strcmp(&buff->data[buff->i], "##start"))
	{
		*node = (buff->data[buff->i + 2] == 'e') ? &farm->end : &farm->start;
		if (**node)
			return (0);
		buff->i += (buff->data[buff->i + 2] == 'e') ? 6 : 8;
		i = buff->i;
		while (((gnl_result = gnl_buff(buff)) || buff->i < buff->size)
		&& is_comment(buff))
		{
			if (gnl_result < 0)
				return (0);
			ft_putendl(&buff->data[i]);
			i = buff->i;
		}
		ft_putendl(&buff->data[buff->i]);
	}
	return (1);
}

static int		check_node(t_buff *buff, t_arr *name, t_farm *farm)
{
	t_node		**special_node;
	size_t		i;
	int			result;

	if (!buff || !buff->data || buff->i > buff->size || !buff->data[buff->i]
	|| !name || !farm)
		return (0);
	special_node = NULL;
	if (!check_start_end(buff, farm, &special_node))
		return (0);
	i = buff->i;
	(result = check_node_name(buff)) ? add_arr(name, (void *)i) : 0;
	if (special_node)
		*special_node = (t_node *)i;
	return (result);
}

int				is_node(t_buff *buff, t_arr *name, t_farm *farm)
{
	if (!buff || !name || !farm)
		return (0);
	if (is_comment(buff))
		return (1);
	if (farm->ant < 0)
		return (is_ant(buff, farm));
	if (farm->node == NULL)
		return (check_node(buff, name, farm));
	return (0);
}
