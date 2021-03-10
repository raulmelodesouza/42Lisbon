********************************************************* 42Cursus *********************************************************


------------------------------------Fourth Project - ft_printf-----------------------------------

Sources:
https://medium.com/@SergioPietri/what-are-variadic-functions-in-c-6205e26c729f
https://medium.com/@zhang.yine/ft-printf-d95747b7aa5a
https://github.com/supalarry/ft_printf
https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
https://github.com/agavrel/42-ft_printf
https://linux.die.net/man/3/printf
https://github.com/yuki-katayama/42cursus-ft_printf
https://github.com/jraleman/42_ft_printf/blob/27163ad4bdd4a850d3a9bae91f78b1ec662cd149/src/ft_printf.c
'https://github.com/vscabell/ft_printf'

vim modifications: vim ~/.vimrc


X------------------CONCEITOS IMPORTANTES PARA A IMPLEMENTACAO A FUNCAO------------------X

---> Variadic Functions <---

Variadic Functions sao funcoes que podem receber um numero variavel de argumentos.

Funcoes normais de C recebem sempre um numero fixo de argumentos, quando definimos uma funcao, especificamos o tipo de cada um dos 
argumentos e cada vez que a chamamos, temos que fornecer o numero esperado de argumentos, com seus respectivos tipos, por exemplo:

foo (int, char *);

Para chamarmos a funcao acima devemos fornecer um numero inteiro e um ponteiro para uma string.  Porem, existem funcoes que executam
operacoes que podem aceitar um numero ilimitado de argumentos. 
Em alguns casos, uma função pode lidar com qualquer número de valores operando em todos eles como um bloco. 
Por exemplo, considere uma função que aloca uma matriz unidimensional com malloc para conter um conjunto especificado de valores. 
Essa operação faz sentido para qualquer número de valores, desde que o comprimento da matriz corresponda a esse número. 
Sem recursos para argumentos variáveis, você teria que definir uma função separada para cada tamanho de array possível.
A função de biblioteca printf é um exemplo de outra classe de função em que argumentos variáveis ​​são úteis. 
Esta função imprime seus argumentos (que podem variar em tipo e número) sob o controle de uma string de modelo de formato.
Essas são boas razões para definir uma função variável que pode lidar com tantos argumentos quantos o chamador decidir passar.


** Como funcoes Variadics sao definidas e utilizadas

1 - Defina a função como variável, usando reticências (‘…’) na lista de argumentos e usando macros especiais para acessar os argumentos 
das variáveis. Pelo menos um argumento fixo eh necessario antes das reticencias. 

2 - Declare a função como variável, usando um protótipo com reticências (‘…’), em todos os arquivos que a chamam.
Por exemplo:

int
func (const char *a, …)
{
  …
}

3 - Chame a função escrevendo os argumentos fixos seguidos pelos argumentos variáveis ​​adicionais.

Se uma funcao possuir variadic arguments, os valores desses argumentos devem ser acessados usando a biblioteca <stdarg.h> da
seguinte maneira:

x--Macros--x

'va_start' - permite o acesso a argumentos de função variadic

'va_arg' - acessa o próximo argumento da função variável

'va_copy' - faz uma cópia dos argumentos da função variável

'va_end' - termina a travessia dos argumentos da função variadic

x--Type--x

'va_list' - contém as informações necessárias para va_start, va_arg, va_end, and va_copy, ou seja, se comporta
			como se fosse um tipo de dado


X------------------Informacoes para a implementacao do Printf------------------X

ft_printf escreve a string C apontada pelo formato para a saída padrão (stdout). 
Se o formato incluir especificadores de formato (subsequências começando com '%'), os argumentos adicionais após 
o formato serão formatados e inseridos na string resultante substituindo seus respectivos especificadores.

prototype: int ft_printf ( const char *format, ... );

