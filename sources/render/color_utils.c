/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:09:12 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:10:31 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

t_color	color_create(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	color_mul_n(t_color color, double n)
{
	color.r *= n;
	color.g *= n;
	color.b *= n;
	return (color);
}

t_color	color_div_n(t_color color, double n)
{
	color.r /= n;
	color.g /= n;
	color.b /= n;
	return (color);
}

t_color	color_add(t_color color1, t_color color2)
{
	t_color	result;

	result.r = (color1.r + color2.r) / 2;
	result.g = (color1.g + color2.g) / 2;
	result.b = (color1.b + color2.b) / 2;
	return (result);
}

t_color	color_mul(t_color v1, t_color v2)
{
	t_color	v;

	v.r = v1.r * v2.r;
	v.g = v1.g * v2.g;
	v.b = v1.b * v2.b;
	return (v);
}
