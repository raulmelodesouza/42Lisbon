/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:47:33 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/02/18 12:47:56 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (*alst && new)
	{
		ptr = *alst;
		new->next = ptr;
		*alst = new;
	}
}
