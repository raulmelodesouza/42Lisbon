********************************************************* 42Cursus *********************************************************


------------------------------------Fifth Project - ft_server-----------------------------------

Sources:
https://harm-smits.github.io/42docs/projects/ft_server
https://github.com/vvarodi/ft_server
https://github.com/ska42/ft_server
https://github.com/solaldunckel/ft_server
https://github.com/rchallie/ft_server
https://github.com/vscabell/ft_server
https://github.com/pmouhali/ft_server - Tutorial by pmouhali

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


---> Makefile <---

Para executar o nosso Dockerfile sera necessario a criacao de um Makefile, utilizando os comandos basicos do Docker
aprendidos acima junto aos nossos conhecimentos sobre o Makefile:

IMAGE = server_image
CONTAINER = server

docker-build:
	sudo docker build -t $(IMAGE) .

docker-run:
	sudo docker run -d -p 80:80 -p 443:443 --name $(CONTAINER) $(IMAGE)

all: docker-build docker-run

docker-stop:
	sudo docker stop $(CONTAINER)

docker-rm: docker-stop
	sudo docker rm $(CONTAINER)

docker-rmi:
	sudo docker rmi $(IMAGE)

docker-exec:
	sudo docker exec -it $(CONTAINER) bash

autoindex-on:
	sudo docker exec $(CONTAINER) bash /autoindex.sh on

autoindex-off:
	sudo docker exec $(CONTAINER) bash /autoindex.sh off

clean: docker-rm docker-rmi

.PHONY: all, clean


---> Dockerfile <---

Boas praticas para a criacao de um Dockerfile: 
"https://docs.docker.com/develop/develop-images/dockerfile_best-practices/"

O Docker constrói imagens automaticamente lendo as instruções de um Dockerfile - um arquivo de texto que contém todos os comandos, 
em ordem, necessários para construir uma determinada imagem. Um Dockerfile segue um formato específico e um conjunto de instruções 
que você pode encontrar na referência do Dockerfile.

Uma imagem Docker consiste em camadas read-only, cada uma das quais representa uma instrução Dockerfile. 
As camadas são empilhadas e cada uma é um delta das alterações da camada anterior. Considere este Dockerfile:

FROM ubuntu: 18.04
COPY . /aplicativo
RUN make / app
CMD python /app/app.py

Cada instrução cria uma camada:

** FROM cria uma camada da imagem Docker do ubuntu: 18.04.
** COPY adiciona arquivos do diretório atual do seu cliente Docker.
** RUN constrói seu aplicativo com make.
** CMD especifica o comando a ser executado no contêiner.

Ao executar uma imagem e gerar um contêiner, você adiciona uma nova camada gravável (a “camada do contêiner”) no topo 
das camadas subjacentes. Todas as alterações feitas no contêiner em execução, como gravar novos arquivos, modificar 
arquivos existentes e excluir arquivos, são gravadas nesta camada de contêiner gravável.

Entao abaixo iremos criar o Dockerfile de acordo com as especificacoes do projeto, um Dockerfile para:

* Nginx
* PHP
* MariaDB SQL database
* PhpMyAdmin
* Wordpress

Lembrando que no subject do projeto esta especificado que "The container OS must be debian buster"

/* 
Install the base image
Select image from Dockerhub - Debian Buster https://hub.docker.com/_/debia
*/
FROM debian:buster

/*Aqui faremos a instalacao de pacotes e instalar os servicos necessarios
Existem duas maneiras de faze-lo, podemos fazer os updates/instalacoes atraves de multi-line arguments
conforme exemplo abaixo, ou entao fazer cada pacote por vez, por exemplo:

RUN apt-get -y update
RUN apt-get -y install nginx

Porem iremos usar o multi-line arguments para facilitar a compreensao do codigo

A flag -y siginifca um YES para todos os arquivos especificados
*/
RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php-fpm \
    php-mysql \
    php-mbstring \
    wget \
    && rm -rf /var/lib/apt/lists/ * //Lembrar de retirar o espaco entre / e * 

// NGINX
RUN     echo "daemon off;" >> /etc/nginx/nginx.conf && \ 
        rm var/www/html/index.nginx-debian.html
COPY	srcs/nginx/ *.conf /tmp/ // Lembrar de remover o espaco entre / e *
#COPY   /srcs/nginx/server.conf /etc/nginx/sites-available/server.conf
#RUN    ln -s /etc/nginx/sites-available/server.conf /etc/nginx/sites-enabled/server.conf
#RUN    rm -rf /etc/nginx/sites-enabled/default

// PHPMYADMIN
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
    tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
    mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin && \
    rm -rf phpMyAdmin-5.0.2-english.tar.gz
COPY srcs/phpmyadmin/config.inc.php /var/www/html/phpmyadmin

// WordPress
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    mv wordpress /var/www/html/ && \
    rm -rf latest.tar.gz
COPY srcs/wordpress/wp-config.php /var/www/html/wordpress

// SLL
RUN mkdir ~/mkcert && cd ~/mkcert && \
	wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64 && \
	mv mkcert-v1.4.1-linux-amd64 mkcert && chmod +x mkcert && \
	./mkcert -install && ./mkcert localhost

// Giving nginx's user-group rights over page files
RUN	chown -R www-data:www-data /var/www/html/ * //Lembrar de apagar o espaco entre / e *

//Expose HTTP and HTTPS ports
// Ports that needs to be exposed at run time with -p [host port]:[container port]
EXPOSE 80 443

//Launch script
CMD bash root/start.sh 

