/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:12:02 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/21 01:53:08 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "miniRT.h"
# include "vector.h"
# include "colors.h"
# include "object.h"

typedef struct s_calculate
{
	t_vector	origin;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
}				t_calculate;

typedef struct s_obj_t
{
	double		t;
	t_vector	intersection;
	t_obj		*obj;
}				t_obj_t;

void		render(void *param);
void		calculate(t_data *data);

// Color
t_color		color_calculate(t_data *data, t_ray ray);
t_color		color_create(double r, double g, double b);

// Ray
t_ray		ray_calculate(t_calculate cal_obj, int x, int y);
t_ray		ray_create(t_vector orig, t_vector dir);
t_vector	ray_at(t_ray ray, double t);

// Hit
t_obj_t		hit_closest_obj(t_data *data, t_ray ray);
double		hit_object(t_obj obj, t_ray ray);
double		hit_sphere(t_sphere sphere, t_ray ray);
double		hit_plane(t_plane plane, t_ray ray);
double		hit_circle(t_cylinder cylinder, t_ray ray, int direction);
double		check_cylinder_hit_distance(
				t_ray ray, t_cylinder cylinder, double t);
void		get_abc(t_cylinder cyl, t_ray ray, double abc[3]);
double		hit_tube(t_cylinder cylinder, t_ray ray);
double		hit_cylinder(t_cylinder cylinder, t_ray ray);
t_obj_t		hit_closest_obj(t_data *data, t_ray ray);

// Color
t_color		color_mul_n(t_color color, double n);
t_color		color_div_n(t_color color, double n);
t_color		color_add(t_color color1, t_color color2);
t_color		color_mul(t_color v1, t_color v2);

#endif