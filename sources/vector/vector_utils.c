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

