/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h 		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:52:02 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/05 12:08:53 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct
{
	int			index;
	int			zero;
	int			minus;
	int			width;
	int			precision;
	int			dot;
	int			negative;
	int			ret;
}				t_flags;

int				ft_printf(const char *format, ...);

#endif