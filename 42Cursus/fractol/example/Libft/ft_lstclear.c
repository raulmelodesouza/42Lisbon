/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:14:57 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/10 19:14:59 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		prev = current;
		current = current->next;
		del(prev->content);
		free((void *)prev);
	}
	*lst = NULL;
}
