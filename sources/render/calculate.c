#include "../../includes/render.h"


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
	if (discriminant <= 0)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}


double get_t_object(t_ray ray, t_data *data)
{
	double temp;
	double t;

	// t = hit_sphere(vector_create(data->scene.objs[0].sphere->position.x, data->scene.objs[0].sphere->position.y,
	// 		data->scene.objs[0].sphere->position.z), data->scene.objs[0].sphere->radius, ray);
	// temp = hit_sphere(vector_create(data->scene.objs[1].sphere->position.x, data->scene.objs[1].sphere->position.y,
	// 		data->scene.objs[1].sphere->position.z), data->scene.objs[1].sphere->radius, ray);

	t = hit_sphere(vector_create(10.0, 0.0, -20.0), 5, ray);
	temp = hit_sphere(vector_create(-10.0, 0.0, -20.0), 10, ray);
	if ((temp < t || t < 0) && 0 < temp)
		t = temp;

	return (t);
}



t_color ray_color(t_ray ray, t_data *data)
{
	double t = get_t_object(ray, data);

	if (t > 0.0)
	{
		t_vector intercection = vector_add(ray.origin, vector_mul_n(ray.direction, t));

		t_vector light = vector_create(300, 0.0, -20);
		t_ray lightRay = ray_create(intercection, unit_vector(vector_sub(light, intercection)));

		// double lightT = get_t_object(lightRay, data);
		// if (lightT > 0.0)
			// return (color_create(0,0,0));
		t_vector N = unit_vector(vector_sub(ray_at(ray, t), vector_create(0,0,-1)));
		t_vector res = vector_mul_n(vector_create(N.x + 1, N.y + 1, N.z + 1), 0.5);
		// return (color_create(1,0,0));
		return (color_create(res.x, res.y, res.z));
	}
	t_vector c1;
	c1.x = 1.0;
	c1.y = 1.0;
	c1.z = 1.0;
	t_vector c2;
	c2.x = 0.5;
	c2.y = 0.7;
	c2.z = 1.0;
	t_vector res;

	t_vector unitDirection = unit_vector(ray.direction);
	t = 0.5 * (unitDirection.y + 1.0);
	res = vector_add(vector_mul_n(c2, (1.0 - t)), vector_mul_n(c1, t));
	t_color color;
	color.r = res.x;
	color.g = res.y;
	color.b = res.z;
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

