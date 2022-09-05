#ifndef CYLINDER
# define CYLINDER

# include "miniRT.h"
# include "colors.h"


typedef struct s_cylinder
{
	t_vector	position;
	t_vector	rotation;
	t_colors	color;
	double		radius;
	double		height;
}				t_cylinder;

#endif