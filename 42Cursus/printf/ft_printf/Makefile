# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 12:03:15 by rmelo-de          #+#    #+#              #
#    Updated: 2021/03/25 12:03:16 by rmelo-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

#target: condicion
	#action

NAME =		libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =		ft_printf.c ft_printchar.c ft_printstring.c ft_printnumbers.c ft_printpercent.c ft_checkflags.c ft_printpointer.c

OBJ 		= ${SRC:.c=.o}

HEAD =		-I. -I./$(LIBFT_DIR)
CFLAGS =	-Wall -Werror -Wextra -g
LFLAGS =	-L . -lftprintf

CC = clang
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rc $(NAME) $(OBJ)
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

.PONY: all, clean, fclean, re
