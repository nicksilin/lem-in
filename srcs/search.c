/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:01:13 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/08 14:01:13 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_node			*find_node(char *name, t_farm *farm)
{
	size_t		left_;
	size_t		right;
	size_t		mid;
	int			result;

	if (!name || !farm || !farm->node)
		return (NULL);
	left_ = 0;
	right = farm->n_node - 1;
	mid = (left_ + right) / 2;
	while ((result = ft_strcmp(name, farm->node[mid]->name)))
	{
		if (left_ >= right || (!mid && result < 0))
			return (NULL);
		left_ = (result > 0) ? mid + 1 : left_;
		right = (result < 0) ? mid - 1 : right;
		mid = (left_ + right) / 2;
	}
	return (farm->node[mid]);
}
