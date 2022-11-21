/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:58:25 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/21 01:59:20 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

int	check_ambient(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (get_split_len(line_split) != 3)
	{
		ft_printf("Wrong amount of elements for ambient.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_float_range(line_split[1], 0.0, 1.0) == -1)
	{
		ft_printf("Wrong lighting ratio format.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_color(line_split[2]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	free_split(line_split);
	return (0);
}

int	check_camera_util(char **line_split)
{
	if (check_normalized(line_split[2]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (check_int_range(line_split[3], 0, 179) == -1)
	{
		ft_printf("Wrong FOV format.\n");
		free_split(line_split);
		return (-1);
	}
	free_split(line_split);
	return (0);
}

int	check_camera(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (get_split_len(line_split) != 4)
	{
		ft_printf("Wrong amount of elements for camera.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_coords(line_split[1]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (check_camera_util(line_split) == -1)
		return (-1);
	return (0);
}

int	check_light(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (get_split_len(line_split) != 3)
	{
		ft_printf("Wrong amount of elements for light.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_coords(line_split[1]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (check_float_range(line_split[2], 0.0, 1.0) == -1)
	{
		ft_printf("Wrong brightness format.\n");
		free_split(line_split);
		return (-1);
	}
	free_split(line_split);
	return (0);
}

int	check_sphere_util(char **line_split)
{
	if (check_float(line_split[2], 1) == -1)
	{
		ft_printf("Wrong diameter format.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_color(line_split[3]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	free_split(line_split);
	return (0);
}
