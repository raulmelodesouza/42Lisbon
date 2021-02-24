********************************************************* C00 *********************************************************

------------------------------------Exercicio 00------------------------------------

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:50:19 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/11 11:11:30 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(void)
{
	int c;

	c = 'a';
	ft_putchar(c);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


------------------------------------Exercicio 01------------------------------------

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:56:12 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/12 09:33:40 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char a;

	a = 'a';
	while (a <= 'z')
	{
		ft_putchar(a);
		a++;
	}
}


int main ()
{
	ft_print_alphabet();
	return (0);
}


------------------------------------Exercicio 02------------------------------------


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:56:12 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/12 09:33:40 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char a;

	a = 'a';
	while (a <= 'z')
	{
		ft_putchar(a);
		a++;
	}
}

------------------------------------Exercicio 03------------------------------------

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:16:54 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/12 09:47:05 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char num;

	num = '0';
	while (num <= '9')
	{
		ft_putchar(num);
		num++;
	}
}

int		main(void)
{
	ft_print_numbers();
	return (0);
}


------------------------------------Exercicio 04------------------------------------

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:38:39 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/12 09:53:27 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		ft_putchar('P');
	}
	else
	{
		ft_putchar('N');
	}
}


------------------------------------Exercicio 05------------------------------------

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:04:40 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/12 09:54:51 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb(void);

int		main(void)
{
	ft_print_comb();
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				ft_display(a, b, c);
				c++;
			}
			b++;
			c = b + 1;
		}
		a++;
		b = a + 1;
		c = b + 1;
	}
}


------------------------------------Exercicio 06------------------------------------

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:07:57 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/11 14:15:38 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb2();

