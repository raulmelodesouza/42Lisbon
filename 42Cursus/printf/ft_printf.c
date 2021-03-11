#include "libftprintf.h"

/* Lembrete da struct
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
*/
static void	start_flags(t_flags *flags) //Funcao apenas para iniciarlizar os tipos de dados contidos na nossa struct
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->negative = 0;
	flags->dot = 0;
}

static void	ft_conversions(const char *format, va_list argp, t_flags *flags)
{
	store_flags(format, argp, flags);
	if (format[flags->index] == 'c')
		print_char(argp, flags);
	else if (format[flags->index] == 's')
		print_string(argp, flags);
	else if (format[flags->index] == 'p')
		print_pointer(argp, flags);
	else if (format[flags->index] == 'd' || format[flags->index] == 'i' ||
	format[flags->index] == 'u' || format[flags->index] == 'x' ||
	format[flags->index] == 'X')
		print_diux(ap, format[flags->index], flags); // Printar os tipos d, i, u & X
	else if (format[flags->index] == '%')
		print_percent(flags);
	else
	{
		write(1, "%", 1);
		flags->index--;
		flags->ret++;
	}
	init_flags(flags);
}


int			ft_printf(const char *format, ...)
{
	va_list	argp; // Ponteiro para um argumento
	t_flags	flags; // Variavel flags do tipo flag

	flags.index = 0;
	flags.ret = 0;
	start_flags(&flags); // Chamando a funcao para iniciar as flags todas, com o valor de zero
	va_start(argp, format); //Aqui permitimos o acesso aos argumentos de função variadic em argp e format

	while (format[flags.index]) // Enquanto nao for nulo
	{
		if (format[flags.index] == '%') // Se for um porcentagen
			ft_conversions(format, argp, &flags);
		else
		{
			ft_putchar_fd(format[flags.index], 1);
			flags.ret++;
		}
		flags.index++;
	}
	va_end(argp); // Termina a travessia dos argumentos da função variadic
	return (flags.ret);
}