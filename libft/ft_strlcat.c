/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:48:06 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/22 17:14:07 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = 0;
	while (dst[i])
	{
		i++;
		size--;
	}
	j = 0;
	while (size > 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
		size--;
	}
	dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
