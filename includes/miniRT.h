#ifndef MINIRT
# define MINIRT

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# include "scene.h"
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

#ifndef ASPECT_RATIO
# define ASPECT_RATIO 16.0 / 9.0
# endif

#define VIEWPORT_HEIGHT 2.0
#define VIEWPORT_WIDTH VIEWPORT_HEIGHT * ASPECT_RATIO
#define FOCAL_LENGTH 5.0
#define T_MIN 0.0001

typedef struct s_data
{
	t_scene		scene;
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
	t_color		**img;
	int			pixel_samples;
}				t_data;

void	mlx_start(t_data *data);

#endif