/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:52:59 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/17 12:55:36 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_setflags(t_flags *flags, unsigned int num, int len, char *base)
{
	int	zero;
	int	space;

	flags->negative ? len++ : 0;
	if (flags->dot && !flags->precision && !num)
		len = 0;
	if (flags->precision > len)
		zero = flags->precision - len;
	else
		zero = (flags->width > len && flags->zero) ? flags->width - len : 0;
	len += zero > 0 ? zero : 0;
	space = flags->width > len && !flags->zero ? flags->width - len : 0;
	flags->ret += len + space;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	flags->negative ? ft_putchar_fd('-', 1) : 0;
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
	if (len)
		ft_putnbr_base_fd(num, base, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

static int	ft_numberlen(unsigned int number, int base_size)
{
	size_t	len;

	len = 1;
	while (number / base_size > 0)
	{
		len++;
		number /= base_size;
	}
	return (len);
}

void		ft_printdiux(va_list ap, char c, t_flags *flags)
{
	int				num;
	unsigned int	unum;

	if (c == 'i' || c == 'd')
	{
		num = va_arg(ap, int);
		if (num < 0)
		{
			flags->negative = 1;
			num *= -1;
			flags->precision += flags->precision > 0 ? 1 : 0;
		}
		ft_setflags(flags, num, ft_numberlen(num, 10), DECIMAL);
	}
	else if (c == 'u' || c == 'x' || c == 'X')
	{
		unum = va_arg(ap, unsigned int);
		if (c == 'u')
			ft_setflags(flags, unum, ft_numberlen(unum, 10), DECIMAL);
		else
			c == 'x' ?
			ft_setflags(flags, unum, ft_numberlen(unum, 16), HEX_LOWER) :
			ft_setflags(flags, unum, ft_numberlen(unum, 16), HEX_UPPER);
	}
}
