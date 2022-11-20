#include "../../includes/render.h"
#include "../../includes/miniRT.h"

// double	hit_object(t_obj obj, t_ray ray);
// double	hit_sphere(t_sphere sphere, t_ray ray);
// double	hit_plane(t_plane plane, t_ray ray);
// double	hit_cylinder(t_cylinder cylinder, t_ray ray);

// t_obj_t	hit_closest_obj(t_data *data, t_ray ray)
// {
// 	t_obj	**objs;
// 	t_obj_t	obj_closest;
// 	id_t	i;
// 	double	t;

// 	objs = data->scene.objs;
// 	obj_closest.obj = NULL;
// 	obj_closest.t = -1.0;
// 	t = -1.0;
// 	i = 0;
// 	while (objs && objs[i] != NULL)
// 	{
// 		t = hit_object(*(objs[i]), ray);
// 		if (t > 0 && (obj_closest.t < 0 || t < obj_closest.t))
// 		{
// 			obj_closest.t = t;
// 			obj_closest.obj = objs[i];
// 			obj_closest.intersection = vector_add(ray.origin,
// 					vector_mul_n(ray.direction, obj_closest.t));
// 		}
// 		i++;
// 	}
// 	return (obj_closest);
// }

// double	hit_object(t_obj obj, t_ray ray)
// {
// 	if (obj.sphere)
// 		return (hit_sphere(*(obj.sphere), ray));
// 	if (obj.plane)
// 		return (hit_plane(*(obj.plane), ray));
// 	if (obj.cylinder)
// 		return (hit_cylinder(*(obj.cylinder), ray));
// 	return (-1.0);
// }

// double	hit_sphere(t_sphere sphere, t_ray ray)
// {
// 	t_vector	oc;
// 	double		abc[3];
// 	double		discriminant;
// 	double		first_intersection;
// 	double		second_intersection;

// 	oc = vector_sub(ray.origin, sphere.position);
// 	abc[0] = vector_dot(ray.direction, ray.direction);
// 	abc[1] = vector_dot(oc, ray.direction) * 2.0;
// 	abc[2] = vector_dot(oc, oc) - sphere.radius * sphere.radius;
// 	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
// 	if (discriminant < 0.0)
// 		return (-1.0);
// 	else
// 	{
// 		first_intersection = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
// 		second_intersection = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);
// 		if (first_intersection < T_MIN)
// 		{
// 			if (second_intersection < T_MIN)
// 				return (-1.0);
// 			return (second_intersection);
// 		}
// 	}
// 	return (first_intersection);
// }

// double	hit_plane(t_plane plane, t_ray ray)
// {
// 	double	t;
// 	double	denom;

// 	denom = vector_dot(plane.rotation, ray.direction);
// 	if (denom < 0.0001 && denom > -0.0001)
// 		return (-1.0);
// 	t = vector_dot(vector_sub(plane.position, ray.origin),
// 			plane.rotation) / denom;
// 	if (t < 0.0001)
// 		return (-1.0);
// 	return (t);
// }

// double	hit_circle(t_cylinder cylinder, t_ray ray, int direction)
// {
// 	t_plane		plane;
// 	double		t;
// 	t_vector	inter;

// 	plane.position = vector_add(cylinder.position,
// 			vector_mul_n(unit_vector(cylinder.rotation),
// 				(cylinder.height / 2) * direction));
// 	plane.rotation = cylinder.rotation;
// 	t = hit_plane(plane, ray);
// 	if (t < 0)
// 		return (-1.0);
// 	inter = vector_add(ray.origin,
// 			vector_mul_n(unit_vector(ray.direction), t));
// 	if (vector_length(vector_sub(inter, plane.position)) > cylinder.radius)
// 		return (-1.0);
// 	return (t);
// }

double	check_cylinder_hit_distance(t_ray ray, t_cylinder cylinder, double t)
{
	t_vector	intersection;
	double		hypo;
	double		distance;

	intersection = vector_add(ray.origin, vector_mul_n(ray.direction, t));
	hypo = vector_length(vector_sub(intersection, cylinder.position));
	distance = sqrt(hypo * hypo - cylinder.radius * cylinder.radius);
	if (distance > cylinder.height / 2)
		t = -1.0;
	return (t);
}

void	get_abc(t_cylinder cyl, t_ray ray, double abc[3])
{
	t_vector	rotation;
	t_vector	new_ray_direction;
	t_vector	oc;

	rotation = vector_div_n(cyl.rotation, vector_length(cyl.rotation));
	new_ray_direction = vector_cross(ray.direction, rotation);
	oc = vector_sub(ray.origin, cyl.position);
	abc[0] = vector_dot(new_ray_direction, new_ray_direction);
	abc[1] = vector_dot(new_ray_direction, vector_cross(oc, rotation)) * 2.0;
	abc[2] = vector_dot(vector_cross(oc, rotation),
			vector_cross(oc, rotation)) - cyl.radius * cyl.radius;
}

double	hit_tube(t_cylinder cylinder, t_ray ray)
{
	double		tube_t;
	double		discriminant;
	double		abc[3];

	tube_t = -1.0;
	get_abc(cylinder, ray, abc);
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (-1.0);
	else
	{
		tube_t = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
		if (tube_t < T_MIN)
			tube_t = -1.0;
	}
	tube_t = check_cylinder_hit_distance(ray, cylinder, tube_t);
	return (tube_t);
}

double	hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	double	top_t;
	double	bot_t;
	double	tube_t;
	double	t;

	t = -1.0;
	top_t = hit_circle(cylinder, ray, 1);
	bot_t = hit_circle(cylinder, ray, -1);
	tube_t = hit_tube(cylinder, ray);
	if ((top_t < t || t < 0) && top_t >= 0)
		t = top_t;
	if ((bot_t < t || t < 0) && bot_t >= 0)
		t = bot_t;
	if ((tube_t < t || t < 0) && tube_t >= 0)
		t = tube_t;
	return (t);
}
