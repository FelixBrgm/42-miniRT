#include "../../includes/render.h"

t_color color_calculate_light(t_data *data, t_ray ray, t_obj_t closest);
t_color get_color_of_object(t_obj obj);
t_color color_mul_n(t_color color, double n);

t_color color_calculate(t_data *data, t_ray ray)
{
	t_obj_t	closest;
	t_color	color;

	closest = hit_closest_obj(data, ray);
	if (closest.t <= 0.0)
		return (color_create(100,100,100));
	return (color_calculate_light(data, ray, closest));
}

t_color color_calculate_light(t_data *data, t_ray ray, t_obj_t closest)
{
	t_obj_t lightCollisions;
	t_ray	lightRay;
	double	t_light_max;

	t_light_max = vector_length(vector_sub(data->scene.light.position, ray.origin)) / vector_length(ray.direction);
	lightRay = ray_create(closest.intersection, vector_sub(data->scene.light.position, closest.intersection));
	lightCollisions = hit_closest_obj(data, lightRay);

	if (lightCollisions.t > 0.0 && lightCollisions.t < t_light_max)
		return (color_mul_n(get_color_of_object(*(closest.obj)), data->scene.ambient.ratio));
	return (get_color_of_object(*(closest.obj)));
	
}

t_color get_color_of_object(t_obj obj)
{
	if (obj.plane)
		return (obj.plane->color);
	if (obj.cylinder)
		return (obj.plane->color);
	if (obj.sphere)
		return (obj.sphere->color);
	return (color_create(1, 0, 0));
}

t_color color_create(double r, double g, double b)
{
	t_color color;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color color_mul_n(t_color color, double n)
{
	color.r *= n;
	color.g *= n;
	color.b *= n;
	return (color);
}