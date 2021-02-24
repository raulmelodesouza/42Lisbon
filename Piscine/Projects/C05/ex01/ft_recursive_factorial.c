/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:28:17 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/20 10:09:17 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int fatorial;

	fatorial = 1;
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else if (nb < 0 || nb > 12)
	{
		return (0);
	}
	else
	{
		fatorial = (nb * (ft_recursive_factorial(nb - 1)));
	}
	return (fatorial);
}
