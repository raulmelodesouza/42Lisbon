********************************************************* 42Cursus *********************************************************


------------------------------------Fifth Project - ft_server-----------------------------------

Sources:
https://harm-smits.github.io/42docs/projects/ft_server
https://github.com/vvarodi/ft_server
https://github.com/ska42/ft_server
https://github.com/solaldunckel/ft_server
https://github.com/rchallie/ft_server
https://github.com/vscabell/ft_server

vim modifications: 
 
vim ~/.vimrc

syntax on
set nu
set ruler
set mouse=a

X------------------CONCEITOS IMPORTANTES PARA A IMPLEMENTACAO A FUNCAO------------------X

---> Objetivo do ft_server <---

O objetivo do ft_server é criar um servidor web com Nginx capaz de executar um site WordPress, phpMyAdmin e um banco de dados MySQL. 
Este servidor será executado em apenas um Docker container, sob o Debian Buster.

	'Servico'  	 |   	'Path'
-----------------|--------------------------------------
    WordPress    |	http:localhost/wordpress
-----------------|--------------------------------------
    phpMyAdmin   |	http:localhost/phpmyadmin 
-----------------|--------------------------------------


---> Docker <---

Docker é uma plataforma aberta para desenvolvimento, envio e execução de aplicativos. 
O Docker permite que você separe seus aplicativos de sua infraestrutura para que possa entregar o software rapidamente. 
Com o Docker, você pode gerenciar sua infraestrutura da mesma forma que gerencia seus aplicativos. 
Tirando proveito das metodologias do Docker para envio, teste e implantação de código rapidamente, você pode reduzir 
significativamente o atraso entre escrever o código e executá-lo na produção.


Quando você digita na barra de pesquisa "Google.com", um servidor web armazena os arquivos que constituem o site (imagens, etc.). 
Para obter a página, seu navegador solicita uma página da web ao servidor, que envia os arquivos (se o servidor não encontrar o 
documento solicitado, ele retorna uma resposta 404).

Existem diferentes tipos de servidores web: estáticos ou dinâmicos. No nosso caso, criaremos um servidor web dinâmico.

Do ponto de vista do software, os componentes de um servidor da web dinâmico são:

* Um OS/Operational System/SO/Sistema Operacional (ex: Windows or Linux)
* Um servidor HTTP = software que suporta solicitações cliente-servidor para o protocolo HTTP (ex: Apache ou Nginx)
* Um banco de dados (ex: mySQL, Oracle)
* Uma linguagem de script = permite interpretar as solicitações do cliente e traduzi-las em html (ex: PHP, Python, Java)
* Nosso SO = Debian Buster
* Nosso servidor HTTP = Nginx
* Nosso banco de dados = Maria DB.
* Nossa linguagem de script = PHP

Além disso, iremos instalar e configurar phpMyAdmin e WordPress

Faremos tudo isso em um Docker container. Por que em um Docker container? 🐳

⚠️ O problema: muitas vezes acabamos com aplicativos que têm toneladas de dependências: precisam de mágica para converter imagens, 
precisam de um banco de dados específico, precisam de nginx ou apache etc. Quando trabalhar com um host de terceiros, é um inferno. 
O administrador do sistema terá que instalar as versões corretas em várias máquinas, etc., quebra-cabeça. 💢

💯 A solução: o Docker possibilita empacotar um aplicativo em um contêiner virtual. É uma espécie de caixa totalmente isolada de 
nosso sistema operacional. No qual podemos instalar todas as bibliotecas que nosso aplicativo precisa para funcionar. 
E também instalamos nosso aplicativo lá. E assim podemos enviar esta caixa para todos os lugares, e ela funcionará independentemente 
do sistema operacional.✔️

Nosso Docker image ira incluir:

Nginx
PHP
MariaDB SQL database
PhpMyAdmin
Wordpress

x--------Comandos basicos do Docker--------x

# Build a docker image from a Dockerfile
docker build -t <your image name> <your Dockerfile dir>

# Start an instance of a docker image
docker run -it <your image name>

# Really important if you want to bind some ports on the container to your own computer, use -p option.
# Example for an Apache image first 80 means is local port, second 80 means container port
docker run -it debian:apache -p 80:80

# Enter running container
docker exec -it <ID or container name> bash

# See all images
docker images

# Remove images
docker rmi <image>
# docker rmi $(docker images -aq)

# Remove a container
$ docker rm <ID or container name>

# See running containers
docker ps
# List all docker containers (running and stopped).
docker ps -a

# Stop a container
docker kill <ID or container name>

# Delete all unused Docker images and cache and free space
docker system prune