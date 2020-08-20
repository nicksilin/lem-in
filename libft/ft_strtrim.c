/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:57:37 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/20 12:53:08 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	len;

	if ((!s))
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	if ((!len))
	{
		str = ft_strnew(1);
		return (str);
	}
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		len--;
		start++;
	}
	str = ft_strsub(s, start, len);
	return (str);
}
