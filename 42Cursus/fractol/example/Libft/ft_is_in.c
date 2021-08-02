#include "libft.h"

int	ft_is_in(char c, char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (c == *str++)
			return (1);
	return (0);
}
