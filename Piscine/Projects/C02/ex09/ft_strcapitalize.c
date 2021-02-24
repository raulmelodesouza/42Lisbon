/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:16:35 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/14 17:20:05 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*tratamento(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 'A' && str[count] <= 'Z')
		{
			str[count] = str[count] + 32;
		}
		count++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int count;

	count = 0;
	tratamento(str);
	while (str[count] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
		{
			str[0] = str[0] - 32;
		}
		else if (str[count] == 32 || str[count] == 43 || str[count] == 45)
		{
			if (str[count + 1] >= 'a' && str[count + 1] <= 'z')
			{
				str[count + 1] = str[count + 1] - 32;
			}
		}
		count++;
	}
	return (str);
}
