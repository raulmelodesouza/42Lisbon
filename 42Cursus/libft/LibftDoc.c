********************************************************* 42Cursus *********************************************************


------------------------------------First Project - Libft-----------------------------------

Sources:
https://github.com/pbondoer/42-libft
https://github.com/elidlocke/libft
https://github.com/Vieuxnorris/Libft

vim modifications: vim ~/.vimrc

Testers
https://github.com/Tripouille/libftTester
https://github.com/jtoty/Libftest
https://github.com/alelievr/libft-unit-test

X------------------Mandatory Part------------------X

>>>>>> ft_memset <<<<<< Ja adicionado ao MakeFile
// A funcao memset substitui o numero de caracteres indicados, a partir do 0 ao numero N indicado de uma string pelo caracter indicado
// Entao se o parametro passado por str (Raul) c(P) n (2)
// Resultado exibido seria entao PPul

#include "libft.h"

void *ft_memset(void *str, int c, size_t n)
{
	while (n > 0)
	{
		((char*)str)[n] = c; // Fazendo um cast para converter a string recebida e o caracter em formator Unsigned Char
		n--;
	}
	return (str);
}


>>>>>> ft_bzero <<<<<< Ja adicionado ao MakeFile
/*
A funcao bzero coloca zeros nos primeiros N bytes de uma string S
*/

#include "libft.h"

void	ft_bzero (void *str, size_t n)
{
	ft_memset (str, 0, n); //Aqui chamamos a funcao memset e passamos os atributos, a string, o valor zero e n
}


void	ft_bzero (void *str, size_t n)
{
	size_t count;

	count =0;
	while (count < n)
	{
		*(char*) s = '\0';
		str++;
		count++;
	}
}

>>>>>> ft_memcpy <<<<<< Ja adicionado ao MakeFile
/*
A funcao copia N caracteres da area de memoria do source para a area de memoria do destino
*/

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t i;

	if (s1 == 0) // Se a string 1 estiver vazia
		return (NULL);
	if (s1 == s2) // Se a string 1 for igual a string 2 retorna a string 1
		return (s1);
	if (s1 == NULL && s2 == NULL) // Se ambas forem nulas, retorna s1
		return (s1);
	i = 0; // iniciando o contador
	while (i < n) // enquanto contador for menor que o tamanho definido pelo parametro
	{
		((char*)s1)[i] = ((char*)s2)[i]; // s1 recebe s2
		i++; // Incremento
	}
	return (s1); // retorna s1
}

>>>>>> ft_memcpy <<<<<< Ja adicionado ao MakeFile
/*
A funcao copia N caracteres da area de memoria do source para a area de memoria do destino, porem para assim que o caracter C eh encontrado
O valor retornado eh um ponteiro para o caracter seguinte ao caracter encontrado C ou entao NULL se C nao for encontrado nos primeiros
N caracteres do source
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i; //Contador
	unsigned char	cc;//Caracter especificado

	i = 0;
	cc = (unsigned char)c; //Cast para unsigned char, pois c eh recebido como INT
	while (i < n) //Enquanto contador menor que o numero de caracteres especificados
	{
		((char *)dst)[i] = ((char *)src)[i];//destino na posicao contador recebe source na posicao contador, ambos convertidos em ponteiros char, ja que entram na funcao como void
		i++; // acrescimo do contador
		if (((unsigned char *)dst)[i - 1] == cc) // Se o caracter na posicao for igual ao CC que recebeu C 
			return (&((unsigned char *)dst)[i]); // retorna um ponteiro para o caracter seguinte de destino depois de C
	}
	return (NULL); // Retorna NULL se o caracter C nao for encontrado nos caracteres do source
}


>>>>>> ft_memmove <<<<<< Ja adicionado ao MakeFile

/*
Funcao que copia N caracteres de um Source para uma Destino, eh mais eficiente que memcpy em termos de sobrepor memoria
Esta estruturada da seguinte maneira
void *memmove(void *str1, const void *str2, size_t n)
*/

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i; // Variavel auxiliar / Contador
	char	*dest;
	char	*source;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		while (len--)
			dest[len] = source[len];
	}
	else if (dest < source)
		ft_memcpy(dst, src, len);
	return (dst);
}

>>>>>> ft_memchr <<<<<< Ja adicionado ao MakeFile
/*
Eh uma funcao que procura a primeira ocorrencia de um caractere especificado
Estrutura da funcao 
void *memchr(const void *str, int c, size_t n)

Parameters
str − This is the pointer to the block of memory where the search is performed.

c − This is the value to be passed as an int, but the function performs a byte per byte search using the unsigned char conversion of this value.

n − This is the number of bytes to be analyzed.

Return Value
This function returns a pointer to the matching byte or NULL if the character does not occur in the given memory area.

Segue exemplo abaixo
*/

