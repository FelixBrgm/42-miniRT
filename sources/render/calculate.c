#include "../../includes/render.h"
#include <stdio.h>

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
		printf("%f%%\n", (double) y/HEIGHT);
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


// [(a2 * b3 – a3 * b2), (a3 * b1 – a1 * b3), (a1 * b2 – a2 * b1)]

t_vector vector_cross(t_vector v1, t_vector v2)
{
	t_vector res;

	res.x = ((v1.y * v2.z) - (v1.z * v2.y));
	res.y = ((v1.z * v2.x) - (v1.x * v2.z));
	res.z = ((v1.x * v2.y) - (v1.y * v2.x));
	return (res);
}

t_calculate	calculate_setup(t_data *data)
{
	t_calculate cal_obj;
	t_camera camera = data->scene.camera;
	double vp_height = tan((camera.fov * M_PI / 180) / 2) * 2.0; // FOV
	double vp_width = vp_height * ASPECT_RATIO;

	t_vector vup = vector_create(0.0, 1.0, 0.0);
	t_vector w = vector_sub(camera.position, camera.rotation);
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

// t_calculate	calculate_setup(t_data *data)
// {
// 	t_calculate cal_obj;

// 	cal_obj.origin = data->scene.camera.position;
// 	cal_obj.horizontal = vector_create(VIEWPORT_WIDTH, 0, 0);
// 	cal_obj.vertical = vector_create(0, VIEWPORT_HEIGHT, 0);
// 	t_vector focal = vector_create(0, 0, FOCAL_LENGTH);
// 	cal_obj.lowerLeftCorner = vector_sub(vector_sub(vector_sub(cal_obj.origin, vector_div_n(cal_obj.horizontal, 2)), vector_div_n(cal_obj.vertical, 2)), focal);
// 	return (cal_obj);
// }

void	set_pixel(t_data *data, t_color color,int x,int y)
{
	int	i;

	i = y * WIDTH + x;
	data->img[i]->r = color.r;
	data->img[i]->g = color.g;
	data->img[i]->b = color.b;
}
















