/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:52:58 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/09 11:16:51 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void function (void); // Aqui declaramos o prototipo

int main (void) {
	function ();
	return (0);
}
/*
void function (void){ // Aqui definimos a funcao real
	printf ("Testando uma funcao prototipo\n");
}*/
