/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:40:16 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/14 16:41:58 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
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
		if (!(var >= '0' && var <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
