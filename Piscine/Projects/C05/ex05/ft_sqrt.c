/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:41:23 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/19 20:44:13 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int count;

	count = 0;
	while (count * count < nb)
	{
		count++;
	}
	if (count * count == nb)
	{
		return (count);
	}
	else
	{
		return (0);
	}
}