int		main(void)
{
	ft_print_comb2();
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(char a, char b)
{
	ft_putchar((char)a / 10 + '0');
	ft_putchar((char)a % 10 + '0');
	ft_putchar(' ');
	ft_putchar((char)b / 10 + '0');
	ft_putchar((char)b % 10 + '0');
}

void	ft_condition(int a, int b)
{
	if (!(a == 98 && b == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			ft_display(a, b);
			ft_condition(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}



------------------------------------Exercicio 07------------------------------------


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:59:18 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/12 10:00:03 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);

int		main(void)
{
	int nb;

	nb = 2552;
	ft_putnbr(nb);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
}



------------------------------------Exercicio 08------------------------------------

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:58:58 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/01/11 17:41:04 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>




********************************************************* C01 *********************************************************

------------------------------------Exercicio 00------------------------------------

#include <unistd.h>
#include <stdio.h>

void    ft_ft   (int *nbr)
{
    *nbr = 42;
}
//Entregar somente o conteudo acima, funcao MAIN usada para testes!
int main ()
{
    int a;
    int *ptr;

    a = 10;
    ptr = &a;

    printf("%d\n", a);
    ft_ft (ptr);
    printf("%d\n", a);
}
------------------------------------Exercicio 01------------------------------------

#include <unistd.h>
#include <stdio.h>

void    ft_ultimate_ft(int ********nbr);

int main (void)
{
    int nbr;
    int *ptr;
    int **ptr2;
    int ***ptr3;
    int ****ptr4;
    int *****ptr5;
    int ******ptr6;
    int *******ptr7;
    int ********ptr8;

    nbr = 10;
    ptr = &nbr;
    ptr2 = &ptr;
    ptr3 = &ptr2;
    ptr4 = &ptr3;
    ptr5 = &ptr4;
    ptr6 = &ptr5;
    ptr7 = &ptr6;
    ptr8 = &ptr7;

    printf("%d\n", nbr);
    ft_ultimate_ft(ptr8);
    printf("%d\n", nbr);
}

//Entregar somente o conteudo abaixo, funcao MAIN usada para testes!
void    ft_ultimate_ft(int *********nbr)
{
    *********nbr = 42;
}

------------------------------------Exercicio 02------------------------------------

#include <stdio.h>
#include <unistd.h>

void    ft_swap(int *a, int *b);


int main (void)
{
    int x;
    int y;
    int *a;
    int *b;

    x = 10;
    y = 15;
    a = &x;
    b = &y;

    printf("%d\n", *a);
    printf("%d\n", *b);

    ft_swap(a, b);

    printf("%d\n", *a);
    printf("%d\n", *b);
}
//Entregar somente o conteudo abaixo, funcao MAIN usada para testes!
void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

------------------------------------Exercicio 03------------------------------------

#include <stdio.h>
#include <unistd.h>

void    ft_div_mod (int a, int b, int *div, int *mod);

int main ()
{
    int a;
    int b;
    int *div;
    int *mod;

    a = 49;
    b = 10;
    div = &a;
    mod = &b;

    ft_div_mod (a, b, div, mod);

    printf("%d\n", *div);
    printf("%d\n", *mod);
    return (0);
}
//Entregar somente o conteudo abaixo, funcao MAIN usada para testes!
void    ft_div_mod (int a, int b, int *div, int *mod)
{
    *div = (a / b);
    *mod = (a % b);
}
------------------------------------Exercicio 04------------------------------------

#include <stdio.h>
#include <unistd.h>

void    ft_ultimate_div_mod (int *a, int *b);

int main (void)
{
    int a;
    int b;
    int *pa;
    int *pb;

    a = 49;
    b = 10;
    pa = &a;
    pb = &b;

    printf ("Valor de A antes: %d\n", a);
    printf ("Valor de B antes: %d\n", b);
    ft_ultimate_div_mod(pa, pb);
    printf ("Valor de A depois: %d\n", a);
    printf ("Valor de A depois: %d\n", b);

}

void    ft_ultimate_div_mod(int *a, int *b)
{
    int tempA;
    int tempB;
    tempA = *a;
    tempB = *b;
    *a = tempA / tempB;
    *b = tempA % tempB;
}

------------------------------------Exercicio 05------------------------------------

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void    ft_putstr (char *s);

int main(void)
{
    char *str; // String jah sao considerados ponteiros!
    str = "Raul";
    ft_putstr(str);

}

void    ft_putchar(char c)
{
    write (1, &c, 1);

}

void    ft_putstr (char *s)
{
    int count;

    count = 0;
    while (s[count])//Enquanto tiverem espacos ocupados no array
    {
        ft_putchar(s[count]);
        count++;
    }
}
------------------------------------Exercicio 06------------------------------------
#include <unistd.h>
#include <stdio.h>

int    ft_strlen(char *str);

int main(void)
{
    int qtd;

    qtd = 0;
    char *str; // String ja sao ponteiros
    str = "Raul Melo de Souza"; // Quantidade eh de 18
    qtd = ft_strlen(str); // Quantidade recebe a quantidade de caracteres contado na funcao abaixo
    printf ("%d\n", qtd); // Exibe a quantidade de caracteres
}
//Apenas fazer upload do conteudo abaixo, funcao main utilizada para testes apenas
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


------------------------------------Exercicio 07------------------------------------

#include<stdio.h>

void    ft_rev_int_tab(int *tab, int size);

int main()
{
    int size; 
    int tab[5]; // Definicao do array  
    int count; // contador

    size = 5;
    count = 0;
    while (count < size)
    {
        tab[count] = size - count;
        printf("%d: %d\n", count + 1, tab[count]);
        count++;
    }
    ft_rev_int_tab(tab, size);
    count =0;
    while (count < size)
    {
        printf("%d: %d\n", count + 1, tab[count]);
        count++;
    }
    return 0;
}

void    ft_rev_int_tab(int *tab, int size)
{
    int temp;
    int count;

    count = 0;
    size = size - 1; //Embora o tamanho do array seja 5, comeca na posicao 0, entao termina em 4, por isso subtraimos antes da repeticao
    while (count < size) // While 0 < 5
    {
        temp = tab[count]; //temp recebe o valor de tab 0, ou seja, recebe 5
        tab[count] = tab[size];//tab[0] recebe o valor de tab[size(5)], ou seja, recebe 1
        tab[size] = temp;//tab[5] recebe o valor no temp, ou seja, recebe 5;
        count++;//count passa de 0 para 1
        size--;//size passa de 5 para 4
    }

}

------------------------------------Exercicio 08------------------------------------

#include <stdio.h>

void    ft_sort_int_tab(int *tab, int size);

int    main()
{
    int size; 
    int tab[5] = {1, 3, 5, 2, 8}; // Definicao do array e atribuicao de valores
    int count; // contador

    size = 5; // Tamanho do array pra passar pra funcao
    count = 0;
    while (count < size) // Exibindo o array origianl antes da modificacao
    {
        printf("%d: %d\n", count + 1, tab[count]);
        count++;
    }

    ft_sort_int_tab(tab, size); // Chamando a funcao e passando os parametros, o tab e seu tamanho
    
    count =0; // Devolvendo o valor do count a 0 para exibir de novo
    
    while (count < size) // Exibindo o array modificado
    {
        printf("%d: %d\n", count + 1, tab[count]);
        count++;
    }
    return 0;
}
//Apenas entregar o conteudo abaixo, o main acima foi usado apenas para testes
void    ft_sort_int_tab(int *tab, int size)
{
    int a; // Comparador de valores com o tamanho
    int b; // Comparador de valores com o tamanho
    int temp; // Variavel temp para pegar o maior valor

    a = 0 ;
    while (a < size) // Enquanto A (0) for menor que 5
    {
        b = 0 ;
        while (b < size) //Enquanto B(0) for menor que 5
        {
            if (tab[b] >= tab[a]) // Se tab[0] >= tab[0]
            {
                temp = tab[b]; // Temp tecebe o valor de B caso B seja maior que A
                tab[b] = tab[a]; // B tecebe o valor de A, que era menor
                tab[a] = temp; // A recebe o valor de temp, ou seja, o maior valor do array na posicao 0
            }
            b++;
        }
        a++;
    }
}

********************************************************* C02 *********************************************************

------------------------------------Exercicio 00------------------------------------


#include <stdio.h>

char    *ft_strcpy (char *dest, char *src)
{
    int count; // Contador para as posicoes do array

    count = 0; // iniciado em 0 
    while (src[count] != '\0') // Enquanto o valor souce "Testando" tiver um retorno
    {
        dest[count] = src[count]; // dest[0] recebe o valor de src[0]
        count++; // incremento do contador para o proximo bloco do array
    }
    dest[count] = src[count]; // a funcao sera executada enquanto o array retornar um valor, portando aqui definimos como 0
    				   // tambem poderia ser src[count] = 0 ou = NULL ou '\0'
    return (dest);
}

int main (void)
{
    char src[] = "testando"; // Valor sera ira substituir o valor de dest
    char dest[] = "antes"; // Valor que sera substituido

    printf("%s\n", dest); // exibindo antes para mostrar o valor atual
    ft_strcpy(dest, src); // Chamando a funcao para alteracao
    printf("%s\n", dest); // exibindo o valor depois da modificacao
    return(0);

}


------------------------------------Exercicio 01------------------------------------
#include <string.h>
#include <stdio.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n) // unsigned int eh um int sem sinal (+ ou -), sempre positivos
{
    unsigned int count;
    count = 0;

    while (src[count] != '\0' && count < n)
    {
        dest[count] = src[count];
        count++;
    }
    while (count < n)
    {
        dest[count] = '\0';
        count ++;
    }
    return (dest);
}

int main (void)
{
    char src[] = "Raul Souza"; // Valor sera ira substituir o valor de dest
    char dest[] = "Lucas Souza"; // Valor que sera substituido

    printf("%s\n", dest); // exibindo antes para mostrar o valor atual
    ft_strncpy(dest, src, 4); // Chamando a funcao para alteracao
    printf("%s\n", dest); // exibindo o valor depois da modificacao
    return(0);
}

------------------------------------Exercicio 02------------------------------------

int	ft_str_is_alpha(char *str) // Verificar se a entrada de string esta no alfabeto e retornar ou 0 ou 1
{
	int		count; // contador de string
	char	temp; // Variavel apra receber o valor atual da posicao da string

	count = 0;
	if (!str)
	{
		return (1);
	}
	while (str[count] != '\0')
	{
		temp = str[count];
		if (!((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))) // Se !(temp >= a/A e <= z/Z)
		{
			return (0);
		}
		count++;
	}
	return (1);
}

------------------------------------Exercicio 03------------------------------------

	int	ft_str_is_numeric(char *str) // Se a string tiver soh numeros retorna
{
	int		count;
	char	var;

	count = 0;
	if (!str)
	{
		return (1);
	}
	while (str[count] != '\0')
	{
		var = str[count];
		if (!(var >= '0' && var <= '9')) // Nao (Se var >= 0 e <= 9) Se nao estiver no padrao entra parentesis 
		{
			return (0); // Retorno 0, pois nao contem apenas digitos
		}
		count++;
	}
	return (1); // Retorno 1 caso soh tenha digiutos
}

------------------------------------Exercicio 04------------------------------------

int		ft_str_is_lowercase(char *str) // Se for caracter minusculo retorna 1, se nao retorna 0
{
	int		count; //contador de posicoes
	char	var; // variavel que recebera o CHAR em cada posicao da string

	count = 0;
	if (!str)
	{
		return (1);
	}
	while (str[count] != '\0')
	{
		var = str[count];
		if (!(var >= 'a' && var <= 'z')) //se o CHAR contido em VAR nao estiver entre a e z, retorna 0 
		{
			return (0);
		}
		count++;
	}
	return (1); // 
}

------------------------------------Exercicio 05------------------------------------


int	ft_str_is_uppercase(char *str)
{
	int count;

	count = 0;
	if (str[count] == '\0')
	{
		return (1);
	}
	while (str[count] != '\0')
	{
		if (str[count] < 'A' || str[count] > 'Z')
		{
			return (0);
		}
		count++;
	}
	return (1);
}

------------------------------------Exercicio 06------------------------------------

int	ft_str_is_printable(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{	// Se o caracter for menor que 32 ou maior que 126
		if (str[count] < 32 || str[count] > 126) // Na tabela ASCII os caracteres printaveis estao entre 32 e 126
		{
			return (0);
		}
		count++;
	}
	return (1);
}

------------------------------------Exercicio 07------------------------------------

char	*ft_strupcase(char *str)
{
	int count;

	count = 0; // contador de posicoes
	while (str[count] != '\0') // enquanto for diferente de nulo
	{
		if (str[count] >= 'a' && str[count] <= 'z')
		{
			str[count] = str[count] - 32;
		}
		count++;
	}
	return (str);
}

------------------------------------Exercicio 08------------------------------------

char	*ft_strlowcase(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 'A' && str[count] <= 'Z')
		{
			str[count] = str[count] + 32; // Na tabela ASCII, a posicao de um caractere minusclo esta 32 numeros a frente do original
		}
		count++;
	}
	return (str);
}


------------------------------------Exercicio 09------------------------------------

char	*tratamento(char *str) // funcao que transforma todos os caracteres em minusculo 
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 'A' && str[count] <= 'Z')
		{
			str[count] = str[count] + 32;
		}
		count++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int count;

	count = 0;
	tratamento(str); // chamando a funcao para transformar tudo em minusculo
	while (str[count] != '\0') // Enquanto o conteudo na posicao count da string nao seja nulo
	{
		if (str[0] >= 'a' && str[0] <= 'z') // se estiver entre a e z minusculos na posicao 0, onde tudo comeca
		{
			str[0] = str[0] - 32; //Por sabermos que a posicao 0 contema  primeira palavra da frase, ja transformamos em uppercase
		}
		else if (str[count] == 32 || str[count] == 43 || str[count] == 45) // Se a posicao conter respectivamente um espaco, + e -
		{
			if (str[count + 1] >= 'a' && str[count + 1] <= 'z') //Como temos que transformar em maiusculo o caracter seguinte ao espaco/+/-m entao count +1
			{
				str[count + 1] = str[count + 1] - 32; // caracter seguinte a espaco/+/- vira maiusculo
			}
		}
		count++; // aumento do contator para seguir a funcao enquanto o valor nao seja nulo
	}
	return (str); // retornar o valor final alterado da string
}

