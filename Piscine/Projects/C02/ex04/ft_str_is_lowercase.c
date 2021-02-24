/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:42:23 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/14 16:43:43 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int		count;
	char	var;

	count = 0;
	if (!str)
	{
		return (1);
	}
	while (str[count] != '\0')
	{
		var = str[count];
		if (!(var >= 'a' && var <= 'z'))
		{
			return (0);
		}
		count++;
	}
	return (1);
}
