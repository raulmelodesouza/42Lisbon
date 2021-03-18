/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:20:21 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/18 12:41:23 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_startflags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->dot = 0;
	flags->negative = 0;
}

static void		ft_conversions(const char *format, va_list argp, t_flags *flags)
{
	ft_checkflags(format, argp, flags);
	if (format[flags->index] == 'c')
		ft_printchar(argp, flags);
	else if (format[flags->index] == 's')
		ft_printstring(argp, flags);
	else if (format[flags->index] == 'p')
		ft_printpointer(argp, flags);
	else if (format[flags->index] == 'd' || format[flags->index] == 'i' ||
	format[flags->index] == 'u' || format[flags->index] == 'x' ||
	format[flags->index] == 'X')
		ft_printdiux(argp, format[flags->index], flags);
	else if (format[flags->index] == '%')
		ft_printpercent(flags);
	else
	{
		write(1, "%", 1);
		flags->index--;
		flags->ret++;
	}
	ft_startflags(flags);
}

int				ft_printf(const char *format, ...)
{
	va_list	argp;
	t_flags	flags;

	flags.index = 0;
	flags.ret = 0;
	ft_startflags(&flags);
	va_start(argp, format);
	while (format[flags.index])
	{
		if (format[flags.index] == '%')
			ft_conversions(format, argp, &flags);
		else
		{
			ft_putchar_fd(format[flags.index], 1);
			flags.ret++;
		}
		flags.index++;
	}
	va_end(argp);
	return (flags.ret);
}
