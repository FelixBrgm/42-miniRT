/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:02:40 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/21 02:03:15 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

int	parse_lines_util(t_data *data, t_list *line_list, int *obj_i)
{
	char	*identifier;
	int		parse_res;

	parse_res = 0;
	identifier = get_identifier(line_list->content);
	if (!identifier)
		return (-1);
	if (!ft_strncmp(identifier, "A", 2))
		parse_res = parse_ambient(data, line_list->content);
	else if (!ft_strncmp(identifier, "C", 2))
		parse_res = parse_camera(data, line_list->content);
	else if (!ft_strncmp(identifier, "L", 2))
		parse_res = parse_light(data, line_list->content);
	else if (!ft_strncmp(identifier, "sp", 3))
		parse_res = parse_sphere(data, line_list->content, obj_i);
	else if (!ft_strncmp(identifier, "pl", 3))
		parse_res = parse_plane(data, line_list->content, obj_i);
	else if (!ft_strncmp(identifier, "cy", 3))
		parse_res = parse_cylinder(data, line_list->content, obj_i);
	free(identifier);
	if (parse_res == -1)
		return (-1);
	return (0);
}

int	parse_lines(t_data *data, t_list *line_list)
{
	int		obj_i;

	obj_i = 0;
	while (line_list)
	{
		if (parse_lines_util(data, line_list, &obj_i) == -1)
			return (-1);
		line_list = line_list->next;
	}
	return (0);
}

int	parse_input_util2(t_list *line_list, int ret)
{
	free_list(line_list);
	return (ret);
}

int	parse_input_util(t_data *data, t_list *line_list)
{
	int	obj_count;

	obj_count = check_identifiers(line_list);
	if (obj_count == -1)
	{
		ft_printf("Wrong identifiers.\n");
		return (parse_input_util2(line_list, -1));
	}
	if (check_lines(line_list) == -1)
	{
		ft_printf("Check error.\n");
		return (parse_input_util2(line_list, -1));
	}
	if (obj_count > 0)
	{
		data->scene.objs = malloc(sizeof(t_obj *) * (obj_count + 1));
		if (!data->scene.objs)
			return (parse_input_util2(line_list, -1));
		data->scene.objs[obj_count] = NULL;
	}
	return (0);
}
