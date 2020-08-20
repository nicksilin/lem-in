/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:59:25 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/12 11:25:06 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	merge(void **array, void **buff, size_t left, size_t right)
{
	size_t	mid;
	size_t	i_left;
	size_t	i_right;
	size_t	i;

	mid = (left + right) / 2;
	i_left = left;
	i_right = mid + 1;
	i = left;
	while (i_left <= mid || i_right <= right)
	{
		if (i_left > mid || i_right > right)
			buff[i++] = i_left > mid ? array[i_right++] : array[i_left++];
		else if (ft_strcmp(array[i_left], array[i_right]) < 0)
			buff[i++] = array[i_left++];
		else
			buff[i++] = array[i_right++];
	}
	i = left;
	while (i <= right)
	{
		array[i] = buff[i];
		i++;
	}
}

void		merge_sort(void **array, void **buff, size_t left, size_t right)
{
	size_t	mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_sort(array, buff, left, mid);
	merge_sort(array, buff, mid + 1, right);
	merge(array, buff, left, right);
}

static int	cmp_xy(t_coordinates *coordinates, size_t i_left, size_t i_right)
{
	return (coordinates[i_left].x > coordinates[i_right].x ? 1 : -1);
}

static void	merge_xy(t_coordinates *array, t_coordinates *buff, size_t left,
			size_t right)
{
	size_t	mid;
	size_t	i_left;
	size_t	i_right;
	size_t	i;

	mid = (left + right) / 2;
	i_left = left;
	i_right = mid + 1;
	i = left;
	while (i_left <= mid || i_right <= right)
	{
		if (i_left > mid || i_right > right)
			buff[i++] = i_left > mid ? array[i_right++] : array[i_left++];
		else if (cmp_xy(array, i_left, i_right) < 0)
			buff[i++] = array[i_left++];
		else
			buff[i++] = array[i_right++];
	}
	i = left;
	while (i <= right)
	{
		array[i] = buff[i];
		i++;
	}
}

void		merge_sort_xy(t_coordinates *array, t_coordinates *buff,
			size_t left, size_t right)
{
	size_t	mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_sort_xy(array, buff, left, mid);
	merge_sort_xy(array, buff, mid + 1, right);
	merge_xy(array, buff, left, right);
}
