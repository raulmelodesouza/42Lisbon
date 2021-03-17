X------------------APLICACAO DOS CONCEITOS PARA REPLICAR O PRINTF------------------X

-----------> ft_printf <-----------

#include "libftprintf.h"

/* Lembrete da struct que
  sera criada na libftprintf.h
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
	flags->width = 0; /* Ponteiro para Struct, apontando para o tipo int width 
						 Número mínimo de caracteres a serem impressos. Se o valor a ser impresso for menor que esse número, 
						 o resultado será preenchido com espaços em branco. */
	flags->precision = 0; /* Ponteiro para Struct, apontando para o tipo int precision 
							 Para especificadores inteiros (d, i, o, u, x, X): a precisão especifica o número mínimo de dígitos a 
							 serem escritos. Se o valor a ser escrito for menor que esse número, o resultado será preenchido com 
							 zeros à esquerda. */
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

 -----------> ft_checkflags <-----------


 /*Ordem de execucao da funcao

ft_checkflags -> ft_zero_minus -> [ft_width ( -> ft_getnumber -> ft_isdigit)] -> [ft_precision (ft_getnumber -> ft_isdigit)]
 */

#include "libftprintf.h"

static int	ft_getnumber(const char *format, int *index)
{
	int	type_flag;

	type_flag = 0;
	while (ft_isdigit(format[*index])) 
	// Aqui usaremos a funcao ft_isdigit do nosso LIBFT, para verificar se os caracteres realmente sao digitos
	{
		type_flag = type_flag * 10 + format[*index] - '0';
		/*Nossa variavel iniciada com zero recebe o valor de zero e depois atribuimos ela mesma multiplicada por 10 e somada
		ao numero da String na posicao index - 0 (convertendo a string para numero)
		Por exemplo, suponhamos que o numero passado seja 92:
		
		Primeira execucao:
		type_flag = 0 * 10 + 9 - '0';   *Valor de typeflag apos a execucao eh 9*
		
		Segunda execucao
		type_flag = 9 * 10 + 2 - '0';  *Valor de typeflag apos a segunda execucao eh 92*
		*/
		(*index)++; // Incremento para verificarmos o proximo elemento, enquanto forem digitos
	}
	return (type_flag); // Retornamos o numero obtido
}

static void	ft_zero_minus(const char *format, t_flags *flags)
{
	while (format[flags->index] == '-' || format[flags->index] == '0')
		/*Enquanto a string na posicao flags->index for - ou 0, faremos as atribuicoes abaixo, lembrando 
		que em nossa funcao principal ja inicializamos todas as flags com o valor de zero! */
	{
		flags->minus = format[flags->index] == '-' ? 1 : flags->minus;
		/*flags->minus recebera um valor de acordo com o seguinte condicional, se for igual a menos recebera o valor de 1, 
		caso contrario recebera ela mesma, que ja foi definido anteriormente como zero */
		flags->zero = (format[flags->index] == '0' && !flags->minus) ? 1 : 0;
		/*flags->zero recebera um valor de acordo com o seguinte condicional, se for igual a 0 e enquanto flag->minus for nulo
		 recebera o valor de 1 pois nao existe zero negativo, caso contrario recebera ela mesma, que ja foi definido anteriormente 
		 como zero */
		flags->index++; /*O incremento serve para sair da posicao zero ou -, somente com um incremento a condicao acima ja deixa
		de existir */

		/*Nao eh necessario fazer algum retorno, pois estamos usando ponteiros para Structs ->, entao o valor ja esta sendo atribuido
		as variaveis */
	}
}

static void	ft_width(const char *format, va_list ap, t_flags *flags)
{
	if (format[flags->index] == '*')
	{
		flags->width = va_arg(ap, int); //flags->width recebe o proximo argumento da funcao, tipo INT
		if (flags->width < 0) // Aqui fazemos um tratamento de dados, caso o valor seja menor que 0, faremos o seguinte
		{
			flags->minus = 1; // flags->minus recebe 1, pois se trata entao de um numero negativo
			flags->zero = 0; // flags->zero receber 0 (Nulo), pois nao se trata de um zero e sim de um numero negativo
			flags->width *= -1; /* Sabemos que eh um numero negativo, porem a leitura do comprimento nao pode seguir negativamente, 
								   entao fazemos o numero multiplicado por -1, para que vire positivo. O fato de que seja um numero 
								   negativo ja esta registrado em flags->minus = 1 */
		}
		flags->index++; // Incremento para o proximo elemento
	}
	else
		flags->width = ft_getnumber(format, &flags->index);
	/*Se o proximo elemento apos o 0/- nao for um *, entao verificamos de eh um numero e checaremos qual o numero com a funcao
	 auxiliar ft_getnumber, o valor sera atribuido a flags->width */
}

