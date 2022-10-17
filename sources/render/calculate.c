#include "../../includes/render.h"

typedef struct s_ray
{
	t_vector origin;
	t_vector direction;
}				t_ray;

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

int hit_sphere(t_vector center, double radius, t_ray ray)
{
	t_vector oc = vector_sub(ray.origin, center);
	double a = vector_dot(ray.direction, ray.direction);
	double b = vector_dot(oc, ray.direction) * 2.0;
	double c = vector_dot(oc, oc) - radius* radius;
	// ft_printf("A: %d | B: %d | C: %d\n", a, b, c);
	double discriminant = b*b - 4*a*c;
	if (discriminant > 0)
		return (1);
	else
		return (0);
}


t_color ray_color(t_ray ray)
{
	if (hit_sphere(vector_create(0.0, 0.0, -1.0), 0.5, ray))
		return color_create(1.0, 0.0, 0.0);


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
	double t = 0.5 * (unitDirection.y + 1.0);
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

	t_vector origin = vector_create(0,0,0);
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
			t_color res = ray_color(r);
			int pos = j * WIDTH + i;
			data->img[pos]->r = res.r * 255;
			data->img[pos]->g = res.g * 255;
			data->img[pos]->b = res.b * 255;
			// ft_printf("POS: %i\n", pos);
			// ft_printf("COLOR: %i %i %i\n", data->img[pos]->r, res.r, res.g);
			x++;
		}
		
	}
	
}