------------------------------------Exercicio 10------------------------------------


//Uma unsigned int usa todo o espaco disponivel numa variavel INTEGER, porem soh com numeros positivos
// Normalmente uma int tem -2,147,483,647 a 2,147,483,647 / Porem uma unisgned int tem de 0 a 4,294,967,294
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((src[i]) && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (j);
}

------------------------------------Exercicio 11------------------------------------

#include <unistd.h>

void	put_char(char a)
{
	write(1, &a, 1);
}

void	hexa(unsigned char c) // funcao para transformar os caracteres aem hexadecimal
{
	put_char(92); // Na tabela ASCII o / eh representado por um 92
	put_char("0123456789abcdef"[c / 16]); // "0123456789abcdef" converte em base 16;
	put_char("0123456789abcdef"[c % 16]); // "0123456789abcdef" converte em base 16;
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!(32 <= (*str) && (*str) <= 126)) //se a string estiver entre posicao 32 e 126, ou seja printaveis
		{
			hexa(*str); // chama a funcao hexa para converter o '/' em
		}
		else
		{
			write(1, str, 1);
		}
		++str;
	}
}

------------------------------------Exercicio 12------------------------------------
  
  empty


********************************************************* C03 *********************************************************

------------------------------------Exercicio 00------------------------------------