static void	ft_precision(const char *format, va_list ap, t_flags *flags)
{
	flags->dot = 1; // Como um ponto foi identificado, entao flags->dot recebe 1
	flags->index++; // Fazemos um incremento, pois queremos saber o que ha depois do pon to, seja um numero ou o que for
	if (format[flags->index] == '*') // Se tivermos um *, ou seja, tudo que vier depois
	{
		flags->precision = va_arg(ap, int); // Recebe o valor que acessa o próximo argumento da função  type va_arg(va_list ap, type); 
		flags->zero = flags->precision >= 0 ? 0 : flags->zero; // se precision for >= 0 entao recebe 0, caso contrario recebe ele mesmo
		flags->index++; 
	}
	else
	{
		if (ft_isdigit(format[flags->index]))
			/*Faremos aqui uma condicao, chamando a funcao isdigit, para verificarmos se ha um numero depois do ponto final, 
			alem disso, a condicao soh sera verdadeira enquanto nao for nulo, ou seja, 0. No final atribuimos o valor a flags->zero como
			nulo (0), se fosse um zero atribuiriamos um valor 1*/
			flags->zero = 0; //
		flags->precision = ft_getnumber(format, &flags->index);
		/*Agora soh no resta verificar qual eh o numero que se encontra depois do ponto, novamente usando nossa funcao auxiliar
		ft_getnumber*/
	}
}

void		ft_checkflags (const char *format, va_list ap, t_flags *flags)
/*Lembrando que essa funcao sera iniciada a partir do momento que nossa funcao principal encontrar um % para verificar qual sao
as flags seguidas da %, entao comecaremos por fazer um incremento na posicao INDEX, que atualmente se encontra no caracter % */
{
	flags->index++; /* Em nossa funcao principal ja definimos que o flags->index se inicia com um valor de zero, 
					aqui iremos fazer um incremento para verificar o conteudo da string*/
	if (format[flags->index] == '-' || format[flags->index] == '0')
		/*Enquanto estivermos lendo a nossa string, caso o index encontre ou um sinal de menos ou um zero, chamaremos a funcao
		ft_zero_minus e passaremos a string na posicao index e as flags*/
		ft_zero_minus(format, flags);
	ft_width(format, ap, flags);
	/*Nosso proximo passo sera agora realizar uma verificacao para saber qual sera o comprimento da nossa flag, a primeira vista
	pode ser que o pensamento fosse verificar o ponto(.), porem devemos lembrar que podem ser especificados ou numeros ou asterisco
	antes do ponto, por exemplo 2.5 ou *. e assim por diante, entao vamos verificar se depois do 0/- temos um numero ou um asterisco
	e depois seguiremos para o ft_precision */
	if (format[flags->index] == '.')
		/*Agora que ja foram verificadas as condicoes anteiores, soh nos falta confirmar se ha algum ponto e caso haja algum ponto
		devemos ver qual o valor depois do mesmo, para isso usaremos a ft_precision*/
		ft_precision(format, ap, flags);
}
 -----------> ft_printchar <-----------

#include "libftprintf.h"

void	ft_printchar(va_list ap, t_flags *flags)
{
	char	c;
	int		space;

	c = va_arg(ap, int);
	space = flags->width > 1 ? flags->width - 1 : 0; 
	/*Se flags->width for maior que 1, entao space recebe o valor de flags->width -1, se nao for maior que 1 entao recebe o valor 0
	Aqui iremos verificar a quantidade de espacos que teremos que colocar antes do nosso char, dependendo do que foi especificado no 
	%c, por exemplo, se a entrada for %2c entao o char deveria ser exibido < c>, ou se for %-2c a saida eh <c >
	Entao se for maior que 1, devemos subtrair um porque
	um dos espacos pertence ao CHAR em si, agora se for menor ou igual que 1, nao ha como mexer nos espacos
	*/
	flags->ret += 1 + space;
	/*flags->ret, que foi iniciada com 0 no printf recebera ret + 1, ou seja 1 somado ao space, que pode ser -1 ou 0, 
	  dependendo do comprimento*/
	if (!flags->minus) // Se flag->minus nao existir, ou seja, se nao tiver o sinal de -
		while (space-- > 0) //Enquanto o espaco-- for maior que 0
			ft_putchar_fd(' ', 1); // Exibimos espacos em branco
	ft_putchar_fd(c, 1); // e depois dos espacos em branco, exibimos nosso caracter
	if (flags->minus) // Se a flag->minus existir, ou seja, se tiver o sinal de -
		while (space-- > 0) // Enquanto o espaco-- for maior que ero
			ft_putchar_fd(' ', 1); // exibimos os espacos depois do caracter
}

 -----------> ft_printpercent <-----------


