#include "../../includes/render.h"
#include "../../includes/miniRT.h"
#include <stdio.h>
double	hit_object(t_obj obj, t_ray ray);
double hit_sphere(t_sphere sphere, t_ray ray);
double hit_plane(t_plane plane, t_ray ray);
double hit_cylinder(t_cylinder cylinder, t_ray ray);

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
	if(obj.plane)
		return (hit_plane(*(obj.plane), ray));
	if(obj.cylinder)
		return (hit_cylinder(*(obj.cylinder), ray));
	return (-1.0);
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

double hit_plane(t_plane plane, t_ray ray)
{
	double	d;
	double	t;
	double	denom;

	denom = vector_dot(plane.rotation, ray.direction);
	if (denom < 0.0001 && denom > -0.0001)
		return (-1.0);

	// d = vector_dot(plane.position, vector_mul_n(plane.rotation, -1.0));
	// t = -(d + vector_dot(ray.origin, plane.rotation)) / vector_dot(ray.direction, plane.rotation);
	t = vector_dot(vector_sub(plane.position, ray.origin), plane.rotation) / denom;

	if (t < 0.0001)
		return (-1.0);

	return (t);
}

double hit_circle(t_cylinder cylinder, t_ray ray, int direction)
{
	t_plane plane;

	plane.position = vector_add(cylinder.position, vector_mul_n(unit_vector(cylinder.rotation), (cylinder.height / 2) * direction));
	plane.rotation = cylinder.rotation;
	double t = hit_plane(plane, ray);
	if (t < 0)
		return (-1.0);
	t_vector intersection = vector_add(ray.origin, vector_mul_n(unit_vector(ray.direction), t));
	if (vector_length(vector_sub(intersection, plane.position)) > cylinder.radius)
		return (-1.0);
	return (t);
}

double hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	double top_t;
	double bot_t;
	double tube1_t, tube2_t;
	double t = -1.0;

	top_t = hit_circle(cylinder, ray, 1);
	bot_t = hit_circle(cylinder, ray, -1);

	t_vector rotation = vector_div_n(cylinder.rotation, vector_length(cylinder.rotation));
	double radius = cylinder.radius;
	tube1_t = -1.0;
	// hit tube
	t_vector new_ray_direction = vector_cross(ray.direction, rotation);
	t_vector oc = vector_sub(ray.origin, cylinder.position);
	double a = vector_dot(new_ray_direction, new_ray_direction);
	double b = vector_dot(new_ray_direction, vector_cross(oc, rotation)) * 2.0;
	double c = vector_dot(vector_cross(oc, rotation), vector_cross(oc, rotation)) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else
	{
		tube1_t = (-b - sqrt(discriminant)) / (2.0 * a);
		// tube2_t = (-b + sqrt(discriminant)) / (2.0 * a);
		if (tube1_t < T_MIN)
		{
			tube1_t = -1.0;
			// if (tube2_t < T_MIN)
				// return (-1.0);
			// return (tube2_t);
		}
	}
	// Check if hit is in range of cylinder height
	t_vector intersection = vector_add(ray.origin, vector_mul_n(ray.direction, tube1_t));
	double hypo = vector_length(vector_sub(intersection, cylinder.position));
	double distance = sqrt(hypo * hypo - cylinder.radius * cylinder.radius);
	if (distance > cylinder.height / 2)
		tube1_t = -1.0;
	// ===
	if ((top_t < t || t < 0) && top_t >= 0)
		t = top_t;
	if ((bot_t < t || t < 0) && bot_t >= 0)
		t = bot_t;
	if ((tube1_t < t || t < 0) && tube1_t >= 0)
		t = tube1_t;
	return (t);
}


// Vector3 Intersect(Vector3 planeP, Vector3 planeN, Vector3 rayP, Vector3 rayD)
// {
//     var d = Vector3.Dot(planeP, -planeN);
//     var t = -(d + Vector3.Dot(rayP, planeN)) / Vector3.Dot(rayD, planeN);
//     return rayP + t * rayD;
// }