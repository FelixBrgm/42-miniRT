#ifndef CYLINDER
# define CYLINDER

# include "vector.h"
# include "colors.h"

typedef struct s_cylinder
{
	t_vector	position;
	t_vector	rotation;
	t_color		color;
	double		radius;
	double		height;
}				t_cylinder;

#endif