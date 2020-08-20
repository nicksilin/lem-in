/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_ft_strcpy_no_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/02/20 13:56:46 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

char			*ft_strcpy_no_spaces(char *dst, const char *src, int i)
{
	int	j;

	j = 0;
	while (src[i] == ' ')
		i++;
	while (src[i] != ' ' && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
