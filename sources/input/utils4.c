/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:57:49 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/21 01:59:17 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

int	check_coords(char *coords_line)
{
	char	**coords_split;

	coords_split = ft_split(coords_line, ',');
	if (!coords_split)
		return (-1);
	if (get_split_len(coords_split) != 3)
	{
		ft_printf("Wrong amount of elements for coordinates.\n");
		free_split(coords_split);
		return (-1);
	}
	if (check_coords_util(coords_split) == -1)
		return (-1);
	free_split(coords_split);
	return (0);
}

int	check_color_util(char **color_split, int *i)
{
	int	number;

	while (color_split[*i])
	{
		if (color_split[*i][0] == '\0' || color_split[*i][0] == '\n')
		{
			ft_printf("Wrong color format.\n");
			free_split(color_split);
			return (-1);
		}
		if (check_int(color_split[*i]) == -1)
		{
			ft_printf("Wrong color format.\n");
			free_split(color_split);
			return (-1);
		}
		number = ft_atoi(color_split[*i]);
		if (number < 0 || number > 255)
		{
			free_split(color_split);
			return (-1);
		}
		*i += 1;
	}
	return (0);
}

int	check_color(char *color_line)
{
	char	**color_split;
	int		i;
	int		number;

	color_split = ft_split(color_line, ',');
	if (!color_split)
		return (-1);
	if (get_split_len(color_split) != 3)
	{
		ft_printf("Wrong amount of elements for color.\n");
		free_split(color_split);
		return (-1);
	}
	i = 0;
	if (check_color_util(color_split, &i) == -1)
		return (-1);
	free_split(color_split);
	return (0);
}

void	check_normalized_util(char **line_split, float vec[3])
{
	vec[0] = ft_atof(line_split[0]);
	vec[1] = ft_atof(line_split[1]);
	vec[2] = ft_atof(line_split[2]);
}

int	check_normalized(char *line)
{
	char		**line_split;
	float		vec[3];
	float		vec_length;

	if (check_coords(line) == -1)
		return (-1);
	line_split = ft_split(line, ',');
	if (!line_split)
		return (-1);
	check_normalized_util(line_split, vec);
	if (vec[0] < -1.0 || vec[0] > 1.0 || vec[1] < -1.0 || vec[1] > 1.0
		|| vec[2] < -1.0 || vec[2] > 1.0)
	{
		free_split(line_split);
		return (-1);
	}
	vec_length = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	if (vec_length != 1.0)
	{
		free_split(line_split);
		return (-1);
	}
	free_split(line_split);
	return (0);
}
