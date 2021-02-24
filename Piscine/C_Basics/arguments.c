/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:53:04 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/09 12:59:25 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

float	funcao (int, float);

int main (void)
{
	int i;
	i = funcao (10, 0.5);
	printf ("Valor de I depois de executada a funcao eh %d\n", i);
	return (0);
}

float funcao (int a, float b)
{
	printf ("Vc acaba de entrar na funcao\n");
	return (a * b);

}

