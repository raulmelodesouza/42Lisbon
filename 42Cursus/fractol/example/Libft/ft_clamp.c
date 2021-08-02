#include "libft.h"

int	ft_clamp(int min, int num, int max)
{
	int	ret;

	ret = num;
	if (ret < min)
		ret = min;
	if (ret > max)
		ret = max;
	return (ret);
}
