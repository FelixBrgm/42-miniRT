/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:54:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:03:07 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// void	free_split(char **split)
// {
// 	int	i;

// 	if (!split)
// 		return ;
// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		split[i] = NULL;
// 		i++;
// 	}
// 	free(split);
// 	split = NULL;
// }

// void	free_list(t_list *list)
// {
// 	t_list	*current;
// 	t_list	*temp;

// 	if (!list)
// 		return ;
// 	current = list;
// 	while (current)
// 	{
// 		free(current->content);
// 		temp = current;
// 		current = current->next;
// 		free(temp);
// 	}
// }

// int	check_arguments(int argc, char **argv)
// {
// 	int	arg_len;
// 	int	fd;

// 	if (argc > 2)
// 		return (-1);
// 	arg_len = ft_strlen(argv[1]);
// 	if (arg_len < 4)
// 		return (-1);
// 	if (ft_strncmp((argv[1] + arg_len - 3), ".rt", 4))
// 		return (-1);
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	return (fd);
// }

// int	read_into_list(int fd, t_list **line_list)
// {
// 	t_list	*new_item;
// 	char	*line;
// 	int		eof;

// 	eof = 0;
// 	while (!eof)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			eof = 1;
// 		else if (ft_strncmp(line, "\n", 2))
// 		{
// 			new_item = ft_lstnew((void *)(ft_strdup(line)));
// 			if (!new_item->content)
// 			{
// 				close(fd);
// 				return (-1);
// 			}
// 			ft_lstadd_back(line_list, new_item);
// 		}
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

// char	*get_identifier(char *line)
// {
// 	char	*identifier;
// 	int		i;

// 	i = 0;
// 	while (line[i] != ' ')
// 	{
// 		if (line[i] == '\0')
// 		{
// 			ft_printf("No spaces\n");
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	identifier = ft_substr(line, 0, i);
// 	if (!identifier)
// 		return (NULL);
// 	return (identifier);
// }

// int	check_identifier(char *identifier, int identifier_count[4])
// {
// 	if (!ft_strncmp(identifier, "A", 2))
// 	{
// 		identifier_count[0] = identifier_count[0] + 1;
// 		return (0);
// 	}
// 	else if (!ft_strncmp(identifier, "C", 2))
// 	{
// 		identifier_count[1] = identifier_count[1] + 1;
// 		return (0);
// 	}
// 	else if (!ft_strncmp(identifier, "L", 2))
// 	{
// 		identifier_count[2] = identifier_count[2] + 1;
// 		return (0);
// 	}
// 	else if (!ft_strncmp(identifier, "pl", 3)
// 		|| !ft_strncmp(identifier, "sp", 3)
// 		|| !ft_strncmp(identifier, "cy", 3))
// 	{
// 		identifier_count[3] = identifier_count[3] + 1;
// 		return (0);
// 	}
// 	return (1);
// }

// int	check_identifiers(t_list *line_list)
// {
// 	char	*identifier;
// 	int		check_res;
// 	int		identifier_count[4];

// 	identifier_count[0] = 0;
// 	identifier_count[1] = 0;
// 	identifier_count[2] = 0;
// 	identifier_count[3] = 0;
// 	while (line_list)
// 	{
// 		identifier = get_identifier(line_list->content);
// 		if (!identifier)
// 			return (-1);
// 		check_res = check_identifier(identifier, identifier_count);
// 		free(identifier);
// 		if (check_res)
// 			return (-1);
// 		line_list = line_list->next;
// 	}
// 	if (identifier_count[0] > 1 || identifier_count[1] > 1
// 		|| identifier_count[2] > 1)
// 		return (-1);
// 	return (identifier_count[3]);
// }

// int	get_split_len(char **split)
// {
// 	int	len;

// 	len = 0;
// 	while (split[len])
// 		len++;
// 	return (len);
// }

// void	ft_atof_util(char *str, int i, float *result)
// {
// 	float	divider;

// 	if (str[i] == '.')
// 	{
// 		i++;
// 		divider = 10;
// 		while (str[i] >= '0' && str[i] <= '9')
// 		{
// 			*result = *result + (str[i] - '0') / divider;
// 			divider *= 10;
// 			i++;
// 		}
// 	}
// }

