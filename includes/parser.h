/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:13:01 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 22:13:05 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "miniRT.h"
# include "../libraries/libs/libs.h"

int		parse_input(t_data *data, int argc, char **argv);
void	free_split(char **split);
void	free_list(t_list *list);
int		check_arguments(int argc, char **argv);
int		read_into_list(int fd, t_list **line_list);
char	*get_identifier(char *line);
int		check_identifier(char *identifier, int identifier_count[4]);
int		check_identifiers(t_list *line_list);
int		get_split_len(char **split);
void	ft_atof_util(char *str, int i, float *result);
float	ft_atof(char *str);
int		check_float(char *line, int check_positive);
int		check_float_range(char *line, float min, float max);
int		check_int(char *line);
int		check_int_range(char *line, float min, float max);
int		check_coords_util(char **coords_split);
int		check_coords(char *coords_line);
int		check_color_util(char **color_split, int *i);
int		check_color(char *color_line);
void	check_normalized_util(char **line_split, float vec[3]);
int		check_normalized(char *line);
int		check_ambient(char *line);
int		check_camera_util(char **line_split);
int		check_camera(char *line);
int		check_light(char *line);
int		check_sphere_util(char **line_split);
int		check_sphere(char *line);
int		check_plane_util(char **line_split);
int		check_plane(char *line);
int		check_cylinder_util(char **line_split);
int		check_cylinder(char *line);
int		check_lines_util(t_list *line_list);
int		check_lines(t_list *line_list);
int		parse_ambient(t_data *data, char *line);
int		parse_camera_util(t_data *data, char **line_split);
int		parse_camera(t_data *data, char *line);
int		parse_light(t_data *data, char *line);
int		parse_sphere_util(t_data *data, char **line_split, int *obj_i);
int		parse_sphere(t_data *data, char *line, int *obj_i);
int		parse_plane_util1(t_data *data, char **line_split, int *obj_i);
int		parse_plane_util2(t_data *data, char **line_split, int *obj_i);
int		parse_plane(t_data *data, char *line, int *obj_i);
int		parse_cylinder_util1(t_data *data, char **line_split, int *obj_i);
int		parse_cylinder_util2(t_data *data, char **line_split, int *obj_i);
int		parse_cylinder_util3(t_data *data, char **line_split, int *obj_i);
int		parse_cylinder(t_data *data, char *line, int *obj_i);
int		parse_lines_util(t_data *data, t_list *line_list, int *obj_i);
int		parse_lines(t_data *data, t_list *line_list);
int		parse_input_util2(t_list *line_list, int ret);
int		parse_input_util(t_data *data, t_list *line_list);
int		parse_input(t_data *data, int argc, char **argv);

#endif