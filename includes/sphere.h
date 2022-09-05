#ifndef SPHERE
# define SPHERE

# include "miniRT.h"
# include "colors.h"

typedef struct s_sphere
{
	t_vector	position;
	t_colors	color;
	double		radius;
}				t_sphere;

#endif