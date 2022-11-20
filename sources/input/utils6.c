/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:59:45 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/20 22:20:40 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	check_sphere(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (get_split_len(line_split) != 4)
	{
		ft_printf("Wrong amount of elements for sphere.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_coords(line_split[1]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (check_sphere_util(line_split) == -1)
		return (-1);
	return (0);
}

int	check_plane_util(char **line_split)
{
	if (check_normalized(line_split[2]) == -1)
	{
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

int	check_plane(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (get_split_len(line_split) != 4)
	{
		ft_printf("Wrong amount of elements for plane.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_coords(line_split[1]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (check_plane_util(line_split) == -1)
		return (-1);
	return (0);
}

int	check_cylinder_util(char **line_split)
{
	if (check_float(line_split[3], 1) == -1)
	{
		ft_printf("Wrong diameter format.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_float(line_split[4], 1) == -1)
	{
		ft_printf("Wrong height format.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_color(line_split[5]) == -1)
	{
		ft_printf("Wrong color format.\n");
		free_split(line_split);
		return (-1);
	}
	free_split(line_split);
	return (0);
}

int	check_cylinder(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		return (-1);
	if (get_split_len(line_split) != 6)
	{
		ft_printf("Wrong amount of elements for cylinder.\n");
		free_split(line_split);
		return (-1);
	}
	if (check_coords(line_split[1]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (check_normalized(line_split[2]) == -1)
	{
		free_split(line_split);
		return (-1);
	}
	if (check_cylinder_util(line_split) == -1)
		return (-1);
	return (0);
}
