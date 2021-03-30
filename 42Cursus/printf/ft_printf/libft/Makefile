# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 12:02:49 by rmelo-de          #+#    #+#              #
#    Updated: 2021/03/25 12:02:52 by rmelo-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

#target: condicion
	#action

SRCS	= ${shell find . -type f \( -name "ft_*.c" ! -name "ft_lst*.c" \)}

SRCS_BONUS = ${shell find . -type f \( -name "ft_*.c" \)}

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

HEADER	= libft.h

NAME	= libft.a

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror

# -*- Rules -*-
#target: dependencies
#	action

#	Implicit rules

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@

#	Normal rules

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			ar rcs $(NAME) $(OBJS)

bonus:		fclean $(OBJS_BONUS) $(HEADER)
			ar rcs $(NAME) $(OBJS_BONUS)

.PHONY:		clean

clean:
	rm -f ${OBJS_BONUS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all
re: fclean all
