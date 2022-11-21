/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:17:36 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/21 02:04:25 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"
#include "../includes/parser.h"
#include "../includes/render.h"

t_data	*data_create(void);

void	free_objs(t_scene scene)
{
	int	i;

	i = 0;
	while (scene.objs && scene.objs[i])
	{
		if (scene.objs[i]->cylinder)
		{
			free(scene.objs[i]->cylinder);
			scene.objs[i]->cylinder = NULL;
		}
		else if (scene.objs[i]->plane)
		{
			free(scene.objs[i]->plane);
			scene.objs[i]->plane = NULL;
		}
		else if (scene.objs[i]->sphere)
		{
			free(scene.objs[i]->sphere);
			scene.objs[i]->sphere = NULL;
		}
		free(scene.objs[i]);
		i++;
	}
}

void	free_data(t_data *data, int ret)
{
	int		i;
	t_scene	scene;

	i = 0;
	while (data->img[i])
	{
		free(data->img[i]);
		i++;
	}
	free(data->img);
	scene = data->scene;
	i = 0;
	if (ret == -1)
	{
		free(data);
		return ;
	}
	free_objs(scene);
	free(scene.objs);
	scene.objs = NULL;
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		parser_res;

	data = data_create();
	if (!data)
		return (0);
	parser_res = parse_input(data, argc, argv);
	if (parser_res != 0)
	{
		ft_printf("error in parser.\n");
		free_data(data, parser_res);
		return (0);
	}
	mlx_start(data);
	ft_printf("done!\n");
	free_data(data, 0);
	return (0);
}

t_data	*data_create(void)
{
	t_data	*data;
	int		i;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (NULL);
	data->img = ft_calloc(PIXELS + 1, sizeof(t_color *));
	i = 0;
	while (i < PIXELS)
	{
		data->img[i] = ft_calloc(1, sizeof(t_color));
		i++;
	}
	data->img[PIXELS] = NULL;
	if (!data->img)
	{
		free(data);
		return (NULL);
	}
	data->mlx_img = NULL;
	data->pixel_samples = 0;
	srand(time(NULL));
	return (data);
}
