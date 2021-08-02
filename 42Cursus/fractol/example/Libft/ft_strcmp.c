#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(t_byte *)s1 - *(t_byte *)s2);
}