'Especificadores'|   		'Descricao'
-----------------|---------------------------------
        c        |	caracter
        s        |	NULL - terminated string
        p        |	pointer memory address	
        d        |	signed decimal base
        i        |	signed decimal base
        u        |	unsigned decimal base
        x        |	unsigned hex base (lowercase)
        X        |	unsigned hex base (uppercase)
        %        |	'%' char literal
-----------------|----------------------------------

O especificador de formato também pode conter subespecificadores: flags, largura, .precision e modifiers (nessa ordem), 
que são opcionais e seguem estas especificações:


	 'Flags'  	 |   	'Descricao'
-----------------|-----------------------------------------------------------------------------------------------------------------------
        -        |	Justificar à esquerda dentro da largura de campo fornecida; 
 				 |	A justificação à direita é o padrão (consulte o subespecificador de largura).
-----------------|-----------------------------------------------------------------------------------------------------------------------
        +        |	Força a preceder o resultado com um sinal de mais ou menos (+ ou -), mesmo para números positivos. 
        		 |  Por padrão, apenas números negativos são precedidos por um sinal -.
-----------------|-----------------------------------------------------------------------------------------------------------------------
       ' '       |	Se nenhum sinal for escrito, um espaço em branco é inserido antes do valor.	
-----------------|-----------------------------------------------------------------------------------------------------------------------
        #        |	Usado com especificadores o, x ou X, o valor é precedido por 0, 0x ou 0X, respectivamente, para valores 
				 |	diferentes de zero.
				 |	Usado com a, A, e, E, f, F, g ou G, força a saída escrita a conter um ponto decimal mesmo se não houver mais dígitos. 
				 |	Por padrão, se nenhum dígito seguir, nenhum ponto decimal é escrito.
-----------------|-----------------------------------------------------------------------------------------------------------------------
        0        |	Preencha o número à esquerda com zeros (0) em vez de espaços quando o preenchimento for especificado.
-----------------|-----------------------------------------------------------------------------------------------------------------------


	  'Width'  	 |   	'Descricao'
-----------------|-----------------------------------------------------------------------------------------------------------------------
     (Numero)    |	Número mínimo de caracteres a serem impressos. Se o valor a ser impresso for menor que esse número, 
     			 | 	o resultado será preenchido com espaços em branco. O valor não é truncado, mesmo se o resultado for maior.
-----------------|-----------------------------------------------------------------------------------------------------------------------
       *         |	A largura não é especificada na string de formato, mas como um argumento de valor inteiro adicional 
                 |	precedendo o argumento que deve ser formatado.
-----------------|-----------------------------------------------------------------------------------------------------------------------



   '.precision'  |   	'Descricao'
-----------------|-----------------------------------------------------------------------------------------------------------------------
     .numero     |	Para especificadores inteiros (d, i, o, u, x, X): a precisão especifica o número mínimo de dígitos a serem escritos.
     			 |	Se o valor a ser escrito for menor que esse número, o resultado será preenchido com zeros à esquerda. 
     			 |	O valor não é truncado, mesmo se o resultado for mais longo. Uma precisão de 0 significa que nenhum caractere 
     			 |	é escrito para o valor 0.
				 |	Para especificadores a, A, e, E, fe F: este é o número de dígitos a serem impressos após a vírgula 
				 |	decimal (por padrão, é 6).
				 |	Para especificadores ge G: Este é o número máximo de dígitos significativos a serem impressos.
				 |	Para s: este é o número máximo de caracteres a serem impressos. Por padrão, todos os caracteres são impressos até 
				 |	que o caractere nulo final seja encontrado.
				 |	Se o período for especificado sem um valor explícito de precisão, 0 será assumido.
-----------------|-----------------------------------------------------------------------------------------------------------------------
     .*          |	A precisão não é especificada na string de formato, mas como um argumento de valor inteiro adicional precedendo 
     			 | 	o argumento que deve ser formatado.
-----------------|-----------------------------------------------------------------------------------------------------------------------