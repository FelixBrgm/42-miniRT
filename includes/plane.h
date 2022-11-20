/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:13:07 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:18:10 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "colors.h"
# include "vector.h"

typedef struct s_plane
{
	t_vector	position;
	t_vector	rotation;
	t_color		color;
}				t_plane;

#endif