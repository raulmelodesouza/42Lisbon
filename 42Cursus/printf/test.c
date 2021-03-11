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
  	  (*p).idade = idade;
  	  p->idade = idade;

  	  Na nossa funcao MAIN passamos o endereco da variavel p1 (&p1), entao nosso ponteiro p aponta para o endereco de p1 
  	  e define os campos nome, idade, altura, que sao passados como parametro
	*/
}

int main ()
{
	pessoa p1;
	setperson (&p1, "Raul", 26, 1.89);
	printperson(p1);
	return(0);
}