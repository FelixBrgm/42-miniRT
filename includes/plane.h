#ifndef PLANE
# define PLANE


# include "colors.h"
# include "vector.h"

typedef struct s_plane 
{
	t_vector	position;
	t_vector	rotation;
	t_colors	colors;
}				t_plane;

#endif