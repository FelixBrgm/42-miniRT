#ifndef SCENE
# define SCENE

#include "miniRT.h"

typedef struct s_scene
{
	t_camera		camera;
	// t_light_ambient	light_ambient;
	t_obj			**objs;
	t_light			**light;
	
}				t_scene;


#endif
