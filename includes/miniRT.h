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

#ifndef WIDTH
# define WIDTH 1920
# endif

#ifndef HEIGHT
# define HEIGHT 1080
# endif

#ifndef PIXELS
# define PIXELS HEIGHT * WIDTH
# endif


typedef struct s_data
{
	t_scene		scene;
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
	t_color		**img;
}			t_data;

void	mlx_start(t_data *data);

#endif