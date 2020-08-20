/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_byte.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:52:13 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/22 15:25:09 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_byte(unsigned char oct)
{
	unsigned char	rev;
	unsigned		i;

	i = 8;
	while (i--)
	{
		rev = (rev << 1 | (oct & 1));
		oct >>= 1;
	}
	return (rev);
}
