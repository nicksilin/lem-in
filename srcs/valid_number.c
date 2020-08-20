/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valin_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:43:43 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/08 13:47:19 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		is_int(char *str)
{
	size_t		prefix;
	size_t		zero;
	size_t		nbr;
	int			cmp;

	if (!str)
		return (0);
	prefix = str[0] == '-' || str[0] == '+' ? 1 : 0;
	zero = 0;
	while (str[prefix + zero] && str[prefix + zero] == '0')
		zero++;
	nbr = 0;
	while (ft_isdigit(str[prefix + zero + nbr]) && nbr <= 10)
		nbr++;
	if ((!nbr && !zero) || nbr > 10)
		return (0);
	if (nbr == 10)
	{
		cmp = ft_strncmp(INT_LIMIT, &str[prefix + zero], 10);
		if ((str[0] == '-' && cmp < 0) || (str[0] != '-' && cmp <= 0))
			return (0);
	}
	return ((int)(prefix + zero + nbr));
}

int				is_number(t_buff *buff)
{
	size_t		i;
	int			nbr_len;

	if (!buff || !buff->data || buff->i > buff->size)
		return (0);
	i = 0;
	while (buff->i <= buff->size && buff->data[buff->i + i]
	&& (buff->data[buff->i + i] == ' ' || buff->data[buff->i + i] == '\t'))
		i++;
	if (buff->i > buff->size)
		return (0);
	if ((nbr_len = is_int(&buff->data[buff->i + i])))
		return ((int)i + nbr_len);
	return (0);
}
