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
https://forhjy.medium.com/how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-1-75ddf3ede861
https://forhjy.medium.com/42-ft-server-how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-2-4042adb2ab2c

vim modifications: 
 epwwyJaXQj)d)plNoQ
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

---> Construcao detalhada do Dockerfile <---

/*Primeiro iremos instalar a imagem base
Lembrando que no subject do projeto esta especificado que "The container OS must be debian buster"
Entao vamos selecioanr a imagem do Dockerhub - Debian Buster https://hub.docker.com/_/debia
*/

FROM debian:buster

/*
Por padrao, ao rodar um dock container o AUTOINDEX esta sempre ativado. 
Existem diversas maneiras de manipular o autoindex no docker, tal como executa-lo quando iniciamos a execucao:

docker run --env AUTOINDEX=off --name ft_server -d -p 443:443 -p 80:80 ft_server

Tambem pode ser ativado/desttivado quando container eh lancado, por exemplo, dentro do mesmo:

echo $AUTOINDEX
AUTOINDEX=off
bash change_autoindex.sh
or outside the container

sh autoindex_off.sh

Aqui no nosso dockerfile iremos ativar o autoindex, e criaremos arquivos para quando estiver ON/OFF

O que seria ENV? 
ENV é para contêineres em execução no futuro. ARG para construir sua imagem Docker apenas. 
O ENV destina-se principalmente a fornecer valores padrão para suas futuras variáveis ​​de ambiente. 
A execução de aplicativos encaixados pode acessar variáveis ​​de ambiente. 
É uma ótima maneira de passar valores de configuração para seu projeto.
Os valores ARG não estão disponíveis após a construção da imagem.
Entao como estaremos lidan do com um index, o deixaremos disponivel ate depois da construcao da imagem

*/

ENV AUTOINDEX on

/*Aqui faremos a instalacao de pacotes e instalar os servicos necessarios
Existem duas maneiras de faze-lo, podemos fazer os updates/instalacoes atraves de multi-line arguments
conforme exemplo abaixo, ou entao fazer cada pacote por vez, por exemplo:

RUN apt-get -y update
RUN apt-get -y install nginx

Porem iremos usar o multi-line arguments para facilitar a compreensao do codigo, alem disso executaremos 
o update e a instalacao juntos, com a utiliacao de &&, conforme execucao abaixo

A flag -y siginifca um YES para todos os arquivos especificados

Explicacao de alguns comandos basicos

wget - Wget é o downloader de rede não interativo que é usado para baixar arquivos do servidor mesmo quando o usuário não 
	   está conectado ao sistema e pode trabalhar em segundo plano sem atrapalhar o processo atual

apt-get update/install - Comando utilizado para buscar e baixar os updates e/ou instala-los
*/

RUN apt-get update && apt-get install -y \ // rodar updates e instalar, flag -y para permitir 
    nginx \
    mariadb-server \
    php-fpm \
    php-mysql \
    php-mbstring \
    wget \ 
    && rm -rf /var/lib/apt/lists/*

/*
Agora abaixo serao executadas as instalacoes das instacias com as quais iremos trabalhar, conforme ja definido anteriormente:

Sinceramente nao ha muita explicacao para os comandos executados abaixo, pois todos foram obtidos atraves de 
recursos online sobre como instalar Wordpress ou outra aplicacao em uma instancia docker, sao comandos ja preparados
pelas plataformas, entao soh temos que executa-los mesmo.

Como nao eh um tema que nao me interessa muito, nao vou me aprofundar nas explicacoes de instalacoes, o guia de como faze-lo
estao abaixo

* Nginx - https://github.com/vvarodi/ft_server/blob/master/img/default

* PHP - https://www.php.net/manual/es/index.php

* MariaDB SQL database - https://mariadb.com/kb/en/mysql_secure_installation/

* PhpMyAdmin - https://docs.phpmyadmin.net/en/latest/
			   https://docs.phpmyadmin.net/en/latest/config.html#
			   https://docs.phpmyadmin.net/en/latest/config.html#config-examples

* Wordpress - https://wordpress.org/support/article/how-to-install-wordpress/
			  https://wordpress.org/support/article/editing-wp-config-php/

*/

# NGINX
RUN     echo "daemon off;" >> /etc/nginx/nginx.conf && \ 
        rm var/www/html/index.nginx-debian.html
