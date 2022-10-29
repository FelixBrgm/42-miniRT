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

t_vector vector_cross(t_vector v1, t_vector v2)
{
	t_vector res;

	res.x = ((v1.y * v2.z) - (v1.z * v2.y));
	res.y = ((v1.z * v2.x) - (v1.x * v2.z));
	res.z = ((v1.x * v2.y) - (v1.y * v2.x));
	return (res);
}


t_vector	unit_vector(t_vector v)
{
	return vector_div_n(v, vector_length(v));
}

double		vector_length(t_vector v)
{
	return sqrt(vector_dot(v, v));
}


t_vector vector_create(double x, double y, double z)
{
	t_vector vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}
