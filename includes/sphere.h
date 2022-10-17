#ifndef SPHERE
# define SPHERE

# include "colors.h"
# include "vector.h"

typedef struct s_sphere
{
	t_vector	position;
	t_colors	color;
	float		radius;
}				t_sphere;

#endif