#include "../../includes/vector.h"

t_vector at(t_vector p, t_vector dir, double t)
{
	return vector_add(p, vector_mul_n(dir, t));
}
