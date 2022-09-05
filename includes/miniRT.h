#ifndef MINIRT
# define MINIRT

# include <stdio.h>
# include <stdlib.h>
# include "objects.h"
# include "scene.h"

typedef struct s_camera
{
	t_vector	position;
	t_vector	rotation;
	int			fov;
}				t_camera;

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

#endif