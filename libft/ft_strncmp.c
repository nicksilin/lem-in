/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:24:22 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/24 11:47:32 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	if (!n)
		return (0);
	i = 0;
	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	while (cmp1[i] == cmp2[i] && cmp1[i] && cmp2[i] && i + 1 < n)
		i++;
	return (cmp1[i] - cmp2[i]);
}