#include "libft.h"

int main () {
   const char str[] = "http://www.42Lisboa.com";
   const char ch = '4'; // Especificamos o caracter inicial como 4, ou seja, a partir do momento que encontrar o 4, retornara tudo em seguida
   char *ret;

   ret = memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}

// Retorno da execucao acima: 42Lisboa.com

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((void *)&((unsigned char *)s)[i]));
		i++;
	}
	return (NULL);
}

>>>>>> ft_memcmp <<<<<<

/*
Funcao utilizada para comparar os primeiros N bytes de area de memoria de uma string Source e um Destino
Estrutura
int memcmp(const void *str1, const void *str2, size_t n)

Parametros
str1 − um ponteiro para um bloco de memoria.

str2 − um ponteiro para um bloco de memoria.

n − Numero de bytes que vao ser comparados.

Return Value
if Return value < 0 then it indicates str1 is less than str2.

if Return value > 0 then it indicates str2 is less than str1.

if Return value = 0 then it indicates str1 is equal to str2.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

>>>>>> ft_strlen <<<<<<

#include "libft.h"

int   ft_strlen(char *str)
{
    int count;

    count = 0;
    while (str[count] != 0)
    {
        count++;
    }
    return(count);
}

>>>>>> ft_strlcpy <<<<<<

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (src[count])
	{
		count++;
		if (size == 0)
		{
			return (count);
		}
	}
	count = 0;
	while (src[count] && count < size - 1)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	count = 0;
	while (src[count])
	{
		count++;
	}
	return (count);
}

>>>>>> ft_strlcat <<<<<<

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*dest;
	const char		*source;
	size_t			i;
	size_t			dlen;

	dest = dst;
	source = src;
	i = size;
	while (i-- != 0 && *dest)
		dest++;
	dlen = dest - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen((char *)source));
	while (*source)
	{
		if (i != 1)
		{
			*dest++ = *source;
			i--;
		}
		source++;
	}
	*dest = '\0';
	return (dlen + (source - src));
}

>>>>>> ft_strchr <<<<<<

/*
Funcao que procura pela primeira ocorrencia de um caracter C (UNSIGNED CHAR) na string apontada pelo argumento str

Estrutura: 
char *strchr(const char *str, int c)

Parametros
str − Essa eh a string a ser escaneada.

c − Esse eh o caracter que sera buscado na str.

Retorno
This returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.

*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

>>>>>> ft_strchr <<<<<<

/*
Funcao que procura pela ultima ocorrencia de um caracter C(UNSIGNED) em uma string apontada pelo argumento str
Declaracao da funcao

char *strrchr(const char *str, int c)

Parameters
str − This is the C string.

c − This is the character to be located. It is passed as its int promotion, but it is internally converted back to char.

Return Value
This function returns a pointer to the last occurrence of character in str. If the value is not found, the function returns a null pointer.

*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

>>>>>> ft_strnstr <<<<<< // Funcao tambem pode ser reconhecida como strstr ou strcasestr

/*
Funcao utilizada para localizar uma substring dentro de uma string

Estruturada da seguinte maneira: 
OBS: NEEDLE eh a string menor que queremos encontrar na maior, no caso em HAYSTACK

char * strnstr(const char *haystack, const char *needle, size_t len);

A funcao localiza a primeira ocorrencia da NEDDLE no HAYSTACK, onde nao mais que o numero especificado de N eh buscado. 
Qualquer caracter que aparecer depois de um NULL - '\0' nao sao buscados. Eh uma fucnao FreeBSD (SO livre)specific API,entao soh deve
ser usada quando portabilidade nao for uma preocupacao

Abaixo exemplo de sua aplicacao
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*needle == '\0' || needle == NULL) // Se a Needle for nula retorna somente o haystack, ja que nao a nada a se buscar
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len) // Enquanto for diferente de NULL
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len) // Enquanto a posicao do Neddle for igual a posicao 
		{
			if (needle[j + 1] == '\0') // Aqui o laco roda para descobrir o tamanho total da needle, quando o tamanho de needle + 1 for = 0, ou seja, nao tivewr mais valor o laco termina
			{
				return ((char*)haystack + i);
			}
			j++; //Incremento que descobre o tamanho da Needle
		}
		i++; //Incremento que define o tamanho do Haystack
	}
	return (NULL);
}


>>>>>> ft_strncmp <<<<<<

//Funcao strncmp compara a primeira e a segunda string, porem se o tamanho for igual, a comparacao eh baseada no valor da tabela ASCII
// Entao definimos a quantidade de caracteres a serem comparados, por exemplo, soh os 4 primeiros
// Com base na tabela ASCII veremos se sao iguais, um maior ou menor que o outro

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0'
			&& s2[count] != '\0' && count + 1 < n)
		count++;
	if (s1[count] == s2[count] || n == 0)
	{
		return (0);
	}
	return (s1[count] - s2[count]);
}

>>>>>> ft_atoi <<<<<<

#include "libft.h"

int	ft_atoi(const char *str)
{
	int signal;
	int result;

	signal = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
	|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		signal = -1;
	}
	while (*str > 47 && *str < 58)
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * signal);
}

>>>>>> ft_isalpha <<<<<<

/*
** The ft_isalpha() function tests for any character for which isupper(3) or
** islower(3) is true.  The value of the argument must be representable as an
** unsigned char or the value of EOF.
*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}


>>>>>> ft_isdigit <<<<<<
/*
** The ft_isdigit() function tests for a decimal digit character.  Regardless of
** locale, this includes the following characters only: '0' - '9'
*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}


>>>>>> ft_isalnum <<<<<<

/*
Eh uma funcao que verifica se existe algum caractere alfanumero, ou seja, engloba as funcoes acima isdigit e isalpha
Supostamente retorna valores nao nulos se C for um digito ou letra, ou entao retorna 0 se nao for alphanumeric
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}

>>>>>> ft_isascii <<<<<<

/*
** Funcao que verifica se o caracter passado se encontra na tabela ASCII, ou seja, se esta entre 0 e 127
** Caso esteja contido entre esses valores estabelecidos, retorna 1, se nao retorna 0
*/
#include "libft.h"

