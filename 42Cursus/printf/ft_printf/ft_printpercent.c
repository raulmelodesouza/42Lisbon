/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:29:25 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/16 13:31:17 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printpercent(t_flags *flags)
{
	int	space;
	int	zero;

	zero = flags->width > 1 && flags->zero ? flags->width - 1 : 0;
	space = flags->width > 1 && !zero ? flags->width - 1 : 0;
	flags->ret += 1 + zero + space;
	if (!flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}
