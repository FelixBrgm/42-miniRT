#ifndef VECTOR
# define VECTOR



typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_mul(t_vector v1, t_vector v2);
t_vector	vector_mul_n(t_vector v, double n);
t_vector	vector_div_n(t_vector v, double n);
double		vector_dot(t_vector v1, t_vector v2);

#endif