// float	ft_atof(char *str)
// {
// 	int		i;
// 	float	divider;
// 	float	negative;
// 	float	result;

// 	i = 0;
// 	negative = 0;
// 	result = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 		negative = 1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 			result = result * 10 + (str[i] - '0');
// 			i++;
// 	}
// 	ft_atof_util(str, i, &result);
// 	if (negative)
// 		return (-result);
// 	return (result);
// }

// int	check_float(char *line, int check_positive)
// {
// 	int	i;
// 	int	dot;

// 	i = 0;
// 	dot = 0;
// 	if (line[i] == '-')
// 		i++;
// 	if (line[i] == '.')
// 		return (-1);
// 	while (line[i] != '\0' && line[i] != '\n')
// 	{
// 		if (!ft_isdigit(line[i]))
// 		{
// 			if (line[i] == '.' && !dot && ft_isdigit(line[i + 1]))
// 				dot = 1;
// 			else
// 				return (-1);
// 		}
// 		i++;
// 	}
// 	if (check_positive)
// 		if (ft_atof(line) < 0)
// 			return (-1);
// 	return (0);
// }

// int	check_float_range(char *line, float min, float max)
// {
// 	float	number;

// 	if (check_float(line, 0) == -1)
// 		return (-1);
// 	number = ft_atof(line);
// 	if (number < min || number > max)
// 		return (-1);
// 	return (0);
// }

// int	check_int(char *line)
// {
// 	int	i;

// 	i = 0;
// 	if (line[0] == '-')
// 		i++;
// 	while (line[i] != '\0' && line[i] != '\n')
// 	{
// 		if (!ft_isdigit(line[i]))
// 			return (-1);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_int_range(char *line, float min, float max)
// {
// 	int	number;

// 	if (check_int(line) == -1)
// 		return (-1);
// 	number = ft_atoi(line);
// 	if (number < min || number > max)
// 		return (-1);
// 	return (0);
// }

// int	check_coords_util(char **coords_split)
// {
// 	int	i;

// 	i = 0;
// 	while (coords_split[i])
// 	{
// 		if (coords_split[i][0] == '\0' || coords_split[i][0] == '\n')
// 		{
// 			ft_printf("Wrong coordinate format.\n");
// 			free_split(coords_split);
// 			return (-1);
// 		}
// 		if (check_float(coords_split[i], 0) == -1)
// 		{
// 			ft_printf("Wrong coordinate format.\n");
// 			free_split(coords_split);
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	check_coords(char *coords_line)
// {
// 	char	**coords_split;

// 	coords_split = ft_split(coords_line, ',');
// 	if (!coords_split)
// 		return (-1);
// 	if (get_split_len(coords_split) != 3)
// 	{
// 		ft_printf("Wrong amount of elements for coordinates.\n");
// 		free_split(coords_split);
// 		return (-1);
// 	}
// 	if (check_coords_util(coords_split) == -1)
// 		return (-1);
// 	free_split(coords_split);
// 	return (0);
// }

// int	check_color_util(char **color_split, int *i)
// {
// 	int	number;

// 	while (color_split[*i])
// 	{
// 		if (color_split[*i][0] == '\0' || color_split[*i][0] == '\n')
// 		{
// 			ft_printf("Wrong color format.\n");
// 			free_split(color_split);
// 			return (-1);
// 		}
// 		if (check_int(color_split[*i]) == -1)
// 		{
// 			ft_printf("Wrong color format.\n");
// 			free_split(color_split);
// 			return (-1);
// 		}
// 		number = ft_atoi(color_split[*i]);
// 		if (number < 0 || number > 255)
// 		{
// 			free_split(color_split);
// 			return (-1);
// 		}
// 		*i += 1;
// 	}
// 	return (0);
// }

// int	check_color(char *color_line)
// {
// 	char	**color_split;
// 	int		i;
// 	int		number;

// 	color_split = ft_split(color_line, ',');
// 	if (!color_split)
// 		return (-1);
// 	if (get_split_len(color_split) != 3)
// 	{
// 		ft_printf("Wrong amount of elements for color.\n");
// 		free_split(color_split);
// 		return (-1);
// 	}
// 	i = 0;
// 	if (check_color_util(color_split, &i) == -1)
// 		return (-1);
// 	free_split(color_split);
// 	return (0);
// }

