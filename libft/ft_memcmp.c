/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:07:46 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/21 19:49:58 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;
	size_t			i;

	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	i = 0;
	if (n == 0 || cmp1 == cmp2)
		return (0);
	while (cmp1[i] == cmp2[i] && i + 1 < n)
		i++;
	return (cmp1[i] - cmp2[i]);
}
