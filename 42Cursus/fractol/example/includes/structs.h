#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}t_mlx;

typedef struct s_res
{
	int			x;
	int			y;
}t_res;

typedef struct s_pos
{
	float		x;
	float		y;
	float		pixel_distance;
}t_pos;

typedef struct s_complex
{
	float		r;
	float		i;
}t_complex;

typedef struct s_scene
{
	t_mlx		*mlx_data;
	t_img		*img_data;
	t_res		res;
	t_pos		pos;
	t_complex	c;
	int			fractal_type;
}t_scene;

#endif
