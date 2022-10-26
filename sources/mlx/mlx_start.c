#include "../../includes/miniRT.h"
# include "../../includes/render.h"
void	mlx_start(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	render((void *) data);
	// mlx_loop_hook(data->mlx, &render, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);	
}