int 	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
	{
		return (1);
	}
	return (0);
}

>>>>>> ft_isprint <<<<<<

/*
** Funcao que identifica se o caracter passado se encontra na tabela de numeros printaveis na tabela ASCII, ou seja entre 32 e 127
** Ou entao entre 32 e 126, considerando que o caracter 127 eh o DELETE, entao nao faz diferenca estar na equacao
*/

#include "libft.h"

int 	ft_isprint (int c)
{
	if ((c >= 32) && (c < 127))
	{
		return (1);
	}
	return (0);
}

>>>>>> ft_toupper <<<<<<

/*
** Funcao que se identificar um caracter minusculo, imediatamente o converte e em seguida retorna como maisculo
** 
*/
#include "libft.h"

int   ft_toupper (int c)
{
  if (c >= 'a' && c <= 'z')
  {
    c -= 32;
  }
  return(c);
}

>>>>>> ft_tolower <<<<<<

#include "libft.h"

int   ft_tolower (int c)
{
  if (c >= 'A' && c <= 'Z')
  {
    c += 32;
  }
  return(c);
}

>>>>>> ft_strdup <<<<<<

/*
A função strdup() é muito útil em situações onde temos que alocar um espaço na memória para copiar determinada string. 
Sem utiliza-lá, teríamos que alocar o espaço antes com malloc(), para em seguida usar strncpy(), por exemplo, para copiar a string. 
A função retorna um ponteiro com a string já alocada (podendo ser liberado com free() depois de seu uso) em caso de sucesso, 
ou ENOMEM como erro caso a memória não tenha sida alocada por insuficiência.
Fica bem claro a facilidade de usar strdup() em vista de que não precisamos ficar chamando 
malloc() e strncpy() toda vez que precisamos gravar alguma string numa variável já que a função faz todo o serviço.
*/

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*buff;

	buff = (char*)malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (!buff)
		return (0);
	dest = buff;
	while (*src)
		*buff++ = *src++;
	*buff = '\0';
	return (dest);
}

>>>>>> ft_calloc <<<<<<

/*
** A funcao calloc funciona de maneira similar a malloc, porem nessa funcao definimos diretamente o a quantidade de blocos de qualquer tipo 
** Porem ao contrario de malloc, Calloc inicia as variaveis de espaco atribuindo o valor de 0 a elas, malloc apenas reserva o espaco com
** qualquer tipo de "sujeira ja contida no mesmo"
*/

#include "libft.h"
//size_t eh um tiupo de dado capaz de representar o tamanho de qualquer objeto em bytes, por exemplo size_t
void	*ft_calloc(size_t count, size_t size) // size_t == unsigned int
{
	char	*new;

	if (!(new = malloc(size * count))) // malloc (size *(count)) significa que estao sendo criados SIZE blocos do tipo count
		return (NULL);
	ft_memset(new, 0, count * size);
	return (new);
}

>>>>>> ft_substr <<<<<<

