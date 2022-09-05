#ifndef SCENE
# define SCENE

# include "object.h"
# include "light.h"

typedef struct s_camera
{
	t_vector	position;
	t_vector	rotation;
	int			fov;
}				t_camera;

typedef struct s_scene
{
	t_camera		camera;
	// t_light_ambient	light_ambient;
	t_obj			**objs;
	t_light			**light;
	
}				t_scene;

#endif
