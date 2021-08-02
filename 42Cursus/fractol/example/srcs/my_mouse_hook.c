#include "fractol.h"

int	my_mouse_hook(int button, int x, int y, t_scene *scene)
{
	int	normal_x;
	int	normal_y;

	if (button == SCROLL_UP)
		scene->pos.pixel_distance /= 1.15;
	else if (button == SCROLL_DOWN)
		scene->pos.pixel_distance *= 1.15;
	else
		return (0);
	normal_x = x - scene->res.x / 2;
	normal_y = y - scene->res.y / 2;
	return (1);
}
