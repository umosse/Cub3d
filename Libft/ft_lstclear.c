/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:58:48 by umosse            #+#    #+#             */
/*   Updated: 2023/11/22 15:38:48 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*first;

	if (lst == 0 || del == 0)
		return ;
	current = *lst;
	first = *lst;
	while (current)
	{
		first = current->next;
		ft_lstdelone(current, del);
		current = first;
	}
	*lst = NULL;
}
