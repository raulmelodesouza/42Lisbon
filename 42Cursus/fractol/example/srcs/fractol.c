#include "fractol.h"

static t_scene	*get_scene_from_args(int argc, char **argv);
static void		fill_julia(int argc, char **argv, t_scene *scene);
static void		print_args(void);
static t_pos	init_pos(void);

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = get_scene_from_args(argc, argv);
	if (!scene)
		return (0);
	do_everything(scene);
	return (0);
}

static t_scene	*get_scene_from_args(int argc, char **argv)
{
	t_scene	*scene;

	if (argc < 4)
		print_args();
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->res.x = atof(argv[1]);
	scene->res.y = atof(argv[2]);
	scene->pos = init_pos();
	if (!ft_strcmp(argv[3], "m"))
	{
		scene->fractal_type = MANDELBROT;
		scene->c.r = 0;
		scene->c.i = 0;
	}
	else if (!ft_strcmp(argv[3], "j"))
	{
		scene->fractal_type = JULIA;
		fill_julia(argc, argv, scene);
	}
	else
		return (NULL);
	return (scene);
}

static void	fill_julia(int argc, char **argv, t_scene *scene)
{
	if (argc < 6)
		print_args();
	scene->c.r = atof(argv[4]);
	scene->c.i = atof(argv[5]);
}

static void	print_args(void)
{
	printf("Not enough args.\n");
	printf("Args format: ");
	printf("./fractol RES_X RES_Y FRACTAL_TYPE\n");
	printf("Format if using Julia set: ");
	printf("./fractol RES_X RES_Y j REAL_NUM IMG_NUM\n");
	exit(20);
}

static t_pos	init_pos(void)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	pos.pixel_distance = 0.008;
	return (pos);
}