#include "libftprintf.h"

void	ft_printpercent(t_flags *flags)
{
	int	space;
	int	zero;

	/*Aqui iremos verificar a quantidade de espacos que teremos que colocar antes da nossa porcentagem, dependendo do que foi especificado 
	no %f, por exemplo, se a entrada for %6.2f%% e o valor for 50 entao o  deveria ser exibido < 50.00>, ou se for %-2c a 
	saida eh <50.00 %>
	Basicamente o comportamento seria igual a um caracter normal, porem para exibirmos uma porcentagem devemos usar no final %%, seguidos.
	Assim sera exibido o caracter % e tudo que vier antes tratamos da mesma forma que nosso char, verificando espacos, quantidade de 
	numeros apos a virgula, etc.
	A variavel "zero" eh necessaria pois ao contrario de um char, ao definirmos a quantidade de numeros apos a virgula, devemos completar
	esses espacos com 0, entao se eu definir na entrada %10.5f%%, a saida esperada sera <  50.00000%>
	Da mesma forma teremos que verificar a quantidade de espacos, pois como no exemplo acima definimos 10 espacos, e nossa porcentagem soh
	ocupou 8, ou seja, o inicio (ou final se colocarmos um - na frente) precisariam de 2 espacos vazios
	*/
	zero = flags->width > 1 && flags->zero ? flags->width - 1 : 0;
	/*Se flags->width for maior que 1 e flags->zero existir (nao for nulo), entao space recebe o valor de flags->width menos 1, 
	se nao for maior que 1 entao recebe o valor 0. */
	space = flags->width > 1 && !zero ? flags->width - 1 : 0;
	/*Se flags->width for maior que 1 e flags->zero for nulo, entao space recebe o valor de flags->width menos 1, 
	se nao for maior que 1 entao recebe o valor 0. */
	flags->ret += 1 + zero + space;
	/*flags->ret, que foi iniciada com 0 no printf recebera ret + 1, ou seja 1 somado ao space e ao zero, que podem ser -1 ou 0, 
	  dependendo do comprimento*/
	if (!flags->minus) // Se nao houver um sinal de - no comeco
		while (space-- > 0)
		/*Se nao ha um sinal de menos, entao temos que fazer um decremento de space enquanto seja maior que 0, a razao para isso eh que
		se nao ha um zero na frente, os espacos vazios sao colocados da esquerda para direita, entao a especificacao
		%5.1f%% exibe < 50.0%>, os espacos vazios comecam da esqueda para direita*/
			ft_putchar_fd(' ', 1); //Aqui colocamos os espacos vazios antes do conteudo, de acordo com as especificacoes do indicador %
	if (flags->zero)
		while (zero-- > 0)
		/*Se a flags-zero existir, entao faremos praticamente o mesmo que fizemos acima, porem adicionando zeros ao comeco de nossa
		porcentagem. Por exemplo, se a entrada for %05.1f%%, a saida esperada eh <050.0%> */
			ft_putchar_fd('0', 1); //Aqui colocamos os espacos vazios antes do conteudo, de acordo com as especificacoes do indicador %
	ft_putchar_fd('%', 1); // No final das checagens acima, temos que colocar o sinal de % para indicar que se trata de porcentagem
	if (flags->minus) // Agora, no caso de houver um sinal de - no comeco da especificacao
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	/*Quando existem sinais de - no comeco, devemos inserir os espacos depois de todo o conteudo, por isso nao ha problema em fazer
	esse condicional depois de toda a execucao acima, pois de a entrada for <%-6.1f%%> a saida esperada eh <50.0  %>*/
}

 -----------> ft_printstring <-----------

