/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:11:25 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/10 19:11:27 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;

	temp = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		temp = (unsigned int)(n * -1);
	}
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((char)(temp % 10 + '0'), fd);
}
