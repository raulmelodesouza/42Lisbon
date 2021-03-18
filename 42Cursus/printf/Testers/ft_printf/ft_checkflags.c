/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:26:06 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/16 13:27:45 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_getnumber(const char *format, int *index)
{
	int	type_flag;

	type_flag = 0;
	while (ft_isdigit(format[*index]))
	{
		type_flag = type_flag * 10 + format[*index] - '0';
		(*index)++;
	}
	return (type_flag);
}

static void	ft_zero_minus(const char *format, t_flags *flags)
{
	while (format[flags->index] == '-' || format[flags->index] == '0')
	{
		flags->minus = format[flags->index] == '-' ? 1 : flags->minus;
		flags->zero = (format[flags->index] == '0' && !flags->minus) ? 1 : 0;
		flags->index++;
	}
}

static void	ft_width(const char *format, va_list ap, t_flags *flags)
{
	if (format[flags->index] == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width *= -1;
		}
		flags->index++;
	}
	else
		flags->width = ft_getnumber(format, &flags->index);
}

static void	ft_precision(const char *format, va_list ap, t_flags *flags)
{
	flags->dot = 1;
	flags->index++;
	if (format[flags->index] == '*')
	{
		flags->precision = va_arg(ap, int);
		flags->zero = flags->precision >= 0 ? 0 : flags->zero;
		flags->index++;
	}
	else
	{
		if (ft_isdigit(format[flags->index]))
			flags->zero = 0;
		flags->precision = ft_getnumber(format, &flags->index);
	}
}

void		ft_checkflags(const char *format, va_list ap, t_flags *flags)
{
	flags->index++;
	if (format[flags->index] == '-' || format[flags->index] == '0')
		ft_zero_minus(format, flags);
	ft_width(format, ap, flags);
	if (format[flags->index] == '.')
		ft_precision(format, ap, flags);
}
