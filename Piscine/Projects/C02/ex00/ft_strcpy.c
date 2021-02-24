/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:20:09 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/14 16:24:19 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int count;

	count = 0;
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	src[count] = '\0';
	return (dest);
}
