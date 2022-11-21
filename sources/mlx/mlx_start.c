/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:17:27 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/21 01:21:24 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/render.h"

void   detect_key(struct mlx_key_data khit, void *data)
{
	if (khit.key == 256)
	{
		mlx_close_window(((t_data *)data)->mlx);
		free_data(data, 0);
		exit(0);
	}
}

void	mlx_start(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	render((void *) data);
	mlx_key_hook(data->mlx, detect_key, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
