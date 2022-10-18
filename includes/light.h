#ifndef LIGHT
# define LIGHT

# include "vector.h"
# include "colors.h"

typedef struct s_light
{
	t_vector	position;
	double		brightness;
}				t_light;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}				t_ambient;

#endif
