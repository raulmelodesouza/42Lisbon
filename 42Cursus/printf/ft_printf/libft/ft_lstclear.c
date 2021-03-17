/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:04:52 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/02/18 13:04:55 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur;
	t_list *nxt;

	if (lst && *lst && del)
	{
		cur = *lst;
		while (cur)
		{
			nxt = cur->next;
			ft_lstdelone(cur, del);
			cur = nxt;
		}
		*lst = NULL;
	}
}
