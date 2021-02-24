/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:07:55 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/13 13:20:26 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int count;

	count = 0;
	size = size - 1;
	while (count < size)
	{
		temp = tab[count];
		tab[count] = tab[size];
		tab[size] = temp;
		count++;
		size--;
	}
}
