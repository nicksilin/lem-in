/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:11:10 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/08 12:11:10 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

size_t			max(size_t nbr1, size_t nbr2)
{
	return (nbr1 > nbr2 ? nbr1 : nbr2);
}

size_t			min(size_t nbr1, size_t nbr2)
{
	return (nbr1 < nbr2 ? nbr1 : nbr2);
}
