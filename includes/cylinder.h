/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:12:10 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:12:37 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vector.h"
# include "colors.h"

typedef struct s_cylinder
{
	t_vector	position;
	t_vector	rotation;
	t_color		color;
	double		radius;
	double		height;
}				t_cylinder;

#endif