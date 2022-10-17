#include "../../includes/render.h"

t_color ray_color(t_vector origin, t_vector dir)
{
	t_vector c1;
	c1.x = 1.0;
	c1.y = 1.0;
	c1.z = 1.0;
	t_vector c2;
	c2.x = 0.5;
	c2.y = 0.7;
	c2.z = 1.0;
	t_vector res;

	t_vector unitDirection = unit_vector(dir);
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
	

	ft_printf("HELLO\n");
	data->img[0]->r = 123;

	double aspectRatio = 16.0/9.0;

	double viewPortHeight = 2.0;
	double viewPortWidth = viewPortHeight * aspectRatio;
	double focal_length = 1.0;

	t_vector origin;
	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
	t_vector horizontal;
	horizontal.x = viewPortWidth;
	horizontal.x = 0;
	horizontal.x = 0;
	t_vector vertical;
	vertical.x = 0;
	vertical.y = viewPortHeight;
	vertical.z = 0;
	t_vector focal;
	focal.x = 0;
	focal.y = 0;
	focal.z = focal_length;
	t_vector lowerLeftCorner = vector_sub(vector_sub(vector_sub(origin, vector_div_n(horizontal, 2)), vector_div_n(vertical, 2)), focal);

	int x = 0;
	for (size_t j = 0; j < HEIGHT; j++)
	{
		printf("LINE %zu\n", j);
		for (size_t i = 0; i < WIDTH; i++)
		{
			double u = (double) i / (double) (WIDTH -1);
			double v = (double) j / (double) (HEIGHT -1);
			t_color res = ray_color(origin, vector_sub(vector_add(lowerLeftCorner, vector_add(vector_mul_n(horizontal, u), vector_mul_n(vertical, v))), origin));
			int pos = j * WIDTH + i;
			data->img[x]->r = res.r * 255;
			data->img[x]->g = res.g * 255;
			data->img[x]->b = res.b * 255;
			// ft_printf("COLOR: %i %i %i\n", data->img[pos]->r, res.r, res.g);
			x++;
		}
		
	}
	
}

