/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:17:27 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/21 02:05:35 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/render.h"

void	detect_key(struct mlx_key_data khit, void *data)
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
