/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:10:53 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/08 12:49:41 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_putchar (char letra) {
	write (1, &letra, 1); // A funcao & indica em qual espaco sera salvo o valor string da variavel char
	return (0);
}
int main (){
	ft_putchar ('@'); // Aqui definimos o valor que entrara em ft_putchar
	ft_putchar ('\n'); // Quebra de linha
	return (0);
}
