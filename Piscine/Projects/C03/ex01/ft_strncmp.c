/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:50:14 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/18 15:07:24 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0'
			&& s2[count] != '\0' && count + 1 < n)
		count++;
	if (s1[count] == s2[count] || n == 0)
	{
		return (0);
	}
	return (s1[count] - s2[count]);
}
