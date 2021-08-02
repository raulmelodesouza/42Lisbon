#include "libft.h"

float	ft_fclamp(float min, float num, float max)
{
	float	ret;

	ret = num;
	if (ret < min)
		ret = min;
	if (ret > max)
		ret = max;
	return (ret);
}
