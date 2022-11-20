/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:12:47 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:17:43 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# include "scene.h"
# include "../libraries/libs/libs.h"
# include "../libraries/mlxlib/include/MLX42/MLX42.h"

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef PIXELS
#  define PIXELS 2073600
# endif

# ifndef ASPECT_RATIO
#  define ASPECT_RATIO 1.7777777
# endif

# define VIEWPORT_HEIGHT 2.0
# define VIEWPORT_WIDTH 3.555555
# define FOCAL_LENGTH 1.0
# define T_MIN 0.0001

typedef struct s_data
{
	t_scene		scene;
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
	t_color		**img;
	int			pixel_samples;
}				t_data;

# include "parser.h"
# include "render.h"


void	mlx_start(t_data *data);

#endif