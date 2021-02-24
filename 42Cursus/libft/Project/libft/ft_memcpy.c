/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:52:05 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/02/16 13:33:49 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t i;

	if (s1 == 0)
		return (NULL);
	if (s1 == s2)
		return (s1);
	if (s1 == NULL && s2 == NULL)
		return (s1);
	i = 0;
	while (i < n)
	{
		((char*)s1)[i] = ((char*)s2)[i];
		i++;
	}
	return (s1);
}
