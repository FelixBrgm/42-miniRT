/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:49:32 by fbruggem          #+#    #+#             */
/*   Updated: 2022/09/05 11:17:05 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT
# define MINIRT

typedef struct s_camera
{
	t_vector	position;
	t_vector	rotation;
	int			fov;
}				t_camera;

typedef struct s_obj
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
}				t_obj;

typedef struct s_plane 
{
	t_vector	position;
	t_vector	rotation;
	t_colors	colors;
}				t_plane;

typedef struct s_sphere
{
	t_vector	position;
	t_color		color;
	double		radius
}				t_sphere;

typedef struct s_cylinder
{
	t_vector	position;
	t_vector	rotation;
	t_color		color;
	double		radius;
	double		height;
}				t_cylinder;

typedef struct s_ligth
{
	t_vector	position;
	double		brightness;
}				t_light;


typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}				t_colors;


typedef struct s_scene
{
	t_camera		camera;
	t_light_ambient	light_ambient;
	t_obj			**objs;
	t_light			**light;
	
}				t_scene;



#endif