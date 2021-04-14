# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/31 13:24:00 by rmelo-de          #+#    #+#              #
#    Updated: 2021/04/01 11:25:53 by rmelo-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IMAGE = server_image
CONTAINER = server

docker-build:
	 docker build -t $(IMAGE) .

docker-run:
	 docker run -d -p 80:80 -p 443:443 --name $(CONTAINER) $(IMAGE)

all: docker-build docker-run

docker-stop:
	 docker stop $(CONTAINER)

docker-rm: docker-stop
	 docker rm $(CONTAINER)

docker-rmi:
	 docker rmi $(IMAGE)

docker-exec:
	 docker exec -it $(CONTAINER) bash

clean: docker-rm docker-rmi

.PHONY: all, clean
