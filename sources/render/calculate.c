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
	t_camera camera = data->scene.camera;
	double vp_height = tan((camera.fov * M_PI / 180) / 2) * 2.0; // FOV
	double vp_width = vp_height * ASPECT_RATIO;

	t_vector vup = vector_create(0.0, 1.0, 0.0);
	t_vector w = vector_mul_n(camera.rotation, -1.0);
	w = vector_div_n(w, vector_length(w));
	t_vector u = vector_cross(vup, w);
	u = vector_div_n(u, vector_length(u));
	t_vector v = vector_cross(u, w);

	cal_obj.origin = camera.position;
	cal_obj.horizontal = vector_mul(vector_create(vp_width, 0, 0), u);
	cal_obj.vertical = vector_mul(vector_create(0, vp_height, 0), v);
	t_vector focal = vector_create(0, 0, 1);
	cal_obj.lowerLeftCorner = vector_sub(vector_sub(vector_sub(cal_obj.origin, vector_div_n(cal_obj.horizontal, 2)), vector_div_n(cal_obj.vertical, 2)), w);
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
















