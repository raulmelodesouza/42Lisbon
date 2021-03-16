/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:27:51 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/16 13:29:20 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printchar(va_list ap, t_flags *flags)
{
	char	c;
	int		space;

	c = va_arg(ap, int);
	space = flags->width > 1 ? flags->width - 1 : 0;
	flags->ret += 1 + space;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
