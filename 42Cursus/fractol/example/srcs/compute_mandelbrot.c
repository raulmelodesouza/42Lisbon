#include "fractol.h"

int	compute_mandelbrot(float x, float y)
{
	int			iter;
	int			color;
	float		temp;
	t_complex	z;
	t_complex	c;

	c = init_complex(x, y);
	z = init_complex(0, 0);
	iter = 0;
	while (z.r * z.r + z.i * z.i <= 4 && iter < MAX_ITER)
	{
		temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp;
		iter++;
	}
	if (iter == MAX_ITER)
		return (0);
	color = MAX_COLOR * iter / MAX_ITER;
	return (color);
}
