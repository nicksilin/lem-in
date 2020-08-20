/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:25:52 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/12 10:25:52 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void				delete_coordinates(t_coordinates **coordinates)
{
	if (!coordinates || !*coordinates)
		return ;
	free(*coordinates);
	*coordinates = NULL;
}

t_coordinates		*create_coordinates(size_t size)
{
	t_coordinates	*coordinates;

	if (!(coordinates = (t_coordinates *)malloc(sizeof(t_coordinates) * size)))
		return (NULL);
	return (coordinates);
}
