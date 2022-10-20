#ifndef RENDER
# define RENDER

# include "miniRT.h"
# include "vector.h"

typedef struct s_calculate
{
	t_vector origin;
	t_vector horizontal;
	t_vector vertical;
	t_vector lowerLeftCorner;
}				t_calculate;

typedef struct s_obj_t
{
	double		t;
	t_vector	intersection;
	t_obj		*obj;
}				t_obj_t;

void	render(void *param);
void	calculate(t_data *data);

// Color
t_color color_calculate(t_data *data, t_ray ray);
t_color color_create(double r, double g, double b);

// Ray
t_ray		ray_calculate(t_calculate cal_obj, int x, int y);
t_ray		ray_create(t_vector orig, t_vector dir);
t_vector	ray_at(t_ray ray, double t);

// Hit
t_obj_t hit_closest_obj(t_data *data, t_ray ray);

#endif