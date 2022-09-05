#include "../../includes/miniRT.h"

void	mlx_start(t_data *data)
{
	if (!data)
		exit(EXIT_FAILURE);
	data->mlx = mlx_init(1920, 1080, "miniRT", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	ft_memset(data->img->pixels, 125, data->img->width * data->img->height * sizeof(int));
	mlx_loop_hook(data->mlx, &render, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);	
}
