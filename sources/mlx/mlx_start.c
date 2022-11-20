/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:17:27 by fbruggem          #+#    #+#             */
/*   Updated: 2022/11/20 12:17:40 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "../../includes/render.h"

void	mlx_start(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	render((void *) data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
