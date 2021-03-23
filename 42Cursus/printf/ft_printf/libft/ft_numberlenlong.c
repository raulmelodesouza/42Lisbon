/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlenlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:54:09 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/23 11:54:12 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numberlenlong(unsigned long int number, int base_size)
{
	unsigned int	len;

	len = 1;
	while (number / base_size > 0)
	{
		len++;
		number /= base_size;
	}
	return (len);
}
