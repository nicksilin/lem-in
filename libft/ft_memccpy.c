/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:32:25 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/22 16:59:23 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		if (dstcpy[i] == (unsigned char)c)
			return (&dstcpy[i + 1]);
		i++;
	}
	return (NULL);
}