// void	check_normalized_util(char **line_split, float vec[3])
// {
// 	vec[0] = ft_atof(line_split[0]);
// 	vec[1] = ft_atof(line_split[1]);
// 	vec[2] = ft_atof(line_split[2]);
// }

// int	check_normalized(char *line)
// {
// 	char		**line_split;
// 	float		vec[3];
// 	float		vec_length;

// 	if (check_coords(line) == -1)
// 		return (-1);
// 	line_split = ft_split(line, ',');
// 	if (!line_split)
// 		return (-1);
// 	check_normalized_util(line_split, vec);
// 	if (vec[0] < -1.0 || vec[0] > 1.0 || vec[1] < -1.0 || vec[1] > 1.0
// 		|| vec[2] < -1.0 || vec[2] > 1.0)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	vec_length = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
// 	if (vec_length != 1.0)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	free_split(line_split);
// 	return (0);
// }

// int	check_ambient(char *line)
// {
// 	char	**line_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (get_split_len(line_split) != 3)
// 	{
// 		ft_printf("Wrong amount of elements for ambient.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_float_range(line_split[1], 0.0, 1.0) == -1)
// 	{
// 		ft_printf("Wrong lighting ratio format.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_color(line_split[2]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	free_split(line_split);
// 	return (0);
// }

// int	check_camera_util(char **line_split)
// {
// 	if (check_normalized(line_split[2]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_int_range(line_split[3], 0, 179) == -1)
// 	{
// 		ft_printf("Wrong FOV format.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	free_split(line_split);
// 	return (0);
// }

// int	check_camera(char *line)
// {
// 	char	**line_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (get_split_len(line_split) != 4)
// 	{
// 		ft_printf("Wrong amount of elements for camera.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_coords(line_split[1]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_camera_util(line_split) == -1)
// 		return (-1);
// 	return (0);
// }

// int	check_light(char *line)
// {
// 	char	**line_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (get_split_len(line_split) != 3)
// 	{
// 		ft_printf("Wrong amount of elements for light.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_coords(line_split[1]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_float_range(line_split[2], 0.0, 1.0) == -1)
// 	{
// 		ft_printf("Wrong brightness format.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	free_split(line_split);
// 	return (0);
// }

// int	check_sphere_util(char **line_split)
// {
// 	if (check_float(line_split[2], 1) == -1)
// 	{
// 		ft_printf("Wrong diameter format.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_color(line_split[3]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	free_split(line_split);
// 	return (0);
// }

// int	check_sphere(char *line)
// {
// 	char	**line_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (get_split_len(line_split) != 4)
// 	{
// 		ft_printf("Wrong amount of elements for sphere.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_coords(line_split[1]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_sphere_util(line_split) == -1)
// 		return (-1);
// 	return (0);
// }

// int	check_plane_util(char **line_split)
// {
// 	if (check_normalized(line_split[2]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_color(line_split[3]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	free_split(line_split);
// 	return (0);
// }

// int	check_plane(char *line)
// {
// 	char	**line_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (get_split_len(line_split) != 4)
// 	{
// 		ft_printf("Wrong amount of elements for plane.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_coords(line_split[1]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_plane_util(line_split) == -1)
// 		return (-1);
// 	return (0);
// }

// int	check_cylinder_util(char **line_split)
// {
// 	if (check_float(line_split[3], 1) == -1)
// 	{
// 		ft_printf("Wrong diameter format.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_float(line_split[4], 1) == -1)
// 	{
// 		ft_printf("Wrong height format.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_color(line_split[5]) == -1)
// 	{
// 		ft_printf("Wrong color format.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	free_split(line_split);
// 	return (0);
// }

