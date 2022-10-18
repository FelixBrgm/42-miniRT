#include "../../includes/render.h"

typedef struct s_obj_t
{
	double	t;
	t_obj	*obj;
}				t_obj_t;


t_ray ray_create(t_vector orig, t_vector dir)
{
	t_ray ray;

	ray.origin = orig;
	ray.direction = dir;
	return (ray);
}

t_vector vector_create(double x, double y, double z)
{
	t_vector vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}
t_color color_create(double r, double g, double b)
{
	t_color color;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

double hit_sphere(t_vector center, double radius, t_ray ray)
{
	t_vector oc = vector_sub(ray.origin, center);
	double a = vector_dot(ray.direction, ray.direction);
	double b = vector_dot(oc, ray.direction) * 2.0;
	double c = vector_dot(oc, oc) - radius* radius;
	// ft_printf("A: %d | B: %d | C: %d\n", a, b, c);
	double discriminant = b*b - 4*a*c;
	if (discriminant < 0.0)
		return -1.0;
	else
	{
		double res = (-b - sqrt(discriminant)) / (2.0 * a);
		if (res < 0.0001)
		{
			res = (-b + sqrt(discriminant)) / (2.0 * a);
			if (res < 0.0001)
				return (-1.0);
		}
		return (res);
	}
}


t_obj_t get_closest_obj(t_ray ray, t_data *data)
{
	double temp = -1.0;
	t_obj_t res;
	t_obj **objs;
	// CHANGE BOTH
	double t_max = vector_length(vector_sub(vector_create(100, 0.0, -20), ray.origin)) / vector_length(ray.direction);

	res.t = -1.0;
	res.obj = NULL;

	objs = data->scene.objs;

	int i = 0;
	while (objs[i] != NULL)
	{
		if (objs[i]->sphere)
		{
			t_sphere *s = objs[i]->sphere;
			temp = hit_sphere(vector_create(s->position.x, s->position.y, s->position.z), s->radius, ray);
		}
		if ((temp < res.t || res.t < 0) && temp > 0 && temp < t_max)
		{
			res.t = temp;
			res.obj = objs[i];
		}
		i++;
	}
	return (res);
}



t_color ray_color(t_ray ray, t_data *data)
{
	t_obj_t res = get_closest_obj(ray, data);

	if (res.t > 0.0)
	{
		t_vector intercection = vector_add(ray.origin, vector_mul_n(ray.direction, res.t));

		// CHANGE BOTH
		t_vector light = vector_create(100, 0.0, -20);
		t_ray lightRay = ray_create(intercection, unit_vector(vector_sub(light, intercection)));
		
		double r = (res.obj->sphere->color.r / 255) * ((data->scene.ambient.color.r / 255) * data->scene.ambient.ratio);
		double g = (res.obj->sphere->color.g / 255) * ((data->scene.ambient.color.g / 255) * data->scene.ambient.ratio);
		double b = (res.obj->sphere->color.b / 255) * ((data->scene.ambient.color.b / 255) * data->scene.ambient.ratio);
		double lightT = get_closest_obj(lightRay, data).t;
		if (lightT > 0.0)
			return (color_create(r, g, b));

		// return (color_create(r, g, b));
		return (color_create(res.obj->sphere->color.r / 255 ,res.obj->sphere->color.g / 255, res.obj->sphere->color.b / 255));
	}
	t_vector c1;
	c1.x = 1.0;
	c1.y = 1.0;
	c1.z = 1.0;
	t_vector c2;
	c2.x = 0.5;
	c2.y = 0.7;
	c2.z = 1.0;
	t_vector re;

	t_vector unitDirection = unit_vector(ray.direction);
	res.t = 0.5 * (unitDirection.y + 1.0);
	re = vector_add(vector_mul_n(c2, (1.0 - res.t)), vector_mul_n(c1, res.t));
	t_color color;
	color.r = re.x;
	color.g = re.y;
	color.b = re.z;
	// ft_printf("RCOLOR: %i %i %i\n", res.x, res.y, res.z);
	// ft_printf("RCOLOR: %i %i %i\n", color.r, color.g, color.b);
	return (color);
}


void	calculate(void *param)
{
	t_data *data;

	data = param;
	
	double aspectRatio = 16.0 / 9.0;

	double viewPortHeight = 2.0;
	double viewPortWidth = viewPortHeight * aspectRatio;
	double focal_length = 1.0;

	t_vector origin = vector_create(data->scene.camera.position.x, data->scene.camera.position.y, data->scene.camera.position.z);
	// t_vector origin = vector_create(0,0,0);
	t_vector horizontal = vector_create(viewPortWidth, 0, 0);
	t_vector vertical = vector_create(0, viewPortHeight, 0);
	t_vector focal = vector_create(0,0,focal_length);

	t_vector lowerLeftCorner = vector_sub(vector_sub(vector_sub(origin, vector_div_n(horizontal, 2)), vector_div_n(vertical, 2)), focal);

	int x = 0;
	for (size_t j = 0; j < HEIGHT; j++)
	{
		for (size_t i = 0; i < WIDTH; i++)
		{
			double u = (double) i / (double) (WIDTH -1);
			double v = (double) j / (double) (HEIGHT -1);
			// ft_printf("U: %f | V: %f\n", u, v);
			t_ray r = ray_create(origin, vector_sub(vector_add(lowerLeftCorner, vector_add(vector_mul_n(horizontal, u), vector_mul_n(vertical, v))), origin));
			t_color res = ray_color(r, data);
			int pos = j * WIDTH + i;
			data->img[pos]->r = res.r;
			data->img[pos]->g = res.g;
			data->img[pos]->b = res.b;
			// ft_printf("POS: %i\n", pos);
			// ft_printf("COLOR: %i %i %i\n", data->img[pos]->r, res.r, res.g);
			x++;
		}
		
	}
	
}

