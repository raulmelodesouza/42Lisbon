/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:16:47 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/19 13:55:23 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_aux_space(int c)
{
	if ((c == ' ' || c == '\t' || c == '\n'
				|| c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base, int base_len)
{
	int i;
	int j;

	i = 0;
	while (i < base_len)
	{
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int base_len;
	int res;

	res = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	if (ft_check_base(base, base_len))
		return (0);
	while (ft_aux_space(*str))
		str++;
	while (ft_find_base(*str, base) < base_len)
	{
		res = res * base_len - ft_find_base(*str++, base);
	}
	return (-res);
}
