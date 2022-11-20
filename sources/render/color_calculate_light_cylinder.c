/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate_light_cylinder.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:44:29 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 23:06:59 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

double	hit_ratio_cylinder_extra(t_cylinder cylinder,
			t_vector light_dir, t_obj_t closest);
double	hit_ratio_cylinder_1(t_cylinder cylinder, t_vector light_dir);
double	hit_ratio_cylinder_2(t_cylinder cylinder, t_vector light_dir);

double	hit_ratio_cylinder(t_data *data, t_obj_t closest)
{
	t_cylinder	cylinder;
	t_vector	light_dir;
	t_vector	top_center;
	t_vector	bot_center;
	t_vector	normal;

	cylinder = *(closest.obj->cylinder);
	light_dir = unit_vector(vector_sub(
				closest.intersection, data->scene.light.position));
	top_center = vector_add(cylinder.position,
			vector_mul_n(unit_vector(cylinder.rotation), cylinder.height / 2));
	bot_center = vector_sub(cylinder.position,
			vector_mul_n(unit_vector(cylinder.rotation), cylinder.height / 2));
	if (vector_length(vector_sub(
				closest.intersection, top_center)) <= cylinder.radius)
		return (hit_ratio_cylinder_1(cylinder, light_dir));
	else if (vector_length(vector_sub(
				closest.intersection, bot_center)) <= cylinder.radius)
		return (hit_ratio_cylinder_2(cylinder, light_dir));
	else
		return (hit_ratio_cylinder_extra(cylinder, light_dir, closest));
}

double	hit_ratio_cylinder_1(t_cylinder cylinder, t_vector light_dir)
{
	t_vector	normal;
	t_vector	rotation;
	double		hit_ratio;

	rotation = unit_vector(cylinder.rotation);
	normal = rotation;
	hit_ratio = vector_dot(normal, vector_mul_n(light_dir, -1.0));
	if (hit_ratio < 0.0)
		hit_ratio = 0.0;
	return (hit_ratio);
}

double	hit_ratio_cylinder_2(t_cylinder cylinder, t_vector light_dir)
{
	t_vector	normal;
	t_vector	rotation;
	double		hit_ratio;

	rotation = unit_vector(cylinder.rotation);
	normal = vector_mul_n(rotation, -1);
	hit_ratio = vector_dot(normal, vector_mul_n(light_dir, -1.0));
	if (hit_ratio < 0.0)
		hit_ratio = 0.0;
	return (hit_ratio);
}

typedef struct s_extra
{
	double		hypo;
	double		distance;
	t_vector	center1;
	t_vector	center2;
	double		c1_dis;
	double		c2_dis;
	t_vector	normal;
	double		hit_ratio;
}				t_extra;

double	hit_ratio_cylinder_extra(t_cylinder cylinder,
	t_vector light_dir, t_obj_t closest)
{
	t_extra	extra;

	extra.hypo = vector_length(vector_sub(closest.intersection,
				closest.obj->cylinder->position));
	extra.distance = sqrt(extra.hypo * extra.hypo
			- closest.obj->cylinder->radius
			* closest.obj->cylinder->radius);
	extra.center1 = vector_add(closest.obj->cylinder->position,
			vector_mul_n(closest.obj->cylinder->rotation, extra.distance));
	extra.center2 = vector_sub(closest.obj->cylinder->position,
			vector_mul_n(closest.obj->cylinder->rotation, extra.distance));
	extra.c1_dis = vector_length(
			vector_sub(closest.intersection, extra.center1));
	extra.c2_dis = vector_length(
			vector_sub(closest.intersection, extra.center2));
	if (extra.c1_dis < extra.c2_dis)
		extra.normal = unit_vector(
				vector_sub(closest.intersection, extra.center1));
	else
		extra.normal = unit_vector(
				vector_sub(closest.intersection, extra.center2));
	extra.hit_ratio = vector_dot(extra.normal, vector_mul_n(light_dir, -1.0));
	if (extra.hit_ratio < 0.0)
		extra.hit_ratio = 0.0;
	return (extra.hit_ratio);
}
