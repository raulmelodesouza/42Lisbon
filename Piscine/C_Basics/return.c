/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:08:51 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/09 12:52:57 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double cube (double num); // prototipo da funcao

int main () {
	printf ("Answer: %f\n", cube(5)); //chamamos a funcao cube e definimos o valor que sera executado na funcao
	return 0;
}

double cube (double num) { // A funcao recebe o valor do caller em main, ou seja, 5
	return num * num * num; // Aqui sera executado  5 * 5 * 5 e o valor da multiplicacao sera retornado
}
