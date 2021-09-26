/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:37:47 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/06 21:45:02 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game_image(t_long *so_long)
{
	so_long->image_wall = mlx_xpm_file_to_image(so_long->mlx, \
		"image/wall.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_grass = mlx_xpm_file_to_image(so_long->mlx, \
		"image/grass.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_player = mlx_xpm_file_to_image(so_long->mlx, \
		"image/player.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_loot = mlx_xpm_file_to_image(so_long->mlx, \
		"image/loot.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_exit = mlx_xpm_file_to_image(so_long->mlx, \
		"image/exit.xpm", &so_long->image_width, &so_long->image_height);
	if (!so_long->image_wall || !so_long->image_grass || !so_long->image_player \
		|| !so_long->image_loot || !so_long->image_exit)
		errorout(so_long, 1);
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
				so_long->image_exit, x * IM_SIZE, y * IM_SIZE);
		}	
	}
}
