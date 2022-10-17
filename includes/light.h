#ifndef LIGHT
# define LIGHT

# include "vector.h"
# include "colors.h"

typedef struct s_light
{
	t_vector	position;
	float		brightness;
}				t_light;

typedef struct s_ambient
{
	float		ratio;
	t_colors	color;
}				t_ambient;

#endif