/*
** A funcao a seguir devera retornar uma substring dentro de uma string S
** A substring comeca no INDEX Start e tem que ter um tamanho maximo de LEN, valores que serao passados como parametro
** char    *ft_substr(char const *s, unsigned int start, unsigned int len)
**
*/

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!(s))
		return (NULL);
	if ((start >= ft_strlen(s)) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

>>>>>> ft_strjoin <<<<<<

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen((char *)s1);
		len2 = ft_strlen((char *)s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

>>>>>> ft_strtrim <<<<<<

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen((char *)s1);
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	newstring = ft_substr((char*)s1, 0, size_s + 1);
	return (newstring);
}

>>>>>> ft_split <<<<<<

#include "libft.h"

static int			ft_nbw(const char *str, char c)
{
	int word;

	word = 0;
	if (*str != c && *str)
	{
		str++;
		word++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				word++;
		}
		str++;
	}
	return (word);
}

static int			ft_ln(const char *str, char c)
{
	int count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static void			*is_free(char **spt)
{
	int		i;

	i = 0;
	while (spt[i])
	{
		free(spt[i++]);
	}
	free(spt);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	int			j;
	int			i;
	char		**spt;

	j = 0;
	i = 0;
	if (!s || (!(spt = (char **)malloc(sizeof(char *) * (ft_nbw(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(spt[j] = (char *)malloc(sizeof(char) * (ft_ln(s, c) + 1))))
				return (is_free(spt));
			while (*s && *s != c)
				spt[j][i++] = (char)*s++;
			spt[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	spt[j] = NULL;
	return (spt);
}

>>>>>> ft_itoa <<<<<<

#include "libft.h"

static int		count_len(int nbr)
{
	int				count;
	unsigned int	unbr;

	if (nbr == 0)
		return (1);
	count = 0;
	unbr = nbr;
	if (nbr < 0)
	{
		count++;
		unbr = -unbr;
	}
	while (unbr > 0)
	{
		unbr /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				is_negative;
	unsigned int	unbr;

	len = count_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	is_negative = 0;
	unbr = n;
	if (n < 0)
	{
		is_negative = 1;
		str[0] = '-';
		unbr = -n;
	}
	len--;
	while (len >= (is_negative ? 1 : 0))
	{
		str[len] = unbr % 10 + '0';
		unbr /= 10;
		len--;
	}
	return (str);
}

>>>>>> ft_strmapi <<<<<<

#include "libft.h"

int		ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*to_return;
	unsigned int	aux;
	unsigned int	s_len;

	s_len = ft_strlen((char*)s);
	aux = 0;
	if (!(to_return = (char*)malloc(s_len * sizeof(char))))
		return (0);
	while (s[aux])
	{
		to_return[aux] = (*f)(aux, s[aux]);
		aux++;
	}
	to_return[aux] = '\0';
	return (to_return);
}
>>>>>> ft_putchar_fd <<<<<<

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

>>>>>> ft_putstr_fd <<<<<<

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
	
		return ;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}

>>>>>> ft_putendl_fd <<<<<<

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	ft_putchar_fd('\n', fd);
}

>>>>>> ft_putnbr_fd <<<<<<

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

X------------------Bonus Functions------------------X

Sources: 
https://www.learn-c.org/en/Linked_lists
https://www.geeksforgeeks.org/linked-list-set-1-introduction/

Data Structures Full Tutorial: https://www.youtube.com/watch?v=RBSGKlAvoiM



>>>>>> ft_lstnew <<<<<<

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

>>>>>> ft_lstadd_front <<<<<<

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (*alst && new)
	{
		ptr = *alst;
		new->next = ptr;
		*alst = new;
	}
}

>>>>>> ft_lstsize <<<<<<

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

>>>>>> ft_lstlast <<<<<<

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

>>>>>> ft_lstadd_back <<<<<<

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (alst && *alst)
	{
		ptr = *alst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
>>>>>> ft_lstdelone <<<<<<

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
		lst = 0;
	}
}

>>>>>> ft_lstclear <<<<<<

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur;
	t_list *nxt;

	if (lst && *lst && del)
	{
		cur = *lst;
		while (cur)
		{
			nxt = cur->next;
			ft_lstdelone(cur, del);
			cur = nxt;
		}
		*lst = NULL;
	}
}

>>>>>> ft_lstiter <<<<<<

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

>>>>>> ft_lstmap <<<<<<

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	if (!(dst = ft_lstnew(f(lst->content))))
		return (NULL);
	first = dst;
	while (lst)
	{
		if (lst->next)
		{
			if (!(dst->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&first, del);
				return (0);
			}
			dst = dst->next;
		}
		lst = lst->next;
	}
	dst->next = NULL;
	return (first);
}
