********************************************************* 42Cursus *********************************************************


------------------------------------Sixth Project - push_swap-----------------------------------

Sources:
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
https://github.com/sshiling/42-push_swap
https://github.com/pbondoer/42-push_swap
https://github.com/kurval/42-push_swap <<<<<
https://github.com/wwatkins42/42_C_Projects/tree/master/Push_swap ****
https://github.com/wwatkins42/42_C_Projects
https://github.com/VBrazhnik?tab=repositories
https://www.youtube.com/watch?v=7KW59UO55TQ
https://github.com/rizky/42-push_swap/tree/master/src
https://www.youtube.com/watch?v=SLauY6PpjW4
https://www.youtube.com/watch?v=egU3YD8OKbw&t=51s

vim modifications: 
vim ~/.vimrc

syntax on
set nu
set ruler
set mouse=a

X------------------CONCEITOS IMPORTANTES PARA A IMPLEMENTACAO A FUNCAO------------------X

---> Objetivo do push_swap <---

O projeto push_swap é um projeto de algoritmo muito simples e altamente eficaz: os dados precisarão ser classificados. 
Você tem à sua disposição um conjunto de valores int, 2 pilhas e um conjunto de instruções para manipular ambas as pilhas.

Este projeto inclui 2 programas em C:
• O primeiro verificador denominado que recebe argumentos inteiros e lê instruções na saída padrão. Uma vez lidos, o verificador os executa e 
  exibe OK se os inteiros forem classificados. Caso contrário, ele exibirá KO.
• O segundo chamado push_swap que calcula e exibe na saída padrão o menor programa usando a linguagem de instrução Push_swap que classifica 
os argumentos inteiros recebidos.

• O objetivo é classificar em números de ordem crescente na pilha a.
• Para fazer isso, você tem as seguintes operações à sua disposição:
sa: troca a - troca os 2 primeiros elementos no topo da pilha a. Não faça nada se houver apenas um ou nenhum elemento).
sb: swap b - troque os 2 primeiros elementos do topo da pilha b. Não faça nada se houver apenas um ou nenhum elemento).
ss: sa e sb ao mesmo tempo.
pa: empurre a - pegue o primeiro elemento no topo de b e coloque-o no topo de a. Não faça nada se b estiver vazio.
pb: empurre b - pegue o primeiro elemento no topo de a e coloque-o no topo de b. Não faça nada se a estiver vazio.
ra: rotacionar a - deslocar todos os elementos da pilha a em 1. O primeiro elemento se torna o último.
rb: rotate b - desloca todos os elementos da pilha b em 1. O primeiro elemento se torna o último.
rr: ra e rb ao mesmo tempo.
rra: rotação reversa a - desloca para baixo todos os elementos da pilha a em 1. O último elemento se torna o primeiro.

---> Criterios da avaliacao que serao considerados <---

Usei a implementação de lista vinculada para formar pilhas e armazenar as regras.

Tenho três algoritmos diferentes para diferentes quantidades de inteiros:

sort_três: classifica três inteiros com menos de 3 movimentos. Isso era muito simples porque havia apenas 3 X 2 combinações diferentes.

sort_five: classifica cinco inteiros em menos de 11 movimentos. O melhor caso são 7 movimentos (veja o exemplo). 
		   Este algoritmo encontra o menor número que é empurrado para a pilha B após o próximo inteiro que também é empurrado para a pilha B. 
		   Depois disso, posso usar sort_três para resolver a pilha A e empurrar o menor número da pilha B de volta para A. 
		   Então, tenho que encontrar o local certo para o último número e colocá-lo no lugar.

big_sort: Este algoritmo é projetado para uma quantidade maior de inteiros. Este algoritmo divide a pilha A em partes menores que são empurradas 
		  para a pilha B: <= 100 são divididos em 5 partes e> 100 inteiros em 10 partes. Os pedaços com os menores números são empurrados primeiro 
		  para a pilha B. Usei uma matriz classificada de inteiros para me ajudar a dividir a pilha A. Quando todos os números estão na pilha B, 
		  então posso começar a pesquisar os números do maior número e empurrá-los de volta para pilha A. Isso continua até que B esteja vazio e 
		  A seja classificado. Para otimizar, criei uma função chamada maneira mais curta de verificar se é mais eficaz usar rb ou rrb para colocar 
		  esse número no topo da pilha B.


---> Compilacao do projeto <---

Run make from terminal and use command:
./push_swap [int arguments] | ./checker [-v] [int arguments]
-v flag for visual mode. See the example below

EXAMPLE
./push_swap 1 5 2 4 3 | ./checker -v 1 5 2 4 3

