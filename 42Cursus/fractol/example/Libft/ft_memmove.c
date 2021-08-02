/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:09:34 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/10 19:09:36 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*reg;
	char	*dst;

	reg = (char *)src;
	dst = (char *)dest;
	if (reg < dst)
	{
		while (n--)
			dst[n] = reg[n];
	}
	else
		ft_memcpy(dst, reg, n);
	return (dest);
}
