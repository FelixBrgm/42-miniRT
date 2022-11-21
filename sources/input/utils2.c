/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:55:54 by pvznuzda          #+#    #+#             */
/*   Updated: 2022/11/21 02:01:20 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/parser.h"

int	check_identifier(char *identifier, int identifier_count[4])
{
	if (!ft_strncmp(identifier, "A", 2))
	{
		identifier_count[0] = identifier_count[0] + 1;
		return (0);
	}
	else if (!ft_strncmp(identifier, "C", 2))
	{
		identifier_count[1] = identifier_count[1] + 1;
		return (0);
	}
	else if (!ft_strncmp(identifier, "L", 2))
	{
		identifier_count[2] = identifier_count[2] + 1;
		return (0);
	}
	else if (!ft_strncmp(identifier, "pl", 3)
		|| !ft_strncmp(identifier, "sp", 3)
		|| !ft_strncmp(identifier, "cy", 3))
	{
		identifier_count[3] = identifier_count[3] + 1;
		return (0);
	}
	return (1);
}

int	check_identifiers(t_list *line_list)
{
	char	*identifier;
	int		check_res;
	int		identifier_count[4];

	identifier_count[0] = 0;
	identifier_count[1] = 0;
	identifier_count[2] = 0;
	identifier_count[3] = 0;
	while (line_list)
	{
		identifier = get_identifier(line_list->content);
		if (!identifier)
			return (-1);
		check_res = check_identifier(identifier, identifier_count);
		free(identifier);
		if (check_res)
			return (-1);
		line_list = line_list->next;
	}
	if (identifier_count[0] != 1 || identifier_count[1] != 1
		|| identifier_count[2] != 1)
		return (-1);
	return (identifier_count[3]);
}

int	get_split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

void	ft_atof_util(char *str, int i, float *result)
{
	float	divider;

	if (str[i] == '.')
	{
		i++;
		divider = 10;
		while (str[i] >= '0' && str[i] <= '9')
		{
			*result = *result + (str[i] - '0') / divider;
			divider *= 10;
			i++;
		}
	}
}

float	ft_atof(char *str)
{
	int		i;
	float	divider;
	float	negative;
	float	result;

	i = 0;
	negative = 0;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			result = result * 10 + (str[i] - '0');
			i++;
	}
	ft_atof_util(str, i, &result);
	if (negative)
		return (-result);
	return (result);
}
