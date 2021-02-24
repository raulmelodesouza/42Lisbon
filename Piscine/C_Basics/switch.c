/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:54:33 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/08 14:08:03 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main (){
	int a;
	a = 45;

	switch (a) {
		case 41:
			printf ("%d = 41\n", a);
			break;
		case 42:
			printf ("%d = 42\n", a);
			break;
		case 43:
			printf ("%d = 43\n", a);
			break;
		default: 
			printf ("%d doesn't match with any of the values\n", a);	
			break;
	}
}
