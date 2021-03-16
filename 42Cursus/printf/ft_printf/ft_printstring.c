/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:31:22 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/16 13:31:32 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printstring(va_list ap, t_flags *flags)
{
	char	*str;
	int		len;
	int		space;
	int		zero;

	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	if (flags->precision > 0 && flags->precision < (int)ft_strlen(str))
		len = flags->precision;
	else
		len = (flags->dot && !flags->precision) ? 0 : ft_strlen(str);
	zero = flags->width > len && flags->zero ? flags->width - len : 0;
	space = flags->width > len && !zero ? flags->width - len : 0;
	flags->ret += len + space + zero;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	while (len--)
		ft_putchar_fd(*str++, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
