/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:45:37 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/20 17:05:41 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	t_list	*tail;
	void	*mapped;

	head = NULL;
	tail = NULL;
	while (lst)
	{
		mapped = (*f)(lst->content);
		new = ft_lstnew(mapped);
		if (!new)
		{
			if (mapped)
				(*del)(mapped);
			return (ft_lstclear(&head, del), NULL);
		}
		if (!head)
			head = new;
		else
			tail->next = new;
		tail = new;
		lst = lst->next;
	}
	return (head);
}
