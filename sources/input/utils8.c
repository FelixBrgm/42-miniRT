/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:00:46 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/21 01:59:29 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

int	parse_light(t_data *data, char *line)
{
	char	**line_split;
	char	**coords_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	coords_split = ft_split(line_split[1], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.light.position.x = ft_atof(coords_split[0]);
	data->scene.light.position.y = ft_atof(coords_split[1]);
	data->scene.light.position.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	data->scene.light.brightness = ft_atof(line_split[2]);
	free_split(line_split);
	return (0);
}

int	parse_sphere_util(t_data *data, char **line_split, int *obj_i)
{
	char		**coords_split;
	t_sphere	*sphere;

	coords_split = ft_split(line_split[3], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	sphere = data->scene.objs[*obj_i]->sphere;
	sphere->color.r = ft_atoi(coords_split[0]) / 255.0;
	sphere->color.g = ft_atoi(coords_split[1]) / 255.0;
	sphere->color.b = ft_atoi(coords_split[2]) / 255.0;
	free_split(coords_split);
	data->scene.objs[*obj_i]->plane = NULL;
	data->scene.objs[*obj_i]->cylinder = NULL;
	*obj_i = *obj_i + 1;
	free_split(line_split);
	return (0);
}

int	parse_sphere(t_data *data, char *line, int *obj_i)
{
	char	**line_split;
	char	**coords_split;

	data->scene.objs[*obj_i] = malloc(sizeof(t_obj));
	if (!data->scene.objs[*obj_i])
		return (-1);
	data->scene.objs[*obj_i]->sphere = malloc(sizeof(t_sphere));
	if (!data->scene.objs[*obj_i]->sphere)
		return (-1);
	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	coords_split = ft_split(line_split[1], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.objs[*obj_i]->sphere->position.x = ft_atof(coords_split[0]);
	data->scene.objs[*obj_i]->sphere->position.y = ft_atof(coords_split[1]);
	data->scene.objs[*obj_i]->sphere->position.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	data->scene.objs[*obj_i]->sphere->radius = ft_atof(line_split[2]) / 2;
	return (parse_sphere_util(data, line_split, obj_i));
}

int	parse_plane_util1(t_data *data, char **line_split, int *obj_i)
{
	char	**coords_split;

	coords_split = ft_split(line_split[1], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.objs[*obj_i]->plane->position.x = ft_atof(coords_split[0]);
	data->scene.objs[*obj_i]->plane->position.y = ft_atof(coords_split[1]);
	data->scene.objs[*obj_i]->plane->position.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	coords_split = ft_split(line_split[2], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.objs[*obj_i]->plane->rotation.x = ft_atof(coords_split[0]);
	data->scene.objs[*obj_i]->plane->rotation.y = ft_atof(coords_split[1]);
	data->scene.objs[*obj_i]->plane->rotation.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	return (0);
}

int	parse_plane_util2(t_data *data, char **line_split, int *obj_i)
{
	char	**coords_split;
	t_plane	*plane;

	coords_split = ft_split(line_split[3], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	plane = data->scene.objs[*obj_i]->plane;
	plane->color.r = ft_atoi(coords_split[0]) / 255.0;
	plane->color.g = ft_atoi(coords_split[1]) / 255.0;
	plane->color.b = ft_atoi(coords_split[2]) / 255.0;
	free_split(coords_split);
	data->scene.objs[*obj_i]->sphere = NULL;
	data->scene.objs[*obj_i]->cylinder = NULL;
	*obj_i = *obj_i + 1;
	free_split(line_split);
	return (0);
}
