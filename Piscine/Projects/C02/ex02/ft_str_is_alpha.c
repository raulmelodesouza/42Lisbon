/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:29:51 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/14 16:32:04 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		count;
	char	temp;

	count = 0;
	if (!str)
	{
		return (1);
	}
	while (str[count] != '\0')
	{
		temp = str[count];
		if (!((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')))
		{
			return (0);
		}
		count++;
	}
	return (1);
}
