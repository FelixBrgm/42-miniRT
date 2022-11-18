#include "../../includes/render.h"

t_color color_calculate_light(t_data *data, t_ray ray, t_obj_t closest);
t_color get_color_of_object(t_obj obj);
t_color color_mul_n(t_color color, double n);
t_color color_div_n(t_color color, double n);
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

	double hitRatio = 1;
	// if (closest.obj->plane)
	// {
	// 	t_vector lightDir = unit_vector(vector_sub(closest.intersection, data->scene.light.position));
	// 	// t_vector normal = unit_vector(vector_sub(closest.intersection, closest.obj->sphere->position));
	// 	t_vector normal = unit_vector(closest.obj->plane->rotation);

	// 	hitRatio = vector_dot(normal, vector_mul_n(lightDir, -1.0));
	// 	if (hitRatio < 0.0)
	// 		hitRatio = 0.0;
	// }
	lightRay = ray_create(closest.intersection, vector_sub(data->scene.light.position, closest.intersection));
	t_light_max = vector_length(vector_sub(data->scene.light.position, lightRay.origin)) / vector_length(lightRay.direction);
	lightCollisions = hit_closest_obj(data, lightRay);
	// if (closest.obj->plane && closest.obj->plane->color.b == 1 && lightCollisions.t > 1.5)
	// 	printf("T: %f Tmax: %f %f %f %f\n", lightCollisions.t, t_light_max, lightCollisions.intersection.x, lightCollisions.intersection.y, lightCollisions.intersection.z);

	// HitAngle
	if (closest.obj->sphere)
	{
		t_vector lightDir = unit_vector(vector_sub(closest.intersection, data->scene.light.position));
		t_vector normal = unit_vector(vector_sub(closest.intersection, closest.obj->sphere->position));
		hitRatio = vector_dot(normal, vector_mul_n(lightDir, -1.0));
		if (hitRatio < 0.0)
			hitRatio = 0.0;
		// printf("DEGREE: %f\n", hitRatio);
	}
	else if (closest.obj->cylinder)
	{
		t_cylinder cylinder = *(closest.obj->cylinder);
		t_vector lightDir = unit_vector(vector_sub(closest.intersection, data->scene.light.position));
		t_vector rotation = unit_vector(cylinder.rotation);
		// check if intersection is on top or bottom cap of cylinder
		t_vector top_center = vector_add(cylinder.position, vector_mul_n(rotation, cylinder.height / 2));
		t_vector bot_center = vector_sub(cylinder.position, vector_mul_n(rotation, cylinder.height / 2));
		double dis1 = vector_length(vector_sub(closest.intersection, top_center));
		double dis2 = vector_length(vector_sub(closest.intersection, bot_center));
		if (dis1 <= cylinder.radius)
		{
			t_vector normal = rotation;
			hitRatio = vector_dot(normal, vector_mul_n(lightDir, -1.0));
			if (hitRatio < 0.0)
				hitRatio = 0.0;
		}
		else if (dis2 <= cylinder.radius)
		{
			t_vector normal = vector_mul_n(rotation, -1);
			hitRatio = vector_dot(normal, vector_mul_n(lightDir, -1.0));
			if (hitRatio < 0.0)
				hitRatio = 0.0;
		}
		else
		{
			// === get P ===
			double hypo = vector_length(vector_sub(closest.intersection, closest.obj->cylinder->position));
			double distance = sqrt(hypo * hypo - closest.obj->cylinder->radius * closest.obj->cylinder->radius);
			t_vector center1 = vector_add(closest.obj->cylinder->position, vector_mul_n(closest.obj->cylinder->rotation, distance));
			t_vector center2 = vector_sub(closest.obj->cylinder->position, vector_mul_n(closest.obj->cylinder->rotation, distance));
			double c1_dis = vector_length(vector_sub(closest.intersection, center1));
			double c2_dis = vector_length(vector_sub(closest.intersection, center2));
			t_vector normal;
			if (c1_dis < c2_dis)
				normal = unit_vector(vector_sub(closest.intersection, center1));
			else
				normal = unit_vector(vector_sub(closest.intersection, center2));
			// ===       ===
			hitRatio = vector_dot(normal, vector_mul_n(lightDir, -1.0));
			if (hitRatio < 0.0)
				hitRatio = 0.0;
			// printf("DEGREE: %f\n", hitRatio);
		}
	}
	double brightness = 1;
	double brightnessLessFactor = 0.01;
	double distance = vector_length(vector_sub(lightRay.origin, data->scene.light.position));
	if (distance > 1000000)
		brightness = 0;
	else
		brightness = (20 - log2(distance/brightnessLessFactor)) / 20;
	// && lightCollisions.t < t_light_max
	// bool isOk = vector_length(vector_sub(lightRay.origin, data->scene.light.position)) > vector_length(vector_sub(lightRay.origin, lightCollisions.intersection));
	if (brightness < brightnessLessFactor)
		return (color_create(0,0,0));
	t_color color = get_color_of_object(*(closest.obj));
	t_color ambient_color = color_mul_n(data->scene.ambient.color, data->scene.ambient.ratio);
	// apply ambient color
	color = color_div_n(color_add(color, ambient_color), 1 + data->scene.ambient.ratio);
	// ===
	// color = color_mul_n(color, brightness);
	// t_color shadow = color_mul_n(color_add(ambient_color, color), 0.5);
	// shadow = color_mul_n(shadow, data->scene.ambient.ratio);
	// shadow = color_mul_n(shadow, brightness);
	t_color shadow = color_mul_n(color, data->scene.light.brightness);
	shadow = color_mul_n(shadow, (0 + data->scene.ambient.ratio) / 2);
	shadow = color_mul_n(shadow, brightness);
	// color = color_add(color, color_mul_n(data->scene.ambient.color, data->scene.ambient.ratio));
	if (lightCollisions.t <= 0.0 || lightCollisions.t > t_light_max)
	{
		// color = color_mul_n(color_add(ambient_color, color), 0.5);
		color = color_mul_n(color, data->scene.light.brightness);
		color = color_mul_n(color, (hitRatio + data->scene.ambient.ratio) / 2);
		color = color_mul_n(color, brightness);
		// color = color_add(color, ambient_color);
		// color = color_mul_n(color_add(ambient_color, color), 0.5);
		return (color);
	}
	return (shadow);
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

t_color color_div_n(t_color color, double n)
{
	color.r /= n;
	color.g /= n;
	color.b /= n;
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