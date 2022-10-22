#include "../../includes/miniRT.h"
#include "../../includes/render.h"
void	render_put_to_window(t_data *data);
void	render_convert_rgb_to_pixels(t_data *data);

void	render(void *param)
{
	t_data	*data;

	data = param;
	
	calculate(data);
	render_put_to_window(data);
}


void	render_put_to_window(t_data *data)
{
	if (data->mlx_img)
		mlx_delete_image(data->mlx, data->mlx_img);

	data->mlx_img =  mlx_new_image(data->mlx, WIDTH, HEIGHT);
	render_convert_rgb_to_pixels(data);
	mlx_image_to_window(data->mlx, data->mlx_img, 0, 0);
}

void	render_convert_rgb_to_pixels(t_data *data)
{
	int			i;
	u_int8_t	*temp;

	i = 0;
	while (i < PIXELS)
	{
		temp = &(data->mlx_img->pixels[i * 4]);
		temp[0] = data->img[i]->r * 255;
		temp[1] = data->img[i]->g * 255;
		temp[2] = data->img[i]->b * 255;
		temp[3] = 255;
		i++;
	}
}