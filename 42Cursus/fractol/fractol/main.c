#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	/*A funcao CLOSE foi criada para fechar a janela aberta anteriormente, */
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	/*Quando chamamos a funcao mlx_hook passamos como parametro vars.win que abre a janela, o evento X11 de numero 2 (KeyPress)
	que indica que uma tecla foi pressionada e a mask 1L<<0 que tambem indica uma tecla presionada, que eh a mask equivalente ao X11 numero 2*/
	mlx_loop(vars.mlx);
}