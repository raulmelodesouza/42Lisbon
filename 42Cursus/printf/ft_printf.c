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
static void	ft_startflags(t_flags *flags) //Funcao apenas para iniciarlizar os tipos de dados contidos na nossa struct
{
	flags->zero = 0; // Ponteiro para Struct, apontando para o tipo int zero
	flags->minus = 0; // Ponteiro para Struct, apontando para o tipo int minus
	flags->width = 0; // Ponteiro para Struct, apontando para o tipo int width
	flags->precision = 0; // Ponteiro para Struct, apontando para o tipo int precision
	flags->dot = 0; // Ponteiro para Struct, apontando para o tipo int dor
	flags->negative = 0; // Ponteiro para Struct, apontando para o tipo int negative
}

static void	ft_conversions(const char *format, va_list argp, t_flags *flags)
{
	ft_checkflags(format, argp, flags); /* Funcao que ira receber os argumentos passados a cima e verificar o comprimento, 
	precisao e se ha algum numero depois da porcentagem, que sao normalmente os tratamentos de dados, para mostrar quantas 
	casas decimais serao passadas, ou a formatacao de exibicao da variavel, depois de identificados esses passos, iremos 
	prosseguir abaixo para a verificacao do tipo de variavel "cspdiuxX" ou se eh um caracter %  */
	if (format[flags->index] == 'c')
		ft_printchar(argp, flags); // Se o indicador for um CHAR, chamamos a funcao para printar um char
	else if (format[flags->index] == 's')
		ft_printstring(argp, flags); // Se o indicador for uma STRING, chamamos a funcao para printar uma STRING
	else if (format[flags->index] == 'p')
		ft_printpointer(argp, flags); // Se o indicador for um POINTER, chamamos a funcao para printar um POINTER
	else if (format[flags->index] == 'd' || format[flags->index] == 'i' ||
	format[flags->index] == 'u' || format[flags->index] == 'x' ||
	format[flags->index] == 'X') // Se o indicador for um INT/(Unsigned)DECIMAL/Hex(Up/lower case), chamamos a funcao para printa-los
		ft_printdiux(ap, format[flags->index], flags); // Printar os tipos d, i, u & X
	else if (format[flags->index] == '%')
		ft_printpercent(flags); // Se o indicador for uma PORCENTAGEM, chamamos a funcao para printar uma PORCENTAGEM
	else /* Caso % seha apenas o caracter e nao haja nenhum indicador de variavel a seguir, 
			escrevemos apenas % com a funcao write, retornarmos o index para a porcentagem, para recomecar a 
			leitura desde onde tinhamos parado com um --, ja que nao tem nada em frente que seja uma variavel e incrementamos o ret++ */
	{
		write(1, "%", 1);
		flags->index--;
		flags->ret++;
	}
	ft_startflags(flags); // Chamamos a funcao de startflags novamente para zera-las, nao precisamos mais desses indicadores
}


int			ft_printf(const char *format, ...) // format sera a string que iremos receber e realizar a formatacao antes de exibir
{
	va_list	argp; // Ponteiro para um argumento
	t_flags	flags; // Variavel flags do tipo flag

	flags.index = 0; // A variavel flag, do tipo t_flags, recebe um index de 0
	flags.ret = 0; // A variavel flag, do tipo t_flags, recebe um ret de 0
	ft_startflags(&flags); // Chamando a funcao para iniciar as flags todas, com o valor de zero
	va_start(argp, format); //Aqui permitimos o acesso aos argumentos de função variadic em argp e format

	while (format[flags.index]) // Enquanto nao for nulo
	{
		if (format[flags.index] == '%') /* A porcentagem geralmente eh um indicador de uma variavel e se for seguido de 
		cspdiuxX devera indicar o respectivo valor da variavel, por isso precisamos identificar se eh uma porcentagem caracter 
		literal ou entao se eh um indicador de variavel */
			ft_conversions(format, argp, &flags); /* Aqui chamamos uma funcao auxiliar para fazer a verificacao, enviamos o format, 
													 o argumento para ponteiro e o endereco de nossas flags */
		else // Se nao houver porcentagem, usamos a funcao putchar_fd para continuar lendo a string recebida
		{
			ft_putchar_fd(format[flags.index], 1);
			flags.ret++; 
		}
		flags.index++;
	}
	va_end(argp); // Termina a travessia dos argumentos da função variadic
	return (flags.ret); // Vai retornar o comprimento total de caracteres exibidos por printf
}