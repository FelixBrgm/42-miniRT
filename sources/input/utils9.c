/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:01:51 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/21 01:59:31 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

int	parse_plane(t_data *data, char *line, int *obj_i)
{
	char	**line_split;

	data->scene.objs[*obj_i] = malloc(sizeof(t_obj));
	if (!data->scene.objs[*obj_i])
		return (-1);
	data->scene.objs[*obj_i]->plane = malloc(sizeof(t_plane));
	if (!data->scene.objs[*obj_i]->plane)
		return (-1);
	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (parse_plane_util1(data, line_split, obj_i) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (parse_plane_util2(data, line_split, obj_i) == -1)
		return (-1);
	return (0);
}

int	parse_cylinder_util1(t_data *data, char **line_split, int *obj_i)
{
	char	**coords_split;

	coords_split = ft_split(line_split[1], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.objs[*obj_i]->cylinder->position.x = ft_atof(coords_split[0]);
	data->scene.objs[*obj_i]->cylinder->position.y = ft_atof(coords_split[1]);
	data->scene.objs[*obj_i]->cylinder->position.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	return (0);
}

int	parse_cylinder_util2(t_data *data, char **line_split, int *obj_i)
{
	char	**coords_split;

	coords_split = ft_split(line_split[2], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.objs[*obj_i]->cylinder->rotation.x = ft_atof(coords_split[0]);
	data->scene.objs[*obj_i]->cylinder->rotation.y = ft_atof(coords_split[1]);
	data->scene.objs[*obj_i]->cylinder->rotation.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	data->scene.objs[*obj_i]->cylinder->radius = ft_atof(line_split[3]) / 2;
	data->scene.objs[*obj_i]->cylinder->height = ft_atof(line_split[4]);
	return (0);
}

int	parse_cylinder_util3(t_data *data, char **line_split, int *obj_i)
{
	char		**coords_split;
	t_cylinder	*cylinder;

	coords_split = ft_split(line_split[5], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	cylinder = data->scene.objs[*obj_i]->cylinder;
	cylinder->color.r = ft_atoi(coords_split[0]) / 255;
	cylinder->color.g = ft_atoi(coords_split[1]) / 255;
	cylinder->color.b = ft_atoi(coords_split[2]) / 255;
	free_split(coords_split);
	data->scene.objs[*obj_i]->sphere = NULL;
	data->scene.objs[*obj_i]->plane = NULL;
	*obj_i = *obj_i + 1;
	free_split(line_split);
	return (0);
}

int	parse_cylinder(t_data *data, char *line, int *obj_i)
{
	char	**line_split;

	data->scene.objs[*obj_i] = malloc(sizeof(t_obj));
	if (!data->scene.objs[*obj_i])
		return (-1);
	data->scene.objs[*obj_i]->cylinder = malloc(sizeof(t_cylinder));
	if (!data->scene.objs[*obj_i]->cylinder)
		return (-1);
	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (parse_cylinder_util1(data, line_split, obj_i) == -1)
		return (-1);
	if (parse_cylinder_util2(data, line_split, obj_i) == -1)
		return (-1);
	if (parse_cylinder_util3(data, line_split, obj_i) == -1)
		return (-1);
	return (0);
}
