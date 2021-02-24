/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:34:12 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/21 17:45:13 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	*buff;

	if (min >= max)
		return (0);
	range = (int*)malloc(sizeof(min) * (max - min));
	buff = range;
	while (min < max)
		*buff++ = min++;
	return (range);
}
