/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:14:38 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/10 19:14:39 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	while (n--)
		if (*(t_byte *)ptr1++ != *(t_byte *)ptr2++)
			return (*(t_byte *)--ptr1 - *(t_byte *)--ptr2);
	return (0);
}
