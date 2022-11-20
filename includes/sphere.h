/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:15:06 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:15:13 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "colors.h"
# include "vector.h"

typedef struct s_sphere
{
	t_vector	position;
	t_color		color;
	double		radius;
}				t_sphere;

#endif