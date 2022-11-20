/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:17:57 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 12:26:09 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

typedef struct s_data_vecotr
{
	t_vector	vup;
	t_vector	w;
	t_vector	u;
	t_vector	v;
}				t_data_vector;

t_calculate	calculate_setup(t_data *data);
void		set_pixel(t_data *data, t_color color, int x, int y);

void	calculate(t_data *data)
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
	t_calculate		cal_obj;
	t_camera		camera;
	double			vp_height;
	double			vp_width;
	t_data_vector	vdata;

	camera = data->scene.camera;
	vp_height = tan((camera.fov * M_PI / 180) / 2) * 2.0;
	vp_width = vp_height * ASPECT_RATIO;
	vdata.vup = vector_create(0.0, 1.0, 0.0);
	vdata.w = vector_mul_n(camera.rotation, -1.0);
	vdata.w = vector_div_n(vdata.w, vector_length(vdata.w));
	vdata.u = vector_cross(vdata.vup, vdata.w);
	vdata.u = vector_div_n(vdata.u, vector_length(vdata.u));
	vdata.v = vector_cross(vdata.u, vdata.w);
	cal_obj.origin = camera.position;
	cal_obj.horizontal = vector_mul(vector_create(vp_width, 0, 0), vdata.u);
	cal_obj.vertical = vector_mul(vector_create(0, vp_height, 0), vdata.v);
	cal_obj.lowerLeftCorner = vector_sub(vector_sub(vector_sub(cal_obj.origin,
					vector_div_n(cal_obj.horizontal, 2)),
				vector_div_n(cal_obj.vertical, 2)), vdata.w);
	return (cal_obj);
}

void	set_pixel(t_data *data, t_color color, int x, int y)
{
	int	i;

	i = y * WIDTH + x;
	data->img[i]->r = color.r;
	data->img[i]->g = color.g;
	data->img[i]->b = color.b;
}