#include <unistd.h>

int ft_strcmp (char *s1, char *s2)
{
    int count;

    count = 0;
    while (s1[count] != '\0' && (s1[count]) == s2[count])
    {
        count++;
    }
    return (s1[count] -s2[count]);
}

// Nao submeter a funcao main, usada apenas para restes
int     main(void)
{
    char str1[] = {"Lucas"}; // Definicao de string com 5 caractere
    char str2[] = {"Raul"}; // Definincao de string com 4 caracteres
  

    if (ft_strcmp(str1, str2) == 0) // Se o resultado da funcao for 0
    {
        write (1, "String 1 = String 2", 19); // String sao iguais
    }
    else if (ft_strcmp (str1, str2) > 0) // Se o resultado da funcao for maior que 0 entao a string 1 eh maiior
    {
        write(1, "String 1 > String 2", 19);
    }
    else // Se o resultado for menor que zero, entao a string 2 eh maior
    {
        write(1, "String 1 < String 2", 19);
    }
    return (0);
}

------------------------------------Exercicio 01------------------------------------

#include <unistd.h>
//Funcao strncmp compara a primeira e a segunda string, porem se o tamanho for igual, a comparacao eh baseada no valor da tabela ASCII
// Entao definimos a quantidade de caracteres a serem comparados, por exemplo, soh os 4 primeiros
// Com base na tabela ASCII veremos se sao iguais, um maior ou menor que o outro

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int count;

    count = 0;
    if (n == 0)
        return (0);
    while (s1[count] == s2[count] && s1[count] != '\0' 
    	&& s2[count] != '\0' && count + 1< n)
        count++;
    	if (s1[count] == s2[count] || n == 0)
    	{
    		return (0);
    	}
    return (s1[count] - s2[count]);
}
/* ************************************************************************** */
/* ************************************************************************** */

int     main(void)
{

   char str1[] = {"Raul"};
   char str2[] = {"Raul"};
   int qtd;
   qtd = ft_strncmp(str1, str2, 5);
  

   if (ft_strncmp(str1, str2, 5) == 0)
      printf ("Nao existe diferenca de caracteres\n");
   else
        
      printf ("Quantidade de caracteres diferentes: %d", qtd);

   return (0);
}
------------------------------------Exercicio 02------------------------------------


char	*ft_strcat(char *dest, char *src) // Funcao que copia o source no destino, porem sem apagar o conteudo do destino
{
	int count; // Definimos o valor do contador 
	int lenght; // Definimos um tamanho para ser equivalente ao contador

	count = 0;
	lenght = 0;
	while (dest[count] != '\0')
	{
		lenght++; // Aqui contaremos o tamanho total do destino
		count++; // Contador 
	}
	count = 0; // Ja usamos o contador para definir o tamanho total de lenght, agora resetamos o contador
	while (src[count] != '\0') // Enquanto o source nao for nulo
	{
		dest[lenght + count] = src[count]; // O destino, na posicao lenght+count recebe o conteudo do source
		count++; //Ao somar o tamanho (lenght) ao contador 0, quer dizer que a string sera copiada a partir do momento que acaba a primeira
	}
	dest[lenght + count] = '\0'; // Finalizamos a variavel
	return (dest); //retornamos 
}

void ft_putchar (char c)
{
    write(1, &c, 1);
}

void    ft_putstr (char *s)
{
    int count;

    count = 0;
    while (s[count])
    {
        ft_putchar(s[count]);
        count++;
    }
}

int  	main ( void )
{
	char 	origem[] = { "Raul\n" };
	char 	destino[ 20 ] = { "Hello, "};

	ft_strcat (destino, origem); // Aqui chamamos a funcao e o "destino" ira receber o conteudo da "origem"
	ft_putstr(destino); // Aqui chamados "destino" depois de ter sido executado pela funcao
	return (0);
}

------------------------------------Exercicio 03------------------------------------

#include <unistd.h>

void  ft_putchar(char c) 
{
  write(1, &c, 1);
}

void  ft_putstr(char *str)
{
  int i;

  i = 0;
  while (*(str + i))
    i++;
  write(1, str, i);
}

char  *ft_strncat(char *dest, char *src, unsigned int nb)  
{
  unsigned int count;
  int lenght;

  count = 0;
  lenght = 0;
  while (dest[lenght]) // Enquanto a cedula do destino nao for vazia, incrementar o length
    lenght++; //Aumento no tamanho
  while (count < nb && src[count]) // Enquanto o contador for menor que o numero passado e a cedula do source nao for vazia
  {
    dest[lenght] = src[count]; // Comeca a copiar os caraacteres do source no fim do dest
    lenght++; //Incremento para ir pra proxima cedula do array
    count++; // Incremento do contador
  }
  dest[lenght] = '\0';              
  return (dest);                  
}

int   main(void)

{
  char  src[] = {"Raul Melo\n"}; // Criacao da string source
  char  dest[20] = {"Hello "}; //Criacao do destino, que recebera o source

  ft_strncat(dest, src, 4); // Passamos os parametros e a quantidade de numeros que queremos copiar, por ser soh 4 nao pegara Raul Melo, soh Raul
  ft_putstr(dest); // Exibe a nova string depois de modificada
  return (0);                   
}

------------------------------------Exercicio 04------------------------------------

#include <stdio.h>

