/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statictest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:58:24 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/09 14:04:43 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int staticfunction (int, int);

int main (void)
{
	int i;
	i = staticfunction (10, 5);
	printf ("Valor da funcao: %d\n", i);
	return (0);

}
