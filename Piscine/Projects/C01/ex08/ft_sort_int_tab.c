/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:11:27 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/13 11:43:34 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int a;
	int b;
	int temp;

	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size)
		{
			if (tab[b] >= tab[a])
			{
				temp = tab[b];
				tab[b] = tab[a];
				tab[a] = temp;
			}
			b++;
		}
		a++;
	}
}
