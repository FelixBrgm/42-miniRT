#include "../../includes/render.h"
#include "../../includes/miniRT.h"

double	hit_object(t_obj obj, t_ray ray);
double hit_sphere(t_sphere sphere, t_ray ray);

t_obj_t hit_closest_obj(t_data *data, t_ray ray)
{
	t_obj	**objs;
	t_obj_t	obj_closest;
	id_t	i;
	double	t;

	objs = data->scene.objs;
	obj_closest.obj = NULL;
	obj_closest.t = - 1.0;
	t = - 1.0;
	i = 0;
	while (objs && objs[i] != NULL)
	{
		t = hit_object(*(objs[i]), ray);
		if (t > 0 && (obj_closest.t < 0 || t < obj_closest.t))
		{
			obj_closest.t = t;
			obj_closest.obj = objs[i];
			obj_closest.intersection = vector_add(ray.origin, vector_mul_n(ray.direction, obj_closest.t));
		}
		i++;
	}
	return (obj_closest);
}

double	hit_object(t_obj obj, t_ray ray)
{
	if(obj.sphere)
		return (hit_sphere(*(obj.sphere), ray));
	return (- 1.0);
}

double hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		firstIntersection;
	double		secondIntersection;
	
	oc = vector_sub(ray.origin, sphere.position);
	a = vector_dot(ray.direction, ray.direction);
	b = vector_dot(oc, ray.direction) * 2.0;
	c = vector_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = b*b - 4*a*c;
	if (discriminant < 0.0)
		return (-1.0);
	else
	{
		firstIntersection = (-b - sqrt(discriminant)) / (2.0 * a);
		secondIntersection = (-b + sqrt(discriminant)) / (2.0 * a);
		if (firstIntersection < T_MIN)
		{
			if (secondIntersection < T_MIN)
				return (-1.0);
			return (secondIntersection);
		}
	}
	return (firstIntersection);
}