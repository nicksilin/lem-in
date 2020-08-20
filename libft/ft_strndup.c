/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:16:44 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/30 11:13:03 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t a)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * a + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, a);
	str[a] = '\0';
	return (str);
}
