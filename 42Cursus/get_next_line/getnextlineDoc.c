********************************************************* 42Cursus *********************************************************


------------------------------------Third Project - Get_Next_Line-----------------------------------

Sources:
https://github.com/520luigi/Get_Next_Line/blob/master/get_next_line.c
https://github.com/jraleman/42_get_next_line/blob/master/src/get_next_line.c

vim modifications: vim ~/.vimrc

X------------------CONCEITOS IMPORTANTES PARA A IMPLEMENTACAO A FUNCAO------------------X

-> Objetivo principal

* A funcao ira ler um texto disponivel em um file descriptor (pasta), uma linha por vez ate chegar ao fim do arquivo (EOF)
* Ira retornar 1 quando uma linha for lida, 0 quando o EOF for atingido ou -1 quando ocorra um erro
* A fucao podera administrar diversos file descriptors


---> File Descriptors <---

Um FILE DESCRIPTOR (FD) eh um numero que identifica um arquivo aberto em um sistema operacional de um computador. Sao identificados
por numeros inteiros nao negativos, pelo menos um FD existe para cada arquivo aberto em nosso sistema. Quando um programa pede para abrir
um arquivo, o Kernel segue o procedimento abaixo:

1- Concede acesso
2- Cria uma entrada na tabela global de arquivos
3- Proporciona ao Software a localizacao da entrada

Quando o processo faz uma solicitacao para abrir o arquivo, o Kernel retorna um FD que aponta para a entrada no Kernel Global File Table,
que por sua vez contem informacoes como INODE** do arquivo, byte OFFSET** e as restricoes de acesso para aquele 
DATA STREAM** (ex: read-only, write-only, etc)

**INODE: Abreviacao para INDEX NODE, eh o index que contem detalhes sobre cada arquivo, como seu nodulo, owner, arquivo, localizacao, etc
**BYTE OFFSET: Determina a diferenca de localizacao de um pedaco de data comparado com outra localizacao, ou seja, em um array de bytes
			   o quinto byte esta offset por 4 do comeco do array
**DATA STREAM: Uma transmissao continua de byte-by-byte entre computadores

Valor Int  | 		Nome
-----------|----------------------------
	0 	   |	Entrada padrão (stdin)
	1	   |	Saída padrão (stdout)
	2	   |	Erro padrão (stderr)

STDIN: 	Entrada padrao, por exemplo, no Terminal quando sao inseridas informacoes atraves do teclado, eh um standard input
STDOUT: Saida padrao, por exemplo, eh o retorno que temos por executar um comando, o que eh exibido na nossa tela.
STDERR: Erro padrao, um output que esta relacionado a algum erro que possa haver ocorrido, exibe na tela o erro.

De forma geral, um FILE DESCRIPTOR eh um indice para um registro de uma estrutura de dados, que contem detalhes de todos os arquivos abertos.
Os FD podem se referir nao somente a arquivos, mas tambem a diretorios, dispositivos de memoria, etc.

---> Static Variables <---

Variaveis estaticas sao variaveis que mantem seu valor, mantem-se na memoria durante toda a execucao do programa. Uma variavel normal
geralmente eh destruida quando a function call termina. 

int variavelNormal()
{
	int count = 0;
	count++;
	return (count);
}

int main ()
{
	printf("%d", variavelNormal());
	printf("%d", variavelNormal());
}

O output do programa acima sera "1 1", pois a variavel eh destruida depois da function call, nao mantem seu valor, assim que quando a 
chamamos de novo, seu valor ja foi resetado.

int variavelEstatica()
{
	static int count = 0;
	count++;
	return (count);
}

int main ()
{
	printf("%d", variavelNormal());
	printf("%d", variavelNormal());
}

Ja o output da funcao acima sera "1 2", pois a variavel estatica manteve seu valor apos a primeira execucao, ou seja, quando a funcao foi
chamada novamente, a variavel count ja possuia o valor de 1, ao executar count++ virou 2, por isso o output diferente.

Para que usaremos static variables na funcao get_next_line? Precisamos chamar GNL ateh o final do nosso arquivo, entao precisamos uma 
variavel estatica para segurar a leitura de uma linha com a quantidade do BUFFER_SIZE ateh que o programa acabe.


---> Implementacao da funcao <---

get_next_line ira ler um arquivo com o tamanho de BUFFER_SIZE e determinar se a string eh uma linha (\n) ou nao.
Se a string que for lida nao for uma quebra de linha, entao a funcao ira ler o arquivo com a mesma quantidade novamente. Para isso iremos criar
uma variavel estatica:


static char *saved[OPEN_MAX] // pointer para saved

OPEN_MAX eh o numero maximo de arquivos que um processo pode ter aberto por vez, para utilizarmos OPEN_MAX devemos ter a biblioteca
"<limits.h>"
A utilizacao do ponteiro duplo sera para administrar as strings de N arquivos e assim seguraremos as linhas lidas ateh o programa acabar.

char buf[BUFFER_SIZE + 1]

