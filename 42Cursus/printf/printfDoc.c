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

vim modifications: 
 
vim ~/.vimrc

syntax on
set nu
set ruler
set mouse=a

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


 -----------> Formatacao de Data <-----------
*** Referencia: https://www.cplusplus.com/reference/cstdio/printf/?kw=printf


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


 -----------> Struct <-----------
*** Referencia: https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm


Structs definem tipos de dado que agrupam variaveis sob um mesmo tipo de dadod. A ideia principal eh permitir que ao armazenar os dados 
de uma mesma entidade, isso possa ser feito com uma unica variavel. Por exemplo, para armazenar a altura, peso e idade de uma pessoa, 
podemos simplemente criar uma struct chamada 'Pessoa' e agrupar os dados em um unico tipo de dado. Por exemplo:

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
	char *nome // definindo o nome
	float peso; // Definindo o campo peso
	int idade; // Definindo o campo idade
	float altura; // Definindo o campo altura
} TipoPessoa; // Aqui definimos o nome do novo tipo criado

Apos a criacao do tipo Pessoa, podemos declarar variaveis do tipo Pessoa, da seguinte maneira

TipoPessoa Pessoa1, Pessoa2; // Aqui criamos duas variaveis que sao do tipo TipoPessoa
TipoPessoa Povo[10]; // Criando um array com 10 pessoas 

Agora para acessar os campos da STRUCT, a sintaxe seria NomeDaVariavel.NomeDoCampo, conforme exemplo

P1.nome = "Raul";
P1.Idade = 26;
P1.Altura = 1.89;
P1.Peso = 90;

Povo[4].Nome = "Lucas"; //Aqui definimos que a pessoa na posicao 4 do array Povo recebe o nome Lucas
Povo[4].Idade = 21;
Povo[4].Altura = 1.79;
Povo[4].Peso = 70;

Com as STRUCTS ainda podemos atribuir os dados de uma STRUCT para outra, com apenas um comando de atribuicao simples, por exemplo:

P2 = Povo[4];


x-- Passando Structs por parametro --x

#include <stdio.h>

typedef struct 
{
	char *nome;
	float altura;
	int idade;

} pessoa;

void printpessoa (pessoa P)
{
	printf ("Nome: %s / Idade: %d / Altura: %.2f \n", P.nome, P.idade, P.altura);
}

int main ()
{
	pessoa p1;
	int x = 5;
	pessoa povo[x];

	p1.nome = "Raul";
	p1.idade = 26;
	p1.altura = 1.89;

	povo[2].nome = "Lucas";
	povo[2].idade = 21;
	povo[2].altura = 1.70;

	printpessoa (p1);
	printpessoa (povo[2]);
	return (0);
}


x-- Passando Structs por referencia --x


Para pasarmos uma Struct por referencia, primeiro devemos passar um ponteiro para struct, conforme o exemplo

#include <stdio.h>

typedef struct 
{
	char *nome;
	int idade;
	float altura;
} pessoa;

void printperson (pessoa p)
{
	printf ("Nome: %s, idade: %d, altura: %.2f\n", p.nome, p.idade, p.altura);
}

void setperson (pessoa *p, char *name, int age, float height) // Nessa funcao o parametro P eh um ponteiro para uma struct
{
	p->nome = name;
	p->idade = age;
	p->altura = height;
	/*Existem duas formas de utilizar ponteiros para uma struct:
  	  (*p).idade = age;
  	  p->idade = age;

  	  Na nossa funcao MAIN passamos o endereco da variavel p1 (&p1), entao nosso ponteiro p aponta para o endereco de p1 
  	  e define os campos nome, idade, altura, que sao passados como parametro.
  	  No exemplo acima, deixei os nomes em PT/EN para melhor entendimento.
  	  Os parametros passados em MAIN (em ingles) sao recebidos na funcao, que sao atribuidos ao endereco de p,
  	  que por sua vez possui tipos nome, idade e altura
	*/
}

int main ()
{
	pessoa p1;
	setpessoa (&p1, "Raul", 26, 1.89);
	printperson(p1);
	return(0);
}