COPY    srcs/nginx/*.conf /tmp/

# PHPMYADMIN
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
    tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
    mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin && \
    rm -rf phpMyAdmin-5.0.2-english.tar.gz
COPY srcs/phpmyadmin/config.inc.php /var/www/html/phpmyadmin

# WordPress
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz && \
    mv wordpress /var/www/html/ && \
    rm -rf latest.tar.gz
COPY srcs/wordpress/wp-config.php /var/www/html/wordpress

# SLL
RUN mkdir ~/mkcert && cd ~/mkcert && \
    wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64 && \
    mv mkcert-v1.4.1-linux-amd64 mkcert && chmod +x mkcert && \
    ./mkcert -install && ./mkcert localhost

# Giving nginx's user-group rights over page files
RUN chown -R www-data:www-data /var/www/html/*

# Scripts: start.sh && change_index.sh
COPY srcs/*.sh ./

# Ports that needs to be exposed at run time with -p [host port]:[container port]
EXPOSE 80 443

CMD bash start.sh

*/

---> Construcao detalhada do nosso autoindex_on/off <---

Por padrão, o AUTOINDEX está ativado quando você executa o contêiner. Se você deseja executar o contêiner, 
definindo o autoindex desativado no início de sendo lançado:

docker run --env AUTOINDEX=off --name ft_server -d -p 443:443 -p 80:80 ft_server

/*As portas 80 e 443 são geralmente associadas à "Internet".
A porta 443 / HTTPS é o protocolo HTTP sobre TLS / SSL.
A porta 80 / HTTP é a World Wide Web. eu
As portas 80/443 são geralmente permitidas por serem abertas em qualquer tipo de dispositivo de filtragem, permitindo a saída de 
tráfego em sua rede.
Se os servidores da web estiverem sendo hospedados, as conexões serão permitidas de entrada para esses servidores da web.
Eles também são duas portas que representam uma ameaça significativa para a sua rede. */

Também pode ser ativado / desativado quando o contêiner é lançado (por meio de uma variável de ambiente):

1 - Dentro do container: 

echo $AUTOINDEX
AUTOINDEX=off
bash change_autoindex.sh

2 - Ou fora do container:

sh autoindex_off.sh

De maneira a facilitar o entendimento, serao criados dois arquivos externos, para quando o autoindex for activated/deactivated

/*
Comandos explicador
docker stop - finalizar a execucao do nosso container ft_server
docker run 
	--rm - automaticamente remove o container ao sair
	--env - define as variaveis de ambiente AUTOINDEX=off
	--name - atribui um nome ao container ft_server
	--d - roda o container em segundo plano e imprime o ID do container
	--p - Publica a  porta  de um contêiner para o host 
*/

#autoindex_off.sh

docker stop ft_server
docker run --rm --env AUTOINDEX=off --name ft_server -d -p 443:443 -p 80:80 ft_server

#autoindex_on.sh
docker stop ft_server
docker run --rm --env AUTOINDEX=on --name ft_server -d -p 443:443 -p 80:80 ft_server

#change_autoindex.sh
#!/bin/bash

# Verifica se nginx ja foi inciado, em caso positivo faz a mudanca e recarrega, 
# caso contrario (primeira tentativa -> durante a construção do contêiner) apenas copia os arquivos
/*
Comandos da execucao abaixo
ps = list processes
-e = exibe todos or pcoessos, nao apenas os que pertencem ao usuario
-f = mostra os processos em formato completo, mais detalhado
-ef = Mostra todos os processos de maneira detalhada
grep = encontra linhas que contenham um padrao a ser especificado
wc = word count, contagem de palavras

Ao usar o if/else numa linha de comando, devemos indicar o fim com ; fi
*/

if (( $(ps -ef | grep -v grep | grep nginx | wc -l) > 0 ))
then
    if [ "$AUTOINDEX" = "off" ] ;
    then cp /tmp/server_auto_off.conf /etc/nginx/sites-available/default ;
    else cp /tmp/server.conf /etc/nginx/sites-available/default ; fi
service nginx reload
else
    if [ "$AUTOINDEX" = "off" ] ;
    then cp /tmp/server_auto_off.conf /etc/nginx/sites-available/default ;
    else cp /tmp/server.conf /etc/nginx/sites-available/default ; fi
fi

---> Configuração do wordpress com SQL <---

A informacao para realizar a configuracao do Wordpress junto ao MySQL pode ser encontrada em:

https://forhjy.medium.com/42-ft-server-how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-2-4042adb2ab2c

<?php

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'put your unique phrase here' );
define( 'SECURE_AUTH_KEY',  'put your unique phrase here' );
define( 'LOGGED_IN_KEY',    'put your unique phrase here' );
define( 'NONCE_KEY',        'put your unique phrase here' );
define( 'AUTH_SALT',        'put your unique phrase here' );
define( 'SECURE_AUTH_SALT', 'put your unique phrase here' );
define( 'LOGGED_IN_SALT',   'put your unique phrase here' );
define( 'NONCE_SALT',       'put your unique phrase here' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );

---> Autoindex ON e OFF <---

para modificar o autoindex eh apenas preciso executar no terminal o comando 

sh autoindex_on.sh

ou 

sh autoindex_off.sh