#include "libftprintf.h"

void		ft_printstring(va_list ap, t_flags *flags)
{
	char	*str;
	int		len;
	int		space;
	int		zero;

	if (!(str = va_arg(ap, char*)))
	/*Em primeiro lugar verificamos se a nossa string naio possui conteudo algum,
	de acordo com a funcionalidade do printf, caso a string nao possua nada de conteudo a exibicao padrao eh (null)
	Por exemplo:
	printf("Teste de string nula: %s\n", NULL);
	Saida do comando acima sera (null)
	*/
		str = "(null)"; // Entao caso nao exista conteudo, atribuidos o conteudo (null) a nossa string para ter a mesma saida do printf
	/*Para o tratamento de strings precisaremos verificar se ha algum ponto(.) antes da string, pois o printf possui comportamentos 
	diferentes, por exemplo, se a nossa string for "Raul" e a indicacao for %.1s o resultado da string sera <R>, ou seja, soh a primeira
	letra da nossa string eh exibida, com %.2s o resultado eh <Ra> e assim sucessivamente. 
	Agora, se houver um numero antes do ponto(.), por exemplo %4.2s, a exibicao seria <  Ra> 
	Para fazer tal tratamento de dados, precisaremos verificar qual o tamanho total da string*/
	if (flags->precision > 0 && flags->precision < (int)ft_strlen(str)) // Se flags->precision for maior que zero e for menor que strlen
		len = flags->precision; // Len recebe o valor de flags->precision
	else
		len = (flags->dot && !flags->precision) ? 0 : ft_strlen(str);
	/*Se flags->dot existir e flags->precision nao, entao recebe 0, else recebe o tamanho da string

	Abaixo novamente temos as nossas classicas variaveis space e zero, conforme utilizacao previa no ft_printchar e ft_printpercent
	mas dessa vez somamos o LEN ao resultado, porque da mesma maneira teremos que adicionar espacos antes ou depois, dependendo
	da flag passada no printf*/
	zero = flags->width > len && flags->zero ? flags->width - len : 0;
	space = flags->width > len && !zero ? flags->width - len : 0;
	flags->ret += len + space + zero;
	if (!flags->minus)
		while (space-- > 0)
		/*Se nao ha um sinal de menos, entao temos que fazer um decremento de space enquanto seja maior que 0, a razao para isso eh que
		se nao ha um zero na frente, os espacos vazios sao colocados da esquerda para direita, entao a especificacao
		%3.1 exibe <  R>, os espacos vazios comecam da esqueda para direita*/
			ft_putchar_fd(' ', 1);
	if (flags->zero)
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
	/*Se a flags-zero existir, entao faremos praticamente o mesmo que fizemos acima, porem adicionando zeros ao comeco de nossa
		porcentagem. Por exemplo, se a entrada for %05s, a saida esperada eh <050.0%> */
	while (len--) // Enquanto len-- nao for nulo
		ft_putchar_fd(*str++, 1); // Fazemos a exibicao da nossa string++, para exibir os campos seguintes
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
	/*Quando existem sinais de - no comeco, devemos inserir os espacos depois de todo o conteudo, por isso nao ha problema em fazer
	esse condicional depois de toda a execucao acima, pois de a entrada for <%-6s%%> a saida esperada eh <  Raul> */
}

 -----------> ft_printnumber <-----------

/* Justamente para a utilizacao dessa funcao que ira mexer com bases, em nosso libftprintf.h fizemos as seguintes definicoes:
# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

Ou seja, ja deixamos definidas bases para decimais e hexadecimais Upper/lower case, entao na nossa funcao podemos 
chamar apenas as variaveis DECIMAL, HEX_LOWER ou HEX_UPPER
*/

#include "libftprintf.h"

