#include "../../includes/render.h"


t_calculate	calculate_setup(t_data *data);
void		set_pixel(t_data *data, t_color color,int x,int y);

void calculate(t_data *data)
{
	t_calculate	cal_obj;
	int			x;
	int			y;
	t_ray		ray;
	t_color		color;

	cal_obj = calculate_setup(data);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_calculate(cal_obj, x, y);
			color = color_calculate(data, ray);
			set_pixel(data, color, x, y);
			x++;
		}
		y++;
	}
}

t_calculate	calculate_setup(t_data *data)
{
	t_calculate cal_obj;

	cal_obj.origin = data->scene.camera.position;
	cal_obj.horizontal = vector_create(VIEWPORT_WIDTH, 0, 0);
	cal_obj.vertical = vector_create(0, VIEWPORT_HEIGHT, 0);
	t_vector focal = vector_create(0, 0, FOCAL_LENGTH);
	cal_obj.lowerLeftCorner = vector_sub(vector_sub(vector_sub(cal_obj.origin, vector_div_n(cal_obj.horizontal, 2)), vector_div_n(cal_obj.vertical, 2)), focal);
	return (cal_obj);
}

void	set_pixel(t_data *data, t_color color,int x,int y)
{
	int	i;

	i = y * WIDTH + x;
	data->img[i]->r = color.r;
	data->img[i]->g = color.g;
	data->img[i]->b = color.b;
}
















