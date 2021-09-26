/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:33:42 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:33:44 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_map_2(t_long *so_long, int y, int x)
{
	while (so_long->map[++y])
	{
		x = -1;
		while (so_long->map[y][++x])
		{
			if (so_long->map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_wall, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_grass, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_player, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_loot, x * IM_SIZE, y * IM_SIZE);
		}
	}
}

void	init_map(t_long *so_long, int y, int x)
{
	while (so_long->map[++y])
	{
		x = -1;
		while (so_long->map[y][++x])
		{
			if (so_long->map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_wall, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_grass, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_player, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_loot, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == 'E')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_exit1, x * IM_SIZE, y * IM_SIZE);
			if (so_long->map[y][x] == 'F')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_fire1, x * IM_SIZE, y * IM_SIZE);
		}	
	}
}
