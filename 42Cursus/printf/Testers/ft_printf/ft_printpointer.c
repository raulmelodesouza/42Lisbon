/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:39:41 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/18 12:39:43 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_number_len_long(unsigned long int number, int base_size)
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

void		ft_printpointer(va_list ap, t_flags *flags)
{
	unsigned long int	address;
	int					len;
	int					space;
	int					precision;

	address = va_arg(ap, unsigned long int);
	len = ft_number_len_long(address, 16);
	precision = flags->precision > len ? flags->precision - len : 0;
	len = !address && flags->dot && !flags->precision ? 2 : len + 2;
	space = flags->width > len ? flags->width - len : 0;
	flags->ret += len + space + precision;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	write(1, "0x", 2);
	while (precision-- > 0)
		ft_putchar_fd('0', 1);
	if (len > 2)
		ft_putnbr_base_long_fd(address, HEX_LOWER, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);

}
