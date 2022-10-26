#include "../../includes/vector.h"
#include "../../includes/render.h"

t_vector ray_at(t_ray ray, double t)
{
	return (vector_add(ray.origin, vector_mul_n(ray.direction, t)));
}
t_ray ray_create(t_vector orig, t_vector dir)
{
	t_ray ray;

	ray.origin = orig;
	ray.direction = unit_vector(dir);
	return (ray);
}
t_ray ray_calculate(t_calculate cal_obj, int x, int y)
{
	double	u;
	double	v;
	t_ray	ray;
	
	u = (double) x / (double) (WIDTH - 1);
	v = (double) y / (double) (HEIGHT - 1);
	ray = ray_create(cal_obj.origin, 
		vector_sub(vector_add(cal_obj.lowerLeftCorner, vector_add(vector_mul_n(cal_obj.horizontal, u),
		vector_mul_n(cal_obj.vertical, v))), cal_obj.origin));
	return (ray);
}
