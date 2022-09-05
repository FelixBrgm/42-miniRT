#ifndef MINIRT
# define MINIRT

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "vector.h"
# include "../libraries/libs/libs.h"
# include "scene.h"

typedef struct s_data
{
	t_scene scene;
}			t_data;

#endif