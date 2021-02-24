********************************************************* C01 *********************************************************

---Declaracao e atribuicao de um ponteiro

#include <stdio.h>

int main(void)
{
	int a;
	int *ponteiro 
	// Para declarar um ponteiro devemos colocar *

	ponteiro = &a; 
	// aqui atribuimos ao ponteiro o valor do local onde a variavel A esta alocada, a posicao de A, nao o seu valor!

	printf("%p\n", ponteiro); // Assim como usamos %d para INT, %f FLOAT, %c CHAR, para ponteiros usamos %p POINTER
	return(0);
}

Ponteiros sao como outras variaveis, entao eh possivel atribuir valores aos mesmos. Por exemplo:

#include <stdio.h>

int main(void)
{
    int a;
    int *ptr;
    int *ptr2;
    int **ptr3; // Ponteiro para um ponteiro, ou seja, ptr3 ira apontar para um outro ponteiro para um int, como ptr ou ptr2
    // ptr3 vai ter o endereco de um outro ponteiro
    ptr = &a; // Aqui o prt recebe a direcao onde A esta armazenado
    printf ("%p\n", ptr);

    ptr2 = ptr; // Aqui prt2 recebe o valor de prt, que por sua vez eh onde a esta armazenado
    printf ("%p\n", ptr2);
    
    ptr3 = &ptr; // Aqui ptr3 recebe o endereco do ponteiro ptr (Cujo esta armazenando o endereco de outro int)
    printf ("%p\n", ptr3);
    // O mesmo valor sera exibido ao correr o programa
    return (0);
}

---Desreferenciar um ponteiro

Um ponteiro eh uma referencia a um endereco de uma variavel, mas o que interessa eh saber o que ha no endereco e 
ser capaz de modificar a variavel.

#include <stdio.h>

int main(void)
{
    int a;
    int *ptr;

    a = 56;
    ptr = &a;
    printf ("%d\n", a); //Aqui exibimos o valor atribuido a 'a'
    printf("%d\n", *ptr); //Se chamarmos o ptr sem *, sera exibido o endereco da variavel
    // Ao chamar *ptr, estamos pedindo o valor alocado naquele endereco, pois definimos que ptr = &a 
    // Como queremos o valor alocado naquela posicao da memoria, devemos chamar o valor a ser impreeso eh um int
    // Entao usamos %d(INT) ao inves de %p(POINTER)

    return(0);
}

Tambem eh possivel alterar o valor da variavel somente utilizando o ponteiro, da seguinte maneira

#include <stdio.h>

int main (void)
{
	int a;
	int *ptr;

	a = 56; // Valor de a definido como 56
	ptr = &a; //Valor do ptr definido como endereco de 'a'
	*ptr = 78;// Atribuicao de 78 a variavel/local onde 'a' esta armazenado, ou seja, deixa de ser 56 e vira 78
	print("%d\n", a);

}

Ou seja, podemos criar um ponteiro que aponta pra um ponteiro, que aponta para outro, etc. 
Segue exemplo abaixo

#include <stdio.h>

int main (void)
{
	int a;
	int *ptr;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;

	a = 42; //Valor 42
	ptr = &a; // ptr recebe o enderecpd e a
	ptr2 = &ptr //ptr2 recebe o endereco de ptr 
	ptr3 = &ptr2 //ptr3 recebe o endereco de ptr2
	ptr4 = &ptr3 //ptr4 recebe o endereco de ptr3
	ptr5 = &ptr4 //ptr5 recebe o endereco de ptr4
}

A pointer when incremented always points to an immediately next location of its own type
So for example

Value		5    | 2    | 6    | 4 	  | 3
Address		1001 | 1005 | 1009 | 1013 | 1017

a[5] // Tamanho do Array
&a[0] // Recebe o endereco do primeiro slot do array, 1001
&a[0] + 1 // Quando um ponteiro eh incrementado ele vai diretamente para a proxima posicao do seu tipo
		  // 1001 + 1 nao eh 1002, mas sim pular pra proxima posicao 1005
&[0] + 1 = 1005
&[0] + 2 = 1009



-----Biblioteca string.h----


int main (void)
{
	char nome[15];
	nome = "Fulano de tal";

	printf ("Nome: &s", nome);
}
