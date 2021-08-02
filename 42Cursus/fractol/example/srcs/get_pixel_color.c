#include "fractol.h"

int	get_pixel_color(int x, int y, t_scene *scene)
{
	int		color;
	float	relative_x;
	float	relative_y;
	float	coord_x;
	float	coord_y;

	relative_x = (float)x - ((float)scene->res.x / 2);
	relative_y = (float)y - ((float)scene->res.y / 2);
	coord_x = scene->pos.x + (relative_x * scene->pos.pixel_distance);
	coord_y = scene->pos.y + (relative_y * scene->pos.pixel_distance);
	if (scene->fractal_type == MANDELBROT)
		color = compute_mandelbrot(coord_x, coord_y);
	else if (scene->fractal_type == JULIA)
		color = compute_julia(coord_x, coord_y, scene->c);
	else
		color = 0;
	return (color);
}
