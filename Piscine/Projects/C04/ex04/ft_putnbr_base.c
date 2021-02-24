/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:57:17 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/19 10:58:00 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

int		ft_nbrlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int		baseistrue(char *str)
{
	int count;
	int countb;

	count = 0;
	if (ft_nbrlen(str) <= 1)
		return (0);
	while (str[count])
	{
		if (!(str[count] >= 'A' && str[count] <= 'Z')
				&& !(str[count] >= 'a' && str[count] <= 'z')
				&& !(str[count] >= '0' && str[count] <= '9'))
			return (0);
		countb = count + 1;
		while (str[countb])
		{
			if (str[countb] == str[count])
				return (0);
			countb++;
		}
		count++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int aux;

	if (!baseistrue(base))
		return ;
	aux = ft_nbrlen(base);
	if (nbr <= -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base((-(long int)nbr) / aux, base);
		ft_putnbr_base((-(long int)nbr) % aux, base);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else if (nbr < aux)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		ft_putnbr_base(nbr / aux, base);
		ft_putnbr_base(nbr % aux, base);
	}
}
