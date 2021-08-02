/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:23:16 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/14 13:23:18 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*reg;
	t_list	*current;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	current = lst;
	while (current)
	{
		reg = ft_lstnew(f(current->content));
		if (!reg)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, reg);
		current = current->next;
	}
	return (new_lst);
}