Acima estamos criando um array temporario que ira segurar uma string lida com a quantidade de BUFFER_SIZE, que mais tarde sera juntado
com a string SAVED que definimos antes!

>>> Passos de implementacao

1 - Verificar se a static variable saved[fd] possui uma nova linha "\n".
		-> SIM? Uma variavel LINE ira receber a string antes de ter chegado a nova linha, que sera copiada de saved[fd]
			line = ateh "\n"
			saved[fd] = tudo depois de "\n"

		-> NAO? Entao saved[fd] sera escrito em saved[fd] depois de uma nova linha.

2 - Ler um arquivo com a quantidade de BUFFER_SIZE. //read (fd, buf, BUFFER_SIZE)
		-> Juntaremos o saved[fd] com buf. //strjoin (saved[fd], buf)
		-> Voltamos ao passo 1.

---> Read function <---

read(int fd, void *buf, size_t count);

A funcao Read eh utilizada para ler um FD, entao a funcao tenta ler ateh uma quantidade COUNT de bytes de um FD para o  
BUFFER comecado em buf.
Em arquivos que oferecem suporte à busca, a operação de leitura começa no deslocamento do arquivo atual e o deslocamento do 
arquivo é incrementado pelo número de bytes lidos. Se o deslocamento do arquivo atual está no final do arquivo ou depois dele, 
nenhum byte é lido e read () retorna zero.



---> Por fim, get_next_line <---

#include "get_next_line.h"
#include <limits.h> // Biblioteca necessaria para OPEN_MAX

/*
** A função saveLine acrescenta uma única linha em nossa variável de linha. Nós fazemos isso para
** encontrar o comprimento da linha. Se no índice len, o caractere é uma nova linha (\n),
** salvamos a string alinhada com o comprimento encontrado. Então nós reajustamos o
** dados armazenados (** s) criando uma string temporária que armazenou o resto dos dados
** após a nova linha. Libertamos os dados armazenados para atualizá-los para o atual
** endereço porque já acrescentamos uma linha dele. Isso é feito liberando * s
** e definindo-o igual à string temporária que armazenou os dados restantes.
** A qualquer momento, quando chegamos ao final do arquivo, liberamos a memória usada para
** rastreie nossa localização em * s porque ela não é mais necessária.
*/

static int	saveline(char **s, char **line)
{
	int		len; // Index para encontrar o comprimento da linha
	char	*tmp; // string temporária que armazenara o resto dos dados após a nova linha.

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0') // Enquanto String na posicao len for diferente de quebra de linha e for diferente de nulo
		len++; // incremento para descobrir o tamanho
	if ((*s)[len] == '\n') // Se a string na posicao LEN for uma quebra de linha
	{
		*line = ft_substr(*s, 0, len); 
		/*  LINE recebe retornado da funcao char *ft_substr(char const *s, unsigned int start, unsigned int len)
			funcao que encontra uma substring dentro de uma string original. Os parametros passados aqui sao a string original, a
			posicao start 0 e o index LEN
			Basicamente LINE recebe todo o conteudo da string *s ateh chegar na quebra de linha
		*/
		tmp = ft_strdup(&((*s)[len + 1])); 
		/* A variavel tmp recebe o retorno da funcao String Duplicate char *ft_strdup(char *src) e como paratmetros estamos 
		passando o que esta contido no endereco de S, ou seja &s na posicao LEN + 1, ou seja, ira armazenar o resto dos dados 
		contidos depois da quebra de linha, ou seja, todo o resto
		*/
		free(*s); //Agora liberamos os blocos de memoria da variavael *s 
		*s = tmp; // Recebe o valor de tmp, ou seja, tudo que vem em seguida da quebra de linha
		if ((*s)[0] == '\0') /* Se o valor na posicao 0 for nulo, significa que ja nao ha mais conteudo, ou seja, 
							soh nos resta eliminar o conteudo armazenadoa anteriormente */
			free(*s); // Liberar o bloco de memoria
			*s = NULL; // Definimos S como nulo, ja nao eh mais necessario
	}
	else
	{
		*line = ft_strdup(*s); // Se String Index Len nao for uma qubera de linha, soh chamamos a strdup
		/* Lembrando que
			strdup () faz alocação de memória dinâmica para a matriz de caracteres, incluindo o caractere final '\ 0' e retorna 
			o endereço da memória heap. Então, o que ele faz é nos dar outra string idêntica à string dada por seu argumento, 
			sem exigir que aloquemos memória. Mas ainda precisamos liberá-lo, mais tarde.
		*/
		free(*s); // liberamos
		*s = NULL;
	}
	return (1);
}

/*
Em primeiro lugar, faremos uma funcao auxiliar para o output dos resultados. O especifica que:
Return value
 1 : A line has been read - Se a linha for lida, entao chamaremos outra funcao que ira armazenar 
	salvar o valor no endereco atual de nossa variavel estatica
 0 : EOF has been reached - Se a leitura eh completada, retorna 0
-1 : ERROR

Ou seja, quando chegarmos a funcao get_next_line, usaremos a funcao READ para verificar se a linha foi lida, 
se chegamos ao fim do arquivo ou se temos um erro.
*/

