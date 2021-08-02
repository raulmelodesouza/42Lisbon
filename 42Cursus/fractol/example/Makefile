NAME		=	fractol

FLAGS		=	-Wall -Wextra -Werror
OBJDIR		=	/objs/
INCLUDES	=	-Iincludes

SRCS		=	$(wildcard libft/*.c)					\
				$(wildcard srcs/*.c)
			
OBJS		= 	$(SRCS:.c=.o)

all: $(OBJS)
	gcc $(FLAGS) $(OBJS) -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $< -c -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
