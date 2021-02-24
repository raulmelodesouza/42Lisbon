/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:25:55 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/14 17:27:17 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char a)
{
	write(1, &a, 1);
}

void	hexa(unsigned char c)
{
	put_char(92);
	put_char("0123456789abcdef"[c / 16]);
	put_char("0123456789abcdef"[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!(32 <= (*str) && (*str) <= 126))
		{
			hexa(*str);
		}
		else
		{
			write(1, str, 1);
		}
		++str;
	}
}
