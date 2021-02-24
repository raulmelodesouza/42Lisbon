/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:25:24 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/20 10:11:56 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int fatorial;
	int count;

	fatorial = 1;
	count = 1;
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	while (count <= nb)
	{
		fatorial = fatorial * count;
		count++;
	}
	return (fatorial);
}