static void	ft_setflags(t_flags *flags, unsigned int num, int len, char *base)
{
	/*Agora que temos acesso as flags, o numero, quantidade de digitos e base, eh hora de definir as flags*/
	int	zero;
	int	space;

	flags->negative ? len++ : 0; // Se negative for True(1), len++, se nao, recebe 0
	if (flags->dot && !flags->precision && !num) // Se dot for True e Precision False e Num False
		len = 0; // Len recebe o valor de 0
	if (flags->precision > len) // Se precision for maior que o numero
		zero = flags->precision - len; // zero recebe precision - len
	else
		zero = (flags->width > len && flags->zero) ? flags->width - len : 0;
	len += zero > 0 ? zero : 0;
	space = flags->width > len && !flags->zero ? flags->width - len : 0;
	flags->ret += len + space;
	if (!flags->minus) // Aqui executaremos o mesmo procedimento de verificacao de char/string/percent, conforme explicacoes ja passadas
		while (space-- > 0) 
			ft_putchar_fd(' ', 1);
	flags->negative ? ft_putchar_fd('-', 1) : 0;
	while (zero-- > 0)
		ft_putchar_fd('0', 1);
	if (len)
		ft_putnbr_base_fd(num, base, 1);
	if (flags->minus)
		while (space-- > 0)
			ft_putchar_fd(' ', 1);
}

static int	ft_numberlen(unsigned int number, int base_size)
{
	/*Funcao simples apenas para identificarmos o tamanho do nosso numero, para o caso de ser de base 10 ou maior
	Vamos supor que o numero passado seja 25 e base 10 e simular a execucao*/
	size_t	len; 

	len = 1;
	while (number / base_size > 0) // Enquanto 25 / 10 for maior que 0
	{
		len++;
		number /= base_size; /* number recebe ele mesmo dividido por base_size, entao number = 25/10 = 2
		Lembrando que em divisao de inteiros / decimais, sempre ha um resultado inteiro, entao 25/10 = 2, mod 5
		Agora na segunda execuxao, 2 ainda eh maior que 0 entao executa de novo
		number = 2/10 = 0 
		Entao nao havera uma proxima execucao, pois 0/10 nao eh maior que zero, entao dessa maneira a funcao foi 
		executada duas vezes, entao sabemos que nosso numero tem 2 digitos, que eh o valor de LEN apos duas execucoes
		*/
	}
	return (len); // Retornamos o valor de LEN, que no caso do nosso exemplo seria 2
}

void		ft_printdiux(va_list ap, char c, t_flags *flags)
{
	/*Funcao utiliada para identificarmos a qual tipo de dados numerais. 
	Podendo ser tanto %i, %d, %u ou %xX */
	int				num;
	unsigned int	unum; // Como uxX se referem a unsigned number, devemos ter uma variavel para tais casos, alem da variavel num

	if (c == 'i' || c == 'd')
	/*O comportamento de numeros inteiros e decimais no Printf eh exatamente igual, entao podemos usar uma estrutura para ambos */
	{
		num = va_arg(ap, int); // Numero recebe acesso o próximo argumento, ap, da funcao do tipo INT
		if (num < 0)
		{
			flags->negative = 1; // Se o numero for menor que 0 sera negativo, entao damos o valor 1 (True) para flags->negative
			num *= -1; // Multiplicamos o numero por -1, para trabalharmos com o valor positivo do mesmo -1 * -1 = 1
			flags->precision += flags->precision > 0 ? 1 : 0; // Se flags->precision =+ for maior que -, recebe o valor 1, se nao recebe 0
		}
		ft_setflags(flags, num, ft_numberlen(num, 10), DEC);
		/*Agora chamamos a funcao ft_setflags e passamos as flags, o nosso numero, uo len do nosso numero e a base que iremos verificar,
		nesse caso por se tratar de I ou D, passamos abase DECIMAL (DEC) para a funcao*/
	}
	else if (c == 'u' || c == 'x' || c == 'X')
		/*A condicao abaixo soh se iniciara caso c for u ou x ou X */
	{
		unum = va_arg(ap, unsigned int); // nosignnum recebe acesso o próximo argumento, ap, da funcao do tipo UNSIGNED INT
		if (c == 'u')
			// Se for u, se trata de um unsigned decimal, entao chamamos a funcao da mesma forma que fizemos com a variavel num
			ft_setflags(flags, unum, ft_numberlen(unum, 10), DECIMAL);
		else
			c == 'x' ?
			ft_setflags(flags, unum, ft_numberlen(unum, 16), HEX_LOWER) :
			ft_setflags(flags, unum, ft_numberlen(unum, 16), HEX_UPPER);
			/*Nessa funcao os valores remanescentes soh podem ser u/x/X, u ja teve seu tratamento, agora soh nos restam xX
			Entao faemos um condicional, se c == x, chamamos a funcao setflags com a base HEX_LOWER, se nao, chamamos com HEX_UPPER*/
	}
}