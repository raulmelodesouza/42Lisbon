/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:37:31 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/02/20 14:48:32 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN_INT	-2147483648
#define MAX_INT	214783647

static int		checker(const char **str)
{
	int	is_negative;

	while (**str == ' ' || **str == '\t' || **str == '\n'
				|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	is_negative = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			is_negative = is_negative * (-1);
		(*str)++;
	}
	return (is_negative);
}

int				ft_atoi(const char *str)
{
	long		nb;
	int			i;
	int			is_negative;

	is_negative = checker(&str);
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb < 0)
			return (is_negative > 0 ? -1 : 0);
		i++;
	}
	return ((int)(is_negative < 0 ? -nb : nb));
}
