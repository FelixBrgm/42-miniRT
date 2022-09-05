#ifndef OBJECTS
# define OBJECTS

# include "miniRT.h"
# include "vector.h"
# include "plane.h"
# include "sphere.h"
# include "light.h"
# include "cylinder.h"
# include "colors.h"

typedef struct s_obj
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
}				t_obj;

#endif