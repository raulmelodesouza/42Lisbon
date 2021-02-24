#include <stdio.h>
#include <string.h>

int main (void)
{
    char nome[15] = "Raul Melo"; // Soh eh possivel atribuir um valor durante a criacao da string
    char nome2[15] = "Lucas Melo";
    printf ("Nome: %s\n", nome); // Exibira Raul Melo 

    // strcpy (string_destino, string_origem)
    strcpy (nome, "Raul Souza"); // A funcao strcpy atribui a um destino o valor que especificarmos
    // O destino eh a variavel nome, o valor eh Raul Souza
    printf("Nome: %s\n", nome);   

    strcpy (nome, nome2);
    printf ("Teste string copy: %s", nome);

}

#include <stdio.h>
#include <string.h>

int main (void)
{
    char nome[15] = "Raul Melo"; // Soh eh possivel atribuir um valor durante a criacao da string
    char nome2[15] = "Lucas Melo";
    printf ("Nome: %s\n", nome); // Exibira Raul Melo 

    // strncpy (string_destino, string_origem, tamanho)
    strncpy (nome, nome2, 5); // A funcao strncpy atribui ao destino o valor da origem e apenas a quantidade de caracteres especificadas
    // O destino sera substituido por nome2, mas somente iremos colocar 5 caracteres da origem, entao soh Lucas sera passado 
    printf("Nome: %s\n", nome);   

    strcpy (nome, nome2);
    printf ("Teste string n copy: %s", nome);
    // Valor original "Raul Melo", Novo valor "LucasMelo"

}



vim ~/.vimrc

syntax on
set nu
set ruler
mouse=a


