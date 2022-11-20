/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:14:53 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:18:16 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object.h"
# include "light.h"

typedef struct s_camera
{
	t_vector	position;
	t_vector	rotation;
	int			fov;
}				t_camera;

typedef struct s_scene
{
	t_camera		camera;
	t_ambient		ambient;
	t_obj			**objs;
	t_light			light;
}				t_scene;

#endif
