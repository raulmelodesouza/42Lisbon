/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:05:02 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/02/24 12:21:53 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*buff;

	buff = (char*)malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (!buff)
		return (0);
	dest = buff;
	while (*src)
		*buff++ = *src++;
	*buff = '\0';
	return (dest);
}
