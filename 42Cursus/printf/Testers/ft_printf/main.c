/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:15:57 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/23 12:15:59 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>
#include "libft/libft.h"

int main()
{
	int original, mine;

	printf ("-------------------------------------\nOriginal Printf\n");
	original = printf("<%p> <%p>\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("r: %d\n", original);
	original = printf("<%p> <%p>\n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("r: %d\n", original);
	original = printf("<%p> <%p>\n", (void *)LLONG_MIN, (void *)LLONG_MAX);
	printf("r: %d\n", original);


	printf ("-------------------------------------\nMy Printf\n");
	mine = ft_printf("<%p> <%p>\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("r: %d\n", mine);
	mine = ft_printf("<%p> <%p>\n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
    printf("r: %d\n", mine);
    mine = ft_printf("<%p> <%p>\n", (void *)LLONG_MIN, (void *)LLONG_MAX);
    printf("r: %d\n", mine);
    return 0;
}
