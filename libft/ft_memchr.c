/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:29:16 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/21 19:49:17 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;
	size_t			i;

	result = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (result[i] == (unsigned char)c)
			return ((void *)(result + i));
		i++;
	}
	return (NULL);
}
