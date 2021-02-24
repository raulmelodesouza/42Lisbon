/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:16:15 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/18 15:08:57 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int count;
	unsigned int lenght;

	count = 0;
	lenght = 0;
	while (dest[lenght])
		lenght++;
	while (count < nb && src[count])
	{
		dest[lenght] = src[count];
		lenght++;
		count++;
	}
	dest[lenght] = '\0';
	return (dest);
}