char    *ft_strstr(char *str, char *to_find) // A funcao identifica se ha uma substring em comum contida na string principal
// Por exemplo se a string for SOBREMESA e o to_find for MESA, se MESA existir na string SOBREMESA, sera retornado.
{
    int i; // contador para a string
    int j; // contador para o to_find

    i = 0;
    if (to_find[0] == '\0') // Se nao houver palavra a ser buscada
        return (str); // retorna ela mesma, que no caso eh nulo
    while (str[i]) // enquanto a string nao for vazia, executa o comando abaixo
    {
        j = 0;
        while (str[i + j] == to_find[j]) /* Contador j = 0 para comecar da posicao zero da string to_find while (str [i + j] == to_find [j]) 
        								/* Se str tiver o mesmo caracter  que o caracter nulo em to_find */

            if (to_find[j + 1] == '\0') // então iniciamos um loop que irá verificar se a célula de rastreamento da string to_find é o fim
                return (str + i);
            j++;
        } /* se a célula for o fim, encerre a função e retorne o endereço da célula da primeira correspondência */
		/* Se a célula não for o fim, verificamos se há mais caracteres em str como em to_find.
		Aumente o contador j apontando para a próxima célula do array str e a próxima célula do array to_find e verifique-os */
        i++;
    }
    return (( void *) 0 );
}

int     main(void)
{
    char *haystack;
    char *needle;
    char *result_c;


    haystack = "Dia de prova"; // Frase original
    needle = "prova"; // Parte da frase que queremos
    result_c = ft_strstr(haystack, needle);
    printf("Endereco de alocacao: %p\n", result_c); // Exibindo o endereco onde estao alocados os resultados
    printf("String original  : %s$\n", haystack);
    printf("O que queriamos encontrar  : %s$\n", result_c);

}

------------------------------------Exercicio 05------------------------------------

int		ft_strlen(char *str) //Usando a funcao strlen para descobrir o tamanho da string e retorna-lo abaixo
{
	int		i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size) // funcao quase identica a strcat, porem retorna o total de caracteres das duas strings somadas 
{
	unsigned int		i; // Contador
	unsigned int		len; // tamanho da string

	i = 0;
	len = 0;
	while (dest[len] && len < size) // Enquanto dest[len] for menor que o tamanho definido
	{
		len++; // descobrindo o tamanho total
	}
	i = len; // Atribuindo o valor total ao contador
	while (src[len - i] && len + 1 < size) // Enquanto a string na posicao tamanho - contador e tamanho forem menors que o size
	{
		dest[len] = src[len - i]; // String dest posicao tamanho recebe source tamanho - contador
		len++; // incremento do tamanho
	}
	if (i < size) // Se o contador for menor que o tamanho da string
		dest[len] = '\0'; // recebe nulo para encerrar a funcao
	return (i + ft_strlen(src));  // contador + o tamanho da string
}


********************************************************* C04 *********************************************************

------------------------------------Exercicio 00------------------------------------



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

------------------------------------Exercicio 01------------------------------------

void    ft_putchar(char c)
{
    write (1, &c, 1);

}

void    ft_putstr (char *s)
{
    int count;

    count = 0;
    while (s[count])//Enquanto tiverem espacos ocupados no array
    {
        ft_putchar(s[count]);
        count++;
    }
}

------------------------------------Exercicio 02------------------------------------


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
}

------------------------------------Exercicio 03------------------------------------



#include <unistd.h>
#include <stdio.h>

int	aux_space(char c) // Verificador de espacos/caracteres especiais, caso estejam, nesses, serao saltados
{
	if (c == '\t' || c == '\n' || c == '\r' ||
			c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int positive;
	int result;
	int count;

	positive = 1;
	count = 0;
	result = 0;
	while (aux_space(*str))
		str++;
	while (*str == '-' || *str == '+') 
	{
		if (*(str++) == '-')
			positive *= -1;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result *= 10;
			result += (*(str++) - '0');
		}
		else
			return (result * positive);
	}
	return (result * positive);
}


int     main (void)
{
    int         i;                          /* declare a variable that will store the number we got */
    char    n[] = { "---+--+1234ab567" };            /* create an array of characters from which we will receive the number 54321 */

    i = ft_atoi (n);                     /* initialize the variable - we call the function to get the number from the string
                                        ** giving it the address of an array of characters (strings) as arguments. The function will get from string
                                        ** number and return it to us in variable i */
    printf("%d", i);                       /* Let's check if it worked. Let's print this number */
    return ( 0 );
}

------------------------------------Exercicio 04------------------------------------

#include <unistd.h>


void  ft_putstr(char *str)
{
  int i;

  i = 0;
  while (*(str + i))
    i++;
  write(1, str, i);
}

int   ft_nbrlen(char *str)
{
  int count;
  count = 0;
  while (str[count])
    count++;
  return (count);
}

int   ft_baseistrue(char *str) // Verificar se a base passada eh valida ou nao
{
  int count; 
  int countb;
  count = 0;
  if (ft_nbrlen(str) <= 1) // Chamamos a funcao strlen para imprimir todas as cedulas da string e se for menor que 1, a base jah eh invalida de acordo com o enunciado
    return (0); // Retorna zero pois base menor que 1 eh invalida
  while (str[count])  // Enquanto a string [] nao for nula
  {
    if (!(str[count] >= 'A' && str[count] <= 'Z')
        && !(str[count] >= 'a' && str[count] <= 'z')
        && !(str[count] >= '0' && str[count] <= '9'))  // Se nao estiver nas condicoes estipuladas
      return (0); // Retorna 0 pois novamente eh invalida
    countb = count + 1; // contador = contador + 1
    while (str[countb]) // Enquanto string countb nao for nulo
    {
      if (str[countb] == str[count]) // Se a string countb for igual a string contador
        return (0); // retorna zero
      countb++; //incremento
    }
    count++; // incremento
  }
  return (1); // Se nao estiver em nenhum dos casos acima, retornara 1, pois eh valida, em quaisquer casos acima eh invalida
}

