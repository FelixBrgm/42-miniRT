#include "../../includes/render.h"

t_color color_calculate_light(t_data *data, t_ray ray, t_obj_t closest);
t_color get_color_of_object(t_obj obj);
t_color color_mul_n(t_color color, double n);
t_color color_add(t_color color1, t_color color2);
t_color	color_mul(t_color v1, t_color v2);

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
	t_vector	normal;
	double	t_light_max;

	t_light_max = vector_length(vector_sub(data->scene.light.position, ray.origin)) / vector_length(ray.direction);
	lightRay = ray_create(closest.intersection, vector_sub(data->scene.light.position, closest.intersection));
	lightCollisions = hit_closest_obj(data, lightRay);

	t_vector lightDir = unit_vector(vector_sub(closest.intersection, data->scene.light.position));
	if (closest.obj->sphere)
		normal = unit_vector(vector_sub(closest.intersection, closest.obj->sphere->position));
	if (closest.obj->plane)
		normal = unit_vector(vector_sub(closest.intersection, closest.obj->plane->position));
	double	hitRatio = vector_dot(normal, vector_mul_n(lightDir, -1.0));
	t_color ambient_color = color_mul_n(data->scene.ambient.color, data->scene.ambient.ratio);

	if (lightCollisions.t > 0.0 && lightCollisions.t < t_light_max)
	{
		t_color shadow = get_color_of_object(*(closest.obj));
		shadow = color_mul_n(color_add(shadow, ambient_color), data->scene.ambient.ratio);
		// shadow = color_mul(shadow, color_mul_n(data->scene.ambient.color, data->scene.ambient.ratio));
		return (shadow);
	}
	if (hitRatio < 0.0)
		hitRatio = 0.0;
	t_color color = get_color_of_object(*(closest.obj));
	double brightness = hitRatio + data->scene.ambient.ratio;
	if (brightness > 1.0)
		brightness = 1.0;
	color = color_mul_n(color_add(color, ambient_color), brightness);
	// color = color_mul(color, color_mul_n(data->scene.ambient.color, brightness));

	return (color);
}

t_color get_color_of_object(t_obj obj)
{
	if (obj.plane)
		return (obj.plane->color);
	if (obj.cylinder)
		return (obj.cylinder->color);
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

t_color color_add(t_color color1, t_color color2)
{
	t_color result;
	result.r = (color1.r + color2.r) / 2;
	result.g = (color1.g + color2.g) / 2;
	result.b = (color1.b + color2.b) / 2;
	return (result);
}

t_color	color_mul(t_color v1, t_color v2)
{
	t_color	v;

	v.r = v1.r * v2.r;
	v.g = v1.g * v2.g;
	v.b = v1.b * v2.b;
	return (v);
}