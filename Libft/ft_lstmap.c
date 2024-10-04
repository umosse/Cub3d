/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:59:23 by umosse            #+#    #+#             */
/*   Updated: 2023/11/22 16:12:03 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*stock;
	t_list	*newlst;

	if (lst == 0 || f == 0)
		return (NULL);
	current = lst;
	newlst = 0;
	while (current)
	{
		stock = ft_lstnew(f(current->content));
		if (!stock)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, stock);
		current = current->next;
	}
	return (newlst);
}