void  ft_putnbr_base(int nbr, char *base)
{
  int aux;
  if (!ft_baseistrue(base)) // Chama a funcao baseistrue, se nao for true
    return ; // retorna nulo, pois a condicao de ser verdadeira nao foi cumprida
  aux = ft_nbrlen(base); // Variavel auxiliar recebe o valor da nossa string
  if (nbr <= -2147483648) // Se o numero for menor ou igual que o valor mais baixo de uma variavel INTEGER
  {
    write(1, "-", 1); // Escreve - na frente, indicando negativo
    ft_putnbr_base((-(long int)nbr) / aux, base); // Numero dividido pela base passada pelo usuario
    ft_putnbr_base((-(long int)nbr) % aux, base); // Mod do numero dividido pela base
  }
  else if (nbr < 0) // Se o numero for menor que zero
  {
    write(1, "-", 1); // escreve negativo na frente
    ft_putnbr_base(-nbr, base); // Parametro passado com valor negativo "-nbr"
  }
  else if (nbr < aux) //Se  numero for menor que a variavel aux, que recebeu o valor da string
  {
    write(1, &base[nbr], 1); //exibi a base do numero apssado
  }
  else
  {
    ft_putnbr_base(nbr / aux, base); // Se nenhuma das condicoes acima for atendida, recursao na propria funcao - divisao
    ft_putnbr_base(nbr % aux, base);  // Se nenhuma das condicoes acima for atendida, recursao na propria funcao - mod
  }
}

int     main(void)
{
    int     nbr;        /* Обьявляем переменную для хранения числа для печати */
    char    *base;        /* Обьявляем указатель для хранения нужной нам системы счисления */
 
    nbr = 876;          /* Инициализируем ее записав туда число для конвертирования */
    base = "01";        /* Инициализируем указатель для хранения нужной нам системы счисления записав туда нужную нам систему счисления */
    ft_putnbr_base(nbr, base);  /* Отправляем число для печати и нужную нам систему счисления в функцию по печати числа в нужной системе счисления */
    ft_putstr(" - binary\n"); /* Печатаем описание */

    base = "0123456789ABCDEF";  /* Перезаписываем указатель на адресс новой строки записав туда новую систему счисления */
    ft_putnbr_base(nbr, base);  /* Отправляем число для печати и новую систему счисления в функцию по печати числа в новой системе счисления */
  ft_putstr(" - hex\n");    /* Печатаем описание */
  
    return (0);         /* Завершаем функцию и возвращаем ноль */
}

------------------------------------Exercicio 05------------------------------------


#include <stdio.h>

int   ft_aux_space(int c)
{
  if ((c == ' ' || c == '\t' || c == '\n'
  || c == '\v' || c == '\f' || c == '\r'))
    return (1);
  return (0);
}

int   ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int   ft_check_base(char *base, int base_len)
{
  int i;
  int j;

  i = 0;
  while (i < base_len)
  {
    j = i + 1;
    while (j < base_len)
    {
      if (base[i] == base[j])
        return (1);
      j++;
    }
    if (base[i] == '-' || base[i] == '+')
      return (1);
    i++;
  }
  return (0);
}

int   ft_find_base(char c, char *base)
{
  int i;

  i = 0;
  while (base[i] && base[i] != c)
    i++;
  return (i);
}

int   ft_atoi_base(char *str, char *base)
{
  int base_len;
  int res;

  res = 0;
  base_len = ft_strlen(base);
  if (base_len < 2)
    return (0);
  if (ft_check_base(base, base_len))
    return (0);
  while (ft_aux_space(*str))
    str++;
  while (ft_find_base(*str, base) < base_len)
  {
    res = res * base_len - ft_find_base(*str++, base);
  }
  return (-res);
}

int     main(void)
{
  char  *base;
  char  *str;

  str = "12fdb3";
  base = "0123456789ABCDEF";
  printf("%d", ft_atoi_base(str, base)); /* Отправляем в функцию нужную нам строку с нужным числом в одном аргументе и другую строку с описанием базового типа этого числа
                    ** для преобразования числа из имеющейся системы счисления в десятичную систему счисления.
                    ** А возвращаемый результат отправляем на печать в функцию печати числа */
    return (0);             /* Завершаем функцию и возвращаем ноль */
}


********************************************************* C05 *********************************************************

------------------------------------Exercicio 00------------------------------------

#include <stdio.h>

int ft_iterative_factorial(int nb)
{
  int fatorial;
  int count;

  fatorial = 1;
  count = 1;
  if (nb < 0 || nb > 12) // Como o enunciado especificou que se tratam de numeros inteiros, deve ser ateh 12, pois !13 eh maior que o valor de um integer
  {
    return (0);
  }
  else if (nb == 0 || nb == 1) // 0! ou 1! sao sempre igual a 1
  {
    return (1);
  }
  else 
  {
    while (count <= nb)
    {
      fatorial = fatorial * count; // fatorial = fatorial * count ex: fatorial = 1 * 1, fatorial = 2 *1, etc.. 
      count++;
    }
    return (fatorial);
  }
}

int main ()
{
  int nb;
  int fatorial;

  nb = 1;
  fatorial = ft_iterative_factorial (nb);
  printf("Fatorial de %d = %d", nb, fatorial); 
  printf ("\n");
  }

------------------------------------Exercicio 01------------------------------------

#include <stdio.h>

int ft_iterative_factorial(int nb)
{
  int fatorial;

  fatorial = 1;
  if (nb == 0 || nb == 1)
  {
    return (1);
  }
  else if (nb < 0 || nb > 12)
  {
    return (0);
  }
  else 
  {
    fatorial = nb * (ft_iterative_factorial(nb -1)); // Executando o fatorial ao usar uma funcao recursiva, ou seja, que chama ela mesma
  }
  return (fatorial);
}

