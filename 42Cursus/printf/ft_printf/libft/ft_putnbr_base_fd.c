/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:26:01 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/17 13:26:02 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	unsigned values
*/

void	ft_putnbr_base_fd(unsigned int n, char *base, int fd)
{
	size_t	size_base;

	size_base = ft_strlen(base);
	if (n / size_base > 0)
		ft_putnbr_base_fd(n / size_base, base, fd);
	ft_putchar_fd(base[n % size_base], fd);
}
