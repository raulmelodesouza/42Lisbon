/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:30:49 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/21 17:44:31 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_length(char *str)
{
	int	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*buff;

	buff = (char*)malloc(sizeof(*src) * str_length(src) + 1);
	if (!buff)
		return (0);
	dest = buff;
	while (*src)
		*buff++ = *src++;
	*buff = '\0';
	return (dest);
}
