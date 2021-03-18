# -*- Makefile -*-

#target: condicion
	#action

NAME = libft.a 

HEADER = libft.h

SOURCE = ${wildcard ft_*.c}

OBJETO = ${SOURCE:.c=.o}
	
FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJETO}
	ar -rs ${NAME} ${OBJETO}

%.o: %.c
	gcc -c -o $@ $< 

all: ${NAME}

bonus: ${NAME}

clean:
	rm -f ${OBJETO}

fclean: clean
	rm -r ${NAME}

re: fclean all