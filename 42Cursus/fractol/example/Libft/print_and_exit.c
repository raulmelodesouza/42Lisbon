#include "libft.h"

void	print_and_exit(char *text, int error)
{
	size_t	i;

	ft_putstr_fd(text, 1);
	i = ft_strlen(text);
	if (text[i - 1] != '\n')
		write(1, "\n", 1);
	exit(error);
}
