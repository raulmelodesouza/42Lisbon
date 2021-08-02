#include "fractol.h"

int	my_key_hook(int keycode, t_scene *scene)
{
	if (keycode == UP_ARROW)
		scene->pos.y -= scene->pos.pixel_distance * 30;
	else if (keycode == DOWN_ARROW)
		scene->pos.y += scene->pos.pixel_distance * 30;
	else if (keycode == LEFT_ARROW)
		scene->pos.x -= scene->pos.pixel_distance * 30;
	else if (keycode == RIGHT_ARROW)
		scene->pos.x += scene->pos.pixel_distance * 30;
	else if (keycode == ESC)
		exit(1);
	return (1);
}
