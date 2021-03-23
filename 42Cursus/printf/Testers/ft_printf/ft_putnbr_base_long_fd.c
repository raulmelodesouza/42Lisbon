/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_long_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 13:00:16 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/18 13:02:21 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_long_fd(unsigned long int n, char *base, int fd)
{
	size_t	size_base;

	size_base = ft_strlen(base);
	if (n / size_base > 0)
		ft_putnbr_base_long_fd(n / size_base, base, fd);
	ft_putchar_fd(base[n % size_base], fd);
}
