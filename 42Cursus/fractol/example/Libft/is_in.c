#include "libft.h"

int	is_in(int num, int *arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}
