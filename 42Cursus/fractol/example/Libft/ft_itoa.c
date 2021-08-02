/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:10:43 by jfigueir          #+#    #+#             */
/*   Updated: 2021/05/24 18:31:00 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_num_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (ft_power(10, i) <= (t_u64)n)
		i++;
	return (i);
}

static void	fill_str(char *str, int num, int num_len, int is_negative)
{
	t_uint	i;
	t_uint	remainder;

	i = 0;
	while (num)
	{
		remainder = num % 10;
		num /= 10;
		str[is_negative + num_len - i - 1] = remainder + '0';
		i++;
	}
	if (is_negative)
		str[0] = '-';
	str[is_negative + num_len] = '\0';
}

char	*ft_itoa(int n)
{
	int		num_len;
	int		is_negative;
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	else
		is_negative = 0;
	num_len = get_num_len(n);
	ret = malloc(is_negative + num_len + 1);
	if (!ret)
		return (0);
	fill_str(ret, n, num_len, is_negative);
	return (ret);
}
