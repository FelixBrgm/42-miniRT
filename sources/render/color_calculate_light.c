/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate_light.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:07:43 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/21 00:03:49 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_color	get_color_of_object(t_obj obj, t_ray light_ray);
double	hit_ratio_cylinder(t_data *data, t_obj_t closest, t_ray light_ray);

double	hit_ratio_sphere(t_data *data, t_obj_t closest)
{
	t_vector	light_dir;
	t_vector	normal;
	double		hit_ratio;

	light_dir = unit_vector(vector_sub(closest.intersection, data->scene.light.position));
	normal = unit_vector(vector_sub(closest.intersection, closest.obj->sphere->position));
	hit_ratio = vector_dot(normal, vector_mul_n(light_dir, -1.0));
	if (hit_ratio < 0.0)
		hit_ratio = 0.0;
	return (hit_ratio);
}

double	calculate_brightness(t_data *data, t_ray light_ray)
{
	double	brightness;
	double	brightness_less_factor;
	double	distance;

	brightness = 1;
	brightness_less_factor = 0.01;
	distance = vector_length(vector_sub(
				light_ray.origin, data->scene.light.position));
	if (distance > 1000000)
		brightness = 0;
	else
		brightness = (20 - log2(distance / brightness_less_factor)) / 20;
	return (brightness);
}

t_color	calculate_colorious(t_data *data, t_obj_t closest, t_ray light_ray)
{
	t_color	color;
	t_color	ambient_color;

	color = get_color_of_object(*(closest.obj), light_ray);
	ambient_color = color_mul_n(data->scene.ambient.color,
			data->scene.ambient.ratio);
	color = color_div_n(color_add(color, ambient_color),
			1 + data->scene.ambient.ratio);
	return (color);
}

t_color	calculate_shadow(t_data *data, t_color color, double brightness)
{
	t_color	shadow;

	shadow = color_mul_n(color, data->scene.light.brightness);
	shadow = color_mul_n(shadow, (0 + data->scene.ambient.ratio) / 2);
	shadow = color_mul_n(shadow, brightness);
	return (shadow);
}

typedef struct s_buck_this_khit
{
	t_obj_t		light_collisions;
	double		t_light_max;
	double		hit_ratio;
	t_vector	light_dir;
	t_vector	normal;
	t_ray		light_ray;
	t_color		color;
	double		brightness;
}				t_buck_this_khit;


t_color	color_calculate_light(t_data *data, t_obj_t closest)
{
	t_buck_this_khit	x;

	x.hit_ratio = 1;
	x.light_ray = ray_create(closest.intersection,
			vector_sub(data->scene.light.position, closest.intersection));
	x.t_light_max = vector_length(vector_sub(data->scene.light.position,
				x.light_ray.origin)) / vector_length(x.light_ray.direction);
	x.light_collisions = hit_closest_obj(data, x.light_ray);
	if (closest.obj->sphere)
		x.hit_ratio = hit_ratio_sphere(data, closest);
	else if (closest.obj->cylinder)
		x.hit_ratio = hit_ratio_cylinder(data, closest, x.light_ray);
	x.color = calculate_colorious(data, closest, x.light_ray);
	x.brightness = calculate_brightness(data, x.light_ray);
	if (x.brightness < 0.01)
		return (color_create(0, 0, 0));
	if (x.light_collisions.t <= 0.0 || x.light_collisions.t > x.t_light_max)
	{
		x.color = color_mul_n(x.color, data->scene.light.brightness);
		x.color = color_mul_n(x.color,
				(x.hit_ratio + data->scene.ambient.ratio) / 2);
		x.color = color_mul_n(x.color, x.brightness);
		return (x.color);
	}
	return (calculate_shadow(data, x.color, x.brightness));
}