int main ()
{
  int nb;
  int fatorial;

  nb = 13;
  fatorial = ft_iterative_factorial (nb);
  printf("Fatorial de %d = %d", nb, fatorial);
  return (0);
}

------------------------------------Exercicio 02------------------------------------
//Condicoes
// 0 power 0 = 1
// Power < 0 = 0;
#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
  int resultado;

  resultado = 1;
  if (power < 0)
  {
    return (0);
  }
  if (power == 0)
  {
    return (1);
  }
  while (power)
  {
  	resultado *= nb;
  	power--;
  } 
  return (resultado);
}

int main ()
{
  int nb;
  int power;
  int resultado;

  nb = 3;
  power = 3;
  resultado = ft_iterative_power (nb, power);
  printf("Potencia de %d = %d", nb, resultado);
  return (0);
}

------------------------------------Exercicio 03------------------------------------
#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
  if (power == 0)
  {
    return (1);
  }
  else if (power < 0)
  {
    return (0);
  }
  else 
  {
    return(nb * (ft_recursive_power(nb, power - 1))); // Retorna o numero multiplicado pela chamada da funcao novamente, soh que dessa vez o power -1
    // Ou seja, a funcao sera repetida ate que o power seja 0, entao retornara 1, antes que chegue a 0 sera executado 3 vezes, no final, 3 * 3 * 3 = 27, que eh o mesmo de 3 ao cubo
  }
}

int main ()
{
  int nb;
  int power;
  int resultado;

  nb = 2;
  power = 3;
  resultado = ft_recursive_power (nb, power);
  printf("Potencia de %d = %d", nb, resultado);
  return (0);
}

------------------------------------Exercicio 04------------------------------------

#include <stdio.h>

int ft_fibonacci(int index)
{
  if (index < 0)
  {
    return (-1);
  }
  else if (index == 0)
  {
    return (0);
  }
  else if(index == 1)
  {
    return(1);
  }
  else 
  {
    return(ft_fibonacci(index - 1) + ft_fibonacci(index - 2)); 
  } // Formula de fibonacci -> Posicao n = (Posicao n - 1) + (Posicao n - 2)
  	//Posicao 2 = (2 - 1) + (2 - 2), logo o elemento na posicao 2 da sequencia de Fibonacci eh 1
}

int main ()
{
  int index;
  int resultado;

  index = 2;
  resultado = ft_fibonacci (index);
  printf("Sequencia de ft_fibonacci na posicao %d = %d", index, resultado); 
  return (0);
}
------------------------------------Exercicio 05------------------------------------
#include <stdio.h>

int ft_sqrt(int nb)
{
	int count;
	count =0;

	while (count * count < nb) // Se o numero multiplicado por ele mesmo for menor que o numero passado
	{
		count++; //incrementados o numero
	}
	if (count * count == nb) // Se o numero multiplicado por ele mesmo for igual ao numero passado
	{
		return (count); //retornamos o valor do contador, pois a raiz quadrada de um numero = numero * numero
	}
	else 
		return (0);
}

int		ft_sqrt(int nb)
{
	int i;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	while (i < nb / i)
		i++;
	if (i == nb / i && nb % i == 0)
		return (i);
	return (0);
}

int main ()
{
  int raizquadrada;
  int resultado;

  raizquadrada = 2;
  resultado = ft_sqrt (raizquadrada);
  printf("Raiz quadrada de %d = %d", raizquadrada, resultado); 
  return (0);
}


------------------------------------Exercicio 06------------------------------------

int		ft_is_prime(int nb)
{ // Numeros primos sao numero que soh tem uma divisao exata, sem resto, ao serem divididos por 1 e por eles mesmo
	int count; // contador 

	if (nb < 2) // Se o numero for menor que 2, ja nao pode ser primo, pois 1 soh se divide por 1
		return (0); // Retorna zero
	count = 2; // Definimos o contador como 2, pois conforme acima, 1 nunca sera primo
	while (count <= nb / count) // Enquanto o contador for menor ou igual que o numero passado dividido pelo contador
	{ // Enquanto 2 <= nb / 2
		if (nb % count == 0) // Se o resto da divisao do numero for igual a zero, encontramos o numero que o divide, que nao eh 1
			return (0);
		else // Se a divisao ainda tiver resto, significa que ainda nao achamos o numero que o divide perfeitamente
			count++; // incrementamos o contador e tentamos novamente com count++
	}
	return (1); // Se nenhuma das condicoes acima for atendida, retorna 1, indicando que o numero eh primo
}

int main ()
{
  int raizquadrada;
  int resultado;

  raizquadrada = 2;
  resultado = ft_sqrt (raizquadrada);
  printf("Raiz quadrada de %d = %d", raizquadrada, resultado); 
  return (0);
}
//Exemplo de numeros primos para teste: 2 ,3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, etc..
------------------------------------Exercicio 07------------------------------------

#include <stdio.h>

int   ft_is_prime(int nb)
{ // Numeros primos sao numero que soh tem uma divisao exata, sem resto, ao serem divididos por 1 e por eles mesmo
  int count; // contador 

  if (nb < 2) // Se o numero for menor que 2, ja nao pode ser primo, pois 1 soh se divide por 1
    return (0); // Retorna zero
  count = 2; // Definimos o contador como 2, pois conforme acima, 1 nunca sera primo
  while (count <= nb / count) // Enquanto o contador for menor ou igual que o numero passado dividido pelo contador
  { // Enquanto 2 <= nb / 2
    if (nb % count == 0) // Se o resto da divisao do numero for igual a zero, encontramos o numero que o divide, que nao eh 1
      return (0);
    else // Se a divisao ainda tiver resto, significa que ainda nao achamos o numero que o divide perfeitamente
      count++; // incrementamos o contador e tentamos novamente com count++
  }
  return (1); // Se nenhuma das condicoes acima for atendida, retorna 1, indicando que o numero eh primo
}

