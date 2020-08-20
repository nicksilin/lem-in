/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:38:09 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/24 11:22:11 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return (char*)(s + i);
	while (s[i - 1] && i)
	{
		if (s[i - 1] == c)
			return (char*)(s + i - 1);
		i--;
	}
	return (NULL);
}
