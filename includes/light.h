/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:12:40 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:12:43 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"
# include "colors.h"

typedef struct s_light
{
	t_vector	position;
	double		brightness;
}				t_light;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}				t_ambient;

#endif