int   ft_find_next_prime(int nb) // Complementaremos a funcao acima para caso o parametro nao seja um numero primo
{
  while (nb <= 2147483647) // Maior valor possivel de um int
  {
    if (ft_is_prime(nb)) // Recursividade, chamamos a funcao is prime de novo 
      {
        return (nb); // Quando achar o numero primo, retorna o NB seguinte que for primo
      }
    nb++; // Se o numero nao for primo, increntamos e o nb e a funcao sera rodada de novo, ate que nb seja o maior valor possivel de int
  }
  return (2147483647);
}

int main ()
{
  int nb;

  nb = 18;
  if (ft_is_prime(nb) == 1)
  {
    printf("Numero %d eh primo", nb); 
  }
  else 
  {
    printf("Numero %d nao eh primo, porem o numero primo seguinte eh %d", nb, ft_find_next_prime(nb));  
  }
  return (0);
}

------------------------------------Exercicio 08------------------------------------
empty

********************************************************* C06 *********************************************************

------------------------------------Exercicio 00------------------------------------

#include <unistd.h>

void ft_putchar (char c)
{
  write (1, &c, 1);
}

void  ft_putchar(char c);

int   main(int argc, char *argv[])
{
  int i;

  i = 0;
  while (argv[0][i] != '\0' && argc)
  {
    ft_putchar(argv[0][i]);
    i++;
  }
  ft_putchar('\n');
  return (0);
}

------------------------------------Exercicio 01------------------------------------

#include <unistd.h>


void  ft_putchar(char c)
{
  write(1, &c, 1);
}

void  ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int main (int argc, char **argv)   /*Argc eh o contador de parametros passados, ja o argv eh um vetor de de parametros armazenados, para que nao seja preciso defini-los ao decorrer da funcao) */
{
  int i;            /* Declare a counter to move from line to line */

  i = 1;           /* Atribuir o valor de 1 ao contador, para que pule a linha zero que tem armazenada o nome do programa, assim ira imprimir os argumentos*/
  if (argc > 1)        /* Verifica se ha alguma outra linha alem do nome do programa nos argumentos, se tiver alguma, comeca a exxecucao */
  {
    while (i < argc)    /* Aqui eh onde "argc" entra em cena, nos ajuda a saber quando acabam as linhas */
    {
      ft_putstr (argv [i]); /* Exibe a string contendo um dos argumentos */
      ft_putchar ('\n'); /* Quebra de linha*/
      i ++;       /* Incremento do contator */
    }
  }
  return (0);         /* funcao terminada */ 
}

------------------------------------Exercicio 02------------------------------------

#include <unistd.h>


void  ft_putchar(char c)
{
  write(1, &c, 1);
}

void  ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int main (int argc, char **argv)   /*Argc eh o contador de parametros passados, ja o argv eh um vetor de de parametros armazenados, para que nao seja preciso defini-los ao decorrer da funcao) */
{
  int i;            /* Declare a counter to move from line to line */

  i = argc - 1;           /* Atribuir o valor de 1 ao contador, para que pule a linha zero que tem armazenada o nome do programa, assim ira imprimir os argumentos*/
  if (argc > 1)        /* Verifica se ha alguma outra linha alem do nome do programa nos argumentos, se tiver alguma, comeca a exxecucao */
  {
    while (i > 0)    /* Aqui eh onde "argc" entra em cena, nos ajuda a saber quando acabam as linhas */
    {
      ft_putstr (argv [i]); /* Exibe a string contendo um dos argumentos */
      ft_putchar ('\n'); /* Quebra de linha*/
      i--;       /* Incremento do contator */
    }
  }
  return (0);         /* funcao terminada */ 
}


------------------------------------Exercicio 03------------------------------------

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_params(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 1;
	if (argc > 1)
	{
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				i = 0;
			}
			i++;
		}
		ft_print_params(argc, argv);
	}
	return (0);
}

********************************************************* C07 *********************************************************

------------------------------------Exercicio 00------------------------------------

#include <stdlib.h>

int		str_length(char *str)
{
	int	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*buff;

	buff = (char*)malloc(sizeof(*src) * str_length(src) + 1);
	if (!buff)
		return (0);
	dest = buff;
	while (*src)
		*buff++ = *src++;
	*buff = '\0';
	return (dest);
}


------------------------------------Exercicio 01------------------------------------

#include <stdlib.h>


int	*ft_range(int min, int max)
{
	int	*range;
	int	*buff;

	if (min >= max)
		return (0);
	range = (int*)malloc(sizeof(min) * (max - min));
	buff = range;
	while (min < max)
		*buff++ = min++;
	return (range);
}

------------------------------------Exercicio 02------------------------------------

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	*buff;

	if (min >= max)
		return (0);
	range = (int*)malloc(sizeof(min) * (max - min));
	if (!range)
		return (0);
	buff = range;
	while (min < max)
		*buff++ = min++;
	return (range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (min >= max)
		return (0);
	if (!*range)
		return (-1);
	return (max - min);
}

------------------------------------Exercicio 03------------------------------------

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (dest[i])
		i++;
	while (src[x])
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	length += ((size - 1) * ft_strlen(sep));
	if ((str = (char *)malloc(sizeof(char) * (length + 1))) == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if ((i + 1) < size)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}

int     main(int argc,char **argv)
{
  char  *str;
  
  if (argc > 2)
  {
    str = ft_strjoin(argc - 1, argv + 1, ".:.");
    ft_putstr(str);
    ft_putchar('\n');
    free(str);
  }
  return (0);
}