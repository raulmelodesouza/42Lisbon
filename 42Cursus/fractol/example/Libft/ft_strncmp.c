/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:12:22 by jfigueir          #+#    #+#             */
/*   Updated: 2021/05/24 18:23:59 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*(t_byte *)s1 == *(t_byte *)s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return (0);
	return (*(t_byte *)s1 - *(t_byte *)s2);
}
