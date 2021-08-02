FLAGS = -Wall -Wextra -Werror
AR = ar rcs

NAME = libft.a

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)


all: $(OBJS)
	ar rcs $(NAME) $(OBJS)

so:
	gcc -c $(FLAGS) -fPIC $(SRCS) $(BONUS)
	gcc -shared -o libft.so $(OBJS) $(OBJS_BONUS)

bonus: $(OBJS_BONUS) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	gcc $(FLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
