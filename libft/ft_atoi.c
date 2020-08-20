/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:01:12 by fwiley            #+#    #+#             */
/*   Updated: 2019/12/20 12:30:47 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		i;
	long int	result;
	int			minus;

	if (!ft_strlen(str))
		return (0);
	result = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((result = result * 10 + str[i++] - '0') < 0)
		{
			if (minus == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)result * minus);
}
