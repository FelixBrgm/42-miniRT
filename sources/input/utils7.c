/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:00:15 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/21 02:03:01 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

int	check_lines_util(t_list *line_list)
{
	char	*identifier;
	int		check_res;

	check_res = 0;
	identifier = get_identifier(line_list->content);
	if (!identifier)
		return (-1);
	if (!ft_strncmp(identifier, "A", 2))
		check_res = check_ambient(line_list->content);
	else if (!ft_strncmp(identifier, "C", 2))
		check_res = check_camera(line_list->content);
	else if (!ft_strncmp(identifier, "L", 2))
		check_res = check_light(line_list->content);
	else if (!ft_strncmp(identifier, "sp", 3))
		check_res = check_sphere(line_list->content);
	else if (!ft_strncmp(identifier, "pl", 3))
		check_res = check_plane(line_list->content);
	else if (!ft_strncmp(identifier, "cy", 3))
		check_res = check_cylinder(line_list->content);
	free(identifier);
	return (check_res);
}

int	check_lines(t_list *line_list)
{
	while (line_list)
	{
		if (check_lines_util(line_list) == -1)
			return (-1);
		line_list = line_list->next;
	}
	return (0);
}

int	parse_ambient(t_data *data, char *line)
{
	char	**line_split;
	char	**color_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	data->scene.ambient.ratio = ft_atof(line_split[1]);
	color_split = ft_split(line_split[2], ',');
	if (!color_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.ambient.color.r = ft_atoi(color_split[0]) / 255.0;
	data->scene.ambient.color.g = ft_atoi(color_split[1]) / 255.0;
	data->scene.ambient.color.b = ft_atoi(color_split[2]) / 255.0;
	free_split(color_split);
	free_split(line_split);
	return (0);
}

int	parse_camera_util(t_data *data, char **line_split)
{
	char	**coords_split;

	coords_split = ft_split(line_split[2], ',');
	if (!coords_split)
	{
		free_split(line_split);
		return (-1);
	}
	data->scene.camera.rotation.x = ft_atof(coords_split[0]);
	data->scene.camera.rotation.y = ft_atof(coords_split[1]);
	data->scene.camera.rotation.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	data->scene.camera.fov = ft_atoi(line_split[3]);
	free_split(line_split);
	return (0);
}

int	parse_camera(t_data *data, char *line)
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
	data->scene.camera.position.x = ft_atof(coords_split[0]);
	data->scene.camera.position.y = ft_atof(coords_split[1]);
	data->scene.camera.position.z = ft_atof(coords_split[2]);
	free_split(coords_split);
	if (parse_camera_util(data, line_split) == -1)
		return (-1);
	return (0);
}
