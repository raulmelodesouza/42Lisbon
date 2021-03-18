#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>
#include "libft/libft.h"

int main()
{
	printf("%p %p", LONG_MIN, LONG_MAX);
	printf("%p %p", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
    return 0;
}