// int	check_cylinder(char *line)
// {
// 	char	**line_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (get_split_len(line_split) != 6)
// 	{
// 		ft_printf("Wrong amount of elements for cylinder.\n");
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_coords(line_split[1]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_normalized(line_split[2]) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (check_cylinder_util(line_split) == -1)
// 		return (-1);
// 	return (0);
// }

// int	check_lines_util(t_list *line_list)
// {
// 	char	*identifier;
// 	int		check_res;

// 	identifier = get_identifier(line_list->content);
// 	if (!identifier)
// 		return (-1);
// 	if (!ft_strncmp(identifier, "A", 2))
// 		check_res = check_ambient(line_list->content);
// 	else if (!ft_strncmp(identifier, "C", 2))
// 		check_res = check_camera(line_list->content);
// 	else if (!ft_strncmp(identifier, "L", 2))
// 		check_res = check_light(line_list->content);
// 	else if (!ft_strncmp(identifier, "sp", 3))
// 		check_res = check_sphere(line_list->content);
// 	else if (!ft_strncmp(identifier, "pl", 3))
// 		check_res = check_plane(line_list->content);
// 	else if (!ft_strncmp(identifier, "cy", 3))
// 		check_res = check_cylinder(line_list->content);
// 	free(identifier);
// 	return (check_res);
// }

// int	check_lines(t_list *line_list)
// {
// 	char	*identifier;
// 	int		check_res;

// 	while (line_list)
// 	{
// 		if (check_lines_util(line_list) == -1)
// 			return (-1);
// 		line_list = line_list->next;
// 	}
// 	return (0);
// }

// int	parse_ambient(t_data *data, char *line)
// {
// 	char	**line_split;
// 	char	**color_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	data->scene.ambient.ratio = ft_atof(line_split[1]);
// 	color_split = ft_split(line_split[2], ',');
// 	if (!color_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.ambient.color.r = ft_atoi(color_split[0]) / 255.0;
// 	data->scene.ambient.color.g = ft_atoi(color_split[1]) / 255.0;
// 	data->scene.ambient.color.b = ft_atoi(color_split[2]) / 255.0;
// 	free_split(color_split);
// 	free_split(line_split);
// 	return (0);
// }

// int	parse_camera_util(t_data *data, char **line_split)
// {
// 	char	**coords_split;

// 	coords_split = ft_split(line_split[2], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.camera.rotation.x = ft_atof(coords_split[0]);
// 	data->scene.camera.rotation.y = ft_atof(coords_split[1]);
// 	data->scene.camera.rotation.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	data->scene.camera.fov = ft_atoi(line_split[3]);
// 	free_split(line_split);
// 	return (0);
// }

// int	parse_camera(t_data *data, char *line)
// {
// 	char	**line_split;
// 	char	**coords_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	coords_split = ft_split(line_split[1], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.camera.position.x = ft_atof(coords_split[0]);
// 	data->scene.camera.position.y = ft_atof(coords_split[1]);
// 	data->scene.camera.position.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	if (parse_camera_util(data, line_split) == -1)
// 		return (-1);
// 	return (0);
// }

// int	parse_light(t_data *data, char *line)
// {
// 	char	**line_split;
// 	char	**coords_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	coords_split = ft_split(line_split[1], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.light.position.x = ft_atof(coords_split[0]);
// 	data->scene.light.position.y = ft_atof(coords_split[1]);
// 	data->scene.light.position.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	data->scene.light.brightness = ft_atof(line_split[2]);
// 	free_split(line_split);
// 	return (0);
// }

// int	parse_sphere_util(t_data *data, char **line_split, int *obj_i)
// {
// 	char		**coords_split;
// 	t_sphere	*sphere;

// 	coords_split = ft_split(line_split[3], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	sphere = data->scene.objs[*obj_i]->sphere;
// 	sphere->color.r = ft_atoi(coords_split[0]) / 255.0;
// 	sphere->color.g = ft_atoi(coords_split[1]) / 255.0;
// 	sphere->color.b = ft_atoi(coords_split[2]) / 255.0;
// 	free_split(coords_split);
// 	data->scene.objs[*obj_i]->plane = NULL;
// 	data->scene.objs[*obj_i]->cylinder = NULL;
// 	*obj_i = *obj_i + 1;
// 	free_split(line_split);
// 	return (0);
// }

// int	parse_sphere(t_data *data, char *line, int *obj_i)
// {
// 	char	**line_split;
// 	char	**coords_split;

// 	data->scene.objs[*obj_i] = malloc(sizeof(t_obj));
// 	if (!data->scene.objs[*obj_i])
// 		return (-1);
// 	data->scene.objs[*obj_i]->sphere = malloc(sizeof(t_sphere));
// 	if (!data->scene.objs[*obj_i]->sphere)
// 		return (-1);
// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	coords_split = ft_split(line_split[1], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.objs[*obj_i]->sphere->position.x = ft_atof(coords_split[0]);
// 	data->scene.objs[*obj_i]->sphere->position.y = ft_atof(coords_split[1]);
// 	data->scene.objs[*obj_i]->sphere->position.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	data->scene.objs[*obj_i]->sphere->radius = ft_atof(line_split[2]) / 2;
// 	return (parse_sphere_util(data, line_split, obj_i));
// }

// int	parse_plane_util1(t_data *data, char **line_split, int *obj_i)
// {
// 	char	**coords_split;

// 	coords_split = ft_split(line_split[1], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.objs[*obj_i]->plane->position.x = ft_atof(coords_split[0]);
// 	data->scene.objs[*obj_i]->plane->position.y = ft_atof(coords_split[1]);
// 	data->scene.objs[*obj_i]->plane->position.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	coords_split = ft_split(line_split[2], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.objs[*obj_i]->plane->rotation.x = ft_atof(coords_split[0]);
// 	data->scene.objs[*obj_i]->plane->rotation.y = ft_atof(coords_split[1]);
// 	data->scene.objs[*obj_i]->plane->rotation.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	return (0);
// }

// int	parse_plane_util2(t_data *data, char **line_split, int *obj_i)
// {
// 	char	**coords_split;
// 	t_plane	*plane;

// 	coords_split = ft_split(line_split[3], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	plane = data->scene.objs[*obj_i]->plane;
// 	plane->color.r = ft_atoi(coords_split[0]) / 255.0;
// 	plane->color.g = ft_atoi(coords_split[1]) / 255.0;
// 	plane->color.b = ft_atoi(coords_split[2]) / 255.0;
// 	free_split(coords_split);
// 	data->scene.objs[*obj_i]->sphere = NULL;
// 	data->scene.objs[*obj_i]->cylinder = NULL;
// 	*obj_i = *obj_i + 1;
// 	free_split(line_split);
// 	return (0);
// }

// int	parse_plane(t_data *data, char *line, int *obj_i)
// {
// 	char	**line_split;

// 	data->scene.objs[*obj_i] = malloc(sizeof(t_obj));
// 	if (!data->scene.objs[*obj_i])
// 		return (-1);
// 	data->scene.objs[*obj_i]->plane = malloc(sizeof(t_plane));
// 	if (!data->scene.objs[*obj_i]->plane)
// 		return (-1);
// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (parse_plane_util1(data, line_split, obj_i) == -1)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	if (parse_plane_util2(data, line_split, obj_i) == -1)
// 		return (-1);
// 	return (0);
// }

// int	parse_cylinder_util1(t_data *data, char **line_split, int *obj_i)
// {
// 	char	**coords_split;

// 	coords_split = ft_split(line_split[1], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.objs[*obj_i]->cylinder->position.x = ft_atof(coords_split[0]);
// 	data->scene.objs[*obj_i]->cylinder->position.y = ft_atof(coords_split[1]);
// 	data->scene.objs[*obj_i]->cylinder->position.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	return (0);
// }

// int	parse_cylinder_util2(t_data *data, char **line_split, int *obj_i)
// {
// 	char	**coords_split;

// 	coords_split = ft_split(line_split[2], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	data->scene.objs[*obj_i]->cylinder->rotation.x = ft_atof(coords_split[0]);
// 	data->scene.objs[*obj_i]->cylinder->rotation.y = ft_atof(coords_split[1]);
// 	data->scene.objs[*obj_i]->cylinder->rotation.z = ft_atof(coords_split[2]);
// 	free_split(coords_split);
// 	data->scene.objs[*obj_i]->cylinder->radius = ft_atof(line_split[3]) / 2;
// 	data->scene.objs[*obj_i]->cylinder->height = ft_atof(line_split[4]);
// 	return (0);
// }

// int	parse_cylinder_util3(t_data *data, char **line_split, int *obj_i)
// {
// 	char		**coords_split;
// 	t_cylinder	*cylinder;

// 	coords_split = ft_split(line_split[5], ',');
// 	if (!coords_split)
// 	{
// 		free_split(line_split);
// 		return (-1);
// 	}
// 	cylinder = data->scene.objs[*obj_i]->cylinder;
// 	cylinder->color.r = ft_atoi(coords_split[0]) / 255;
// 	cylinder->color.g = ft_atoi(coords_split[1]) / 255;
// 	cylinder->color.b = ft_atoi(coords_split[2]) / 255;
// 	free_split(coords_split);
// 	data->scene.objs[*obj_i]->sphere = NULL;
// 	data->scene.objs[*obj_i]->plane = NULL;
// 	*obj_i = *obj_i + 1;
// 	free_split(line_split);
// 	return (0);
// }

// int	parse_cylinder(t_data *data, char *line, int *obj_i)
// {
// 	char	**line_split;

// 	data->scene.objs[*obj_i] = malloc(sizeof(t_obj));
// 	if (!data->scene.objs[*obj_i])
// 		return (-1);
// 	data->scene.objs[*obj_i]->cylinder = malloc(sizeof(t_cylinder));
// 	if (!data->scene.objs[*obj_i]->cylinder)
// 		return (-1);
// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return (-1);
// 	if (parse_cylinder_util1(data, line_split, obj_i) == -1)
// 		return (-1);
// 	if (parse_cylinder_util2(data, line_split, obj_i) == -1)
// 		return (-1);
// 	if (parse_cylinder_util3(data, line_split, obj_i) == -1)
// 		return (-1);
// 	return (0);
// }

// int	parse_lines_util(t_data *data, t_list *line_list, int *obj_i)
// {
// 	char	*identifier;
// 	int		parse_res;

// 	identifier = get_identifier(line_list->content);
// 	if (!identifier)
// 		return (-1);
// 	if (!ft_strncmp(identifier, "A", 2))
// 		parse_res = parse_ambient(data, line_list->content);
// 	else if (!ft_strncmp(identifier, "C", 2))
// 		parse_res = parse_camera(data, line_list->content);
// 	else if (!ft_strncmp(identifier, "L", 2))
// 		parse_res = parse_light(data, line_list->content);
// 	else if (!ft_strncmp(identifier, "sp", 3))
// 		parse_res = parse_sphere(data, line_list->content, obj_i);
// 	else if (!ft_strncmp(identifier, "pl", 3))
// 		parse_res = parse_plane(data, line_list->content, obj_i);
// 	else if (!ft_strncmp(identifier, "cy", 3))
// 		parse_res = parse_cylinder(data, line_list->content, obj_i);
// 	free(identifier);
// 	if (parse_res == -1)
// 		return (-1);
// 	return (0);
// }

// int	parse_lines(t_data *data, t_list *line_list)
// {
// 	int		obj_i;

// 	obj_i = 0;
// 	while (line_list)
// 	{
// 		if (parse_lines_util(data, line_list, &obj_i) == -1)
// 			return (-1);
// 		line_list = line_list->next;
// 	}
// 	return (0);
// }

// int	parse_input_util2(t_list *line_list, int ret)
// {
// 	free_list(line_list);
// 	return (ret);
// }

// int	parse_input_util(t_data *data, t_list *line_list)
// {
// 	int	obj_count;

// 	obj_count = check_identifiers(line_list);
// 	if (obj_count == -1)
// 	{
// 		ft_printf("Wrong identifiers.\n");
// 		return (parse_input_util2(line_list, -1));
// 	}
// 	if (check_lines(line_list) == -1)
// 	{
// 		ft_printf("Check error.\n");
// 		return (parse_input_util2(line_list, -1));
// 	}
// 	if (obj_count > 0)
// 	{
// 		data->scene.objs = malloc(sizeof(t_obj *) * (obj_count + 1));
// 		if (!data->scene.objs)
// 			return (parse_input_util2(line_list, -1));
// 		data->scene.objs[obj_count] = NULL;
// 	}
// 	return (0);
// }

int	parse_input(t_data *data, int argc, char **argv)
{
	int		fd;
	int		obj_count;
	t_list	*line_list;

	fd = check_arguments(argc, argv);
	if (fd == -1)
	{
		ft_printf("Error with argument\n");
		return (-1);
	}
	line_list = NULL;
	if (read_into_list(fd, &line_list) == -1)
		return (parse_input_util2(line_list, -1));
	if (parse_input_util(data, line_list) == -1)
		return (-1);
	if (parse_lines(data, line_list) == -1)
		return (parse_input_util2(line_list, -2));
	free_list(line_list);
	return (0);
}
