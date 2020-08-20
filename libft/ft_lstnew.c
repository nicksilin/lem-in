/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:04:45 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/22 16:09:25 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if (!(lst->content = (void *)ft_memalloc(sizeof(content)
			* content_size)))
		{
			free(lst);
			return (NULL);
		}
		else
		{
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
	}
	lst->next = NULL;
	return (lst);
}
