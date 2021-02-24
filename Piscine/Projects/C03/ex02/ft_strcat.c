/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:12:04 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/18 10:15:44 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int count;
	int lenght;

	count = 0;
	lenght = 0;
	while (dest[count] != '\0')
	{
		lenght++;
		count++;
	}
	count = 0;
	while (src[count] != '\0')
	{
		dest[lenght + count] = src[count];
		count++;
	}
	dest[lenght + count] = '\0';
	return (dest);
}
