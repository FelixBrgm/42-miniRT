#ifndef OBJECT
# define OBJECT

# include "plane.h"
# include "sphere.h"
# include "cylinder.h"

typedef struct s_obj
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
}				t_obj;

#endif