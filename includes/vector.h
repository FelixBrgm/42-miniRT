#ifndef VECTOR
# define VECTOR

#include <math.h>


typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_mul(t_vector v1, t_vector v2);
t_vector	vector_mul_n(t_vector v, double n);
t_vector	vector_div_n(t_vector v, double n);
double		vector_dot(t_vector v1, t_vector v2);
t_vector	unit_vector(t_vector v);
double		vector_length(t_vector v);

#endif