/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifelse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:21:04 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/08 13:33:12 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main (void){
	int a, valor; 
	a = 0;
	valor = 40;

	if (a > valor) {  
		printf ("%d eh maior que %d\n", a, valor);
		
	}
	else if (a == valor) {
		printf ("Valor %d igual a %d\n", a, valor);
	}
	else if (a < valor) {
		printf ("Valor %d menor que %d\n", a, valor);
	}

}
