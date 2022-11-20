/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:34:52 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:28:41 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_color	color_calculate_light(t_data *data, t_obj_t closest);

t_color	color_calculate(t_data *data, t_ray ray)
{
	t_obj_t	closest;

	closest = hit_closest_obj(data, ray);
	if (closest.t <= 0.0)
		return (color_create(100, 100, 100));
	return (color_calculate_light(data, closest));
}

t_color	get_color_of_object(t_obj obj)
{
	if (obj.plane)
		return (obj.plane->color);
	if (obj.cylinder)
		return (obj.cylinder->color);
	if (obj.sphere)
		return (obj.sphere->color);
	return (color_create(1, 0, 0));
}
