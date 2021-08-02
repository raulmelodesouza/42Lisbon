/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:16:28 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/10 19:16:29 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	if (!lst)
		return (0);
	size = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}
