/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:36:03 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/22 15:40:55 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_lst)
{
	long int	size;
	t_list		*lst;

	lst = begin_lst;
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
