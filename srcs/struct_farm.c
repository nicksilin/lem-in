/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 09:59:26 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/09 07:30:19 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			delete_farm(t_farm **farm)
{
	if (!farm || !*farm)
		return ;
	if ((*farm)->node)
		delete_node_array(&(*farm)->node, (*farm)->n_node);
	free(*farm);
	*farm = NULL;
}

t_farm			*create_farm(void)
{
	t_farm		*farm;

	if (!(farm = (t_farm *)malloc(sizeof(t_farm))))
		return (NULL);
	farm->ant = -1;
	farm->node = NULL;
	farm->start = NULL;
	farm->end = NULL;
	farm->n_node = -1;
	return (farm);
}
