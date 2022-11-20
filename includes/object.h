/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:12:55 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:12:59 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "plane.h"
# include "sphere.h"
# include "cylinder.h"

typedef struct s_obj
{
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
}				t_obj;

#endif