#include <stdio.h>

typedef struct 
{
	char *nome;
	int idade;
	float altura;
	char sexo;
	float porcentagem;
} pessoa;

void printperson (pessoa p)
{
	printf ("Nome: <%5s>, idade: %d, altura: %.2f, sexo: %c \n", p.nome, p.idade, p.altura, p.sexo);
	printf ("<%5c>\n", p.sexo);
	printf ("<%-6.1f%%>\n", p.porcentagem);
}

void setperson (pessoa *p, char *name, int age, float height, char sex, float percent) // Nessa funcao o parametro P eh um ponteiro para uma struct
{
	p->nome = name;
	p->idade = age;
	p->altura = height;
	p->sexo = sex;
	p->porcentagem = percent;
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
	setperson (&p1, "Raul", 26, 1.89, 'm', 50);
	printperson(p1);
	printf("Teste de string nula: %s\n", NULL);
	return(0);
}