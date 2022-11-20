/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:26:15 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/21 00:26:16 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"
#include "../../includes/miniRT.h"

double	check_cylinder_hit_distance(t_ray ray, t_cylinder cylinder, double t)
{
	t_vector	intersection;
	double		hypo;
	double		distance;

	intersection = vector_add(ray.origin, vector_mul_n(ray.direction, t));
	hypo = vector_length(vector_sub(intersection, cylinder.position));
	distance = sqrt(hypo * hypo - cylinder.radius * cylinder.radius);
	if (distance > cylinder.height / 2)
		t = -1.0;
	return (t);
}

void	get_abc(t_cylinder cyl, t_ray ray, double abc[3])
{
	t_vector	rotation;
	t_vector	new_ray_direction;
	t_vector	oc;

	rotation = vector_div_n(cyl.rotation, vector_length(cyl.rotation));
	new_ray_direction = vector_cross(ray.direction, rotation);
	oc = vector_sub(ray.origin, cyl.position);
	abc[0] = vector_dot(new_ray_direction, new_ray_direction);
	abc[1] = vector_dot(new_ray_direction, vector_cross(oc, rotation)) * 2.0;
	abc[2] = vector_dot(vector_cross(oc, rotation),
			vector_cross(oc, rotation)) - cyl.radius * cyl.radius;
}

double	hit_tube(t_cylinder cylinder, t_ray ray)
{
	double		tube_t;
	double		discriminant;
	double		abc[3];

	tube_t = -1.0;
	get_abc(cylinder, ray, abc);
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (-1.0);
	else
	{
		tube_t = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
		if (tube_t < T_MIN)
			tube_t = -1.0;
	}
	tube_t = check_cylinder_hit_distance(ray, cylinder, tube_t);
	return (tube_t);
}

double	hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	double	top_t;
	double	bot_t;
	double	tube_t;
	double	t;

	t = -1.0;
	top_t = hit_circle(cylinder, ray, 1);
	bot_t = hit_circle(cylinder, ray, -1);
	tube_t = hit_tube(cylinder, ray);
	if ((top_t < t || t < 0) && top_t >= 0)
		t = top_t;
	if ((bot_t < t || t < 0) && bot_t >= 0)
		t = bot_t;
	if ((tube_t < t || t < 0) && tube_t >= 0)
		t = tube_t;
	return (t);
}
