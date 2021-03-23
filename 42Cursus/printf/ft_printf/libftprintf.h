/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:23:19 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/17 12:59:02 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct	s_flags
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
void			ft_checkflags(const char *format, va_list ap, t_flags *flags);
void			ft_printchar(va_list ap, t_flags *flags);
void			ft_printpercent(t_flags *flags);
void			ft_printstring(va_list ap, t_flags *flags);
void			ft_printdiux(va_list ap, char c, t_flags *flags);
void			ft_printpointer(va_list ap, t_flags *flags);

#endif
