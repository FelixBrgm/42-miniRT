#ifndef OBJECTS
# define OBJECTS

#include "miniRT.h"

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
	t_colors	color;
	double		radius;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector	position;
	t_vector	rotation;
	t_colors	color;
	double		radius;
	double		height;
}				t_cylinder;

typedef struct s_light
{
	t_vector	position;
	double		brightness;
}				t_light;

#endif