/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:41:19 by fwiley            #+#    #+#             */
/*   Updated: 2020/01/26 12:34:15 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first_lst;
	t_list	*present_lst;
	t_list	*past_lst;

	if (!lst || !f)
		return (NULL);
	if (!(first_lst = f(lst)))
		return (NULL);
	lst = lst->next;
	past_lst = first_lst;
	while (lst)
	{
		if (!(present_lst = f(lst)))
		{
			ft_lstdel(&first_lst, &ft_del);
			return (NULL);
		}
		lst = lst->next;
		past_lst->next = present_lst;
		past_lst = past_lst->next;
	}
	return (first_lst);
}
