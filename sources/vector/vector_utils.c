#include "../../includes/vector.h"

/**
 * @brief Calculates the dot product of 2 vectors
 */
double	vector_dot(t_vector v1, t_vector v2)
{
	double	dot;

	dot = 0;
	dot += v1.x * v2.x;
	dot += v1.y * v2.y;
	dot += v1.z * v2.z;
	return (dot);
}

t_vector	unit_vector(t_vector v)
{
	return vector_div_n(v, vector_length(v));
}

double		vector_length(t_vector v)
{
	return sqrt(vector_dot(v, v));
}

t_vector ray_at(t_ray ray, double t)
{
	return (vector_add(ray.origin, vector_mul_n(ray.direction, t)));
}