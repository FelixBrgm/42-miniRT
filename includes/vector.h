/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:15:16 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:18:30 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_mul(t_vector v1, t_vector v2);
t_vector	vector_mul_n(t_vector v, double n);
t_vector	vector_div_n(t_vector v, double n);
double		vector_dot(t_vector v1, t_vector v2);
t_vector	vector_cross(t_vector v1, t_vector v2);
t_vector	unit_vector(t_vector v);
double		vector_length(t_vector v);
t_vector	vector_create(double x, double y, double z);

#endif