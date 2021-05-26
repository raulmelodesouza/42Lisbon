 #include "mlx.h"

int main ()
{
	void *mlx_ptr;

	mlx_ptr = mlx_init(); // para que possamos executar a nossa interface MiniLibX devemos sempre dar um mlx_init()
	mlx_new_window(mlx_ptr, 500, 500, "My First MiniLibX"); // Aqui chamamos a funcao que queremos, ou seja, aqui queremos que se abra uma nova janela
	mlx_loop(mlx_ptr);
}