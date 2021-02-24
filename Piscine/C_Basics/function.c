/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 10:37:58 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/09 10:50:58 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void function (){
	printf ("Testando uma funcao\n");
	printf ("Testando novamente\n");
}

int main (void) {
	function (); // Aqui estamos chamando a funcao definida acima
	function ();// Ou seja, serao exibidor os valores da funcao
	return (0);
}
