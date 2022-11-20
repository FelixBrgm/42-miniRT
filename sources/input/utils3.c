/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:57:02 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/20 22:20:33 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	check_float(char *line, int check_positive)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (line[i] == '-')
		i++;
	if (line[i] == '.')
		return (-1);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]))
		{
			if (line[i] == '.' && !dot && ft_isdigit(line[i + 1]))
				dot = 1;
			else
				return (-1);
		}
		i++;
	}
	if (check_positive)
		if (ft_atof(line) < 0)
			return (-1);
	return (0);
}

int	check_float_range(char *line, float min, float max)
{
	float	number;

	if (check_float(line, 0) == -1)
		return (-1);
	number = ft_atof(line);
	if (number < min || number > max)
		return (-1);
	return (0);
}

int	check_int(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '-')
		i++;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	check_int_range(char *line, float min, float max)
{
	int	number;

	if (check_int(line) == -1)
		return (-1);
	number = ft_atoi(line);
	if (number < min || number > max)
		return (-1);
	return (0);
}

int	check_coords_util(char **coords_split)
{
	int	i;

	i = 0;
	while (coords_split[i])
	{
		if (coords_split[i][0] == '\0' || coords_split[i][0] == '\n')
		{
			ft_printf("Wrong coordinate format.\n");
			free_split(coords_split);
			return (-1);
		}
		if (check_float(coords_split[i], 0) == -1)
		{
			ft_printf("Wrong coordinate format.\n");
			free_split(coords_split);
			return (-1);
		}
		i++;
	}
	return (0);
}