static int	output(char **s, char **line, int retorno, int fd)
{
	if (retorno < 0) // Em primeiro lugar, se o FD for menor que 0, erro de primeira, pois FD soh podem ser INTs positivos!
		return (-1); 
	else if (retorno == 0 && s[fd] == NULL)
		return (0);
	else
		return (saveline(&s[fd], line));
}

/*
** A função get_next_line lê um arquivo e retorna a linha que termina com um
** caractere de quebra de linha (\n) de um FD. Uma variável estática é usada, de modo que
** sempre que get_next_line é chamado, ele se lembra da chamada de função anterior.
** Quando get_next_line é chamado pela primeira vez, verificamos se nossa variável estática
** *saved está vazio. Se for, alocamos memória para ele usando nossa string de buff.
** No loop, continuaremos a ler mais sobre a linha e juntá-los
** usando uma string temporária. Esta string temporária irá substituir os dados armazenados
** cada iteração para que possamos acompanhar o quanto é lido e excluído
** os dados armazenados anteriormente. Isso é necessário porque estamos lendo apenas alguns
** n bytes por vez decidido por nosso BUFF_SIZE. Se lermos em cada iteração
** sem liberar memória, teríamos vazamentos de memória. O loop quebra quando
** uma nova linha é encontrada. Finalmente, chamamos a função de saída para verificar o que
** deve ser devolvido.
*/

int			get_next_line(int fd, char **line)
{
	int			retorno;
	static char	*saved[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1]; // Durante a compilacao, BUFF_SIZE eh definido, portanto nao eh necessario iniciar a variavel
	char		*tmp; /* Esta string temporária irá substituir os dados armazenados cada iteração para que possamos acompanhar o 
						quanto é lido e excluído dos dados armazenados anteriormente */

	if (fd < 0 || line == NULL) //Se o File Descriptor for menor que 0 ou Nulo, retorna erro, pois FD soh podem ser inteiros positivos!
		return (-1); // Retorna -1 como erro
	while ((retorno = read(fd, buff, BUFFER_SIZE)) > 0) 
	/* RETORNO recebera o resultado da execucao da funcao READ conforme falamos na parte do OUTPUT, se for menor que 0 automaticamente
	   eh um erro, ou seja, enquanto for maior que 0 podemos executar os comandos abaixo
	*/
	{
		buff[retorno] = '\0'; // OBS buff eh um ponteiro para alguma parte da memoria, aqui estamos dizendo que essa parte da memoria recebe 0
		if (saved[fd] == NULL) // Se a string na posicao FD for nula
			saved[fd] = ft_strdup(buff); // Entao ira receber o retorno de strdup, que duplica buff para saved, ou seja, duplica \0
		else
		{
			tmp = ft_strjoin(saved[fd], buff);
			/* Aqui nossa variavel temporaria recebe  
			*/
			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (ft_strchr(saved[fd], '\n')) 
			/*
			Lembrando que strchr busca a primeira ocorrencia do caracter passado como parametro e retorna um ponteiro para a primeira
			ocorrencia do caracter, ou seja, vai retornar um ponteiro de onde esta a primeira quebra de linha!
			*/
			break ; /*O loop da break quando uma nova linha é encontrada. */
	}
	return (output(saved, line, retorno, fd)); // Finalmente, chamamos a função de saída para verificar o que deve ser devolvido.
}


---> Funcoes utilizadas acima <---

Conforme o enunciado do projeto, nao eh permitido utilizar a nossa biblioteca libft, entao devemos criar uma nova biblioteca somente
para o get_next_line, e as funcoes adicionais que tivemos que utilizar estarao contidas no seguinte arquivo:


get_next_line_utils.c

As funcoes utilizadas para a implementacao de nossa get_next_line foram:

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *src);
size_t		ft_strlen(const char *s);

Acima temos apenas os prototipos, pois nao ha necessidade de escreve-las novamente, visto que ja temos e ja entregamos todas essas funcoes
no libft, ou seja, soh precisamos fazer um arquivo "get_next_line_utils.c" com todas essas funcoes inclusas e #include "get_next_line.h"


---> Biblioteca get_next_line <---


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int			get_next_line(const int fd, char **line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *src);
size_t		ft_strlen(const char *s);

#endif

---> Main para testes <---

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char **line;
    int ret;

    fd = open("text.txt", O_RDONLY);
    if (!(line = (char **)malloc(sizeof(char*) * 10000)))
        return (0);

    while ((ret = get_next_line(fd, line)) > 0)
    {
        printf("%s\n", *line);
        printf("%i\n", ret);
        free(*line);
    }
    printf("%s\n", *line);
    printf("%i\n", ret);
    free(line);
    return(0);
}

---> Como testar o GNL <---

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c && ./a.out


---> Como entregar os bonus <---

O get_next_line desenvolvido acima ja tem capacidade para executar diferentes files descriptors, ou seja, apenas eh necessario
criar uma copia dos arquivos get_next_line.c, get_next_line_utils.c e get_next_line.h, porem adicionar _bonus ao final