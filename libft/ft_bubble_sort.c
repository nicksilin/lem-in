/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:14:31 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/22 13:52:22 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	int		buf;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				buf = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buf;
			}
			j++;
		}
		i++;
	}
}
