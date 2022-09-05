#ifndef MINIRT
# define MINIRT

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "vector.h"
# include "scene.h"
# include "render.h"
# include "../libraries/libs/libs.h"
# include "../libraries/mlxlib/include/MLX42/MLX42.h"

typedef struct s_data
{
	t_scene		scene;
	mlx_t		*mlx;
	mlx_image_t	*img;
}			t_data;

void	mlx_start(t_data *data);

#endif