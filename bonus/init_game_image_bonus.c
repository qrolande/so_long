/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 19:37:47 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:33:19 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	if_nothing(t_long *so_long)
{
	if (!so_long->image_wall || !so_long->image_grass \
		|| !so_long->image_player || !so_long->image_loot \
		|| !so_long->image_exit1 || !so_long->image_exit2 \
		|| !so_long->image_exit3 || !so_long->image_exit4 \
		|| !so_long->image_exit5 || !so_long->image_exit6 \
		|| !so_long->image_exit7 || !so_long->image_fire1 \
		|| !so_long->image_fire2 || !so_long->image_fire3 \
		|| !so_long->image_fire4 || !so_long->image_fire5 \
		|| !so_long->image_fire6)
		errorout(so_long, 1);
}

static void	spray_exit_image(t_long *so_long)
{
	so_long->image_exit1 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/portal/exit1.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_exit2 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/portal/exit2.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_exit3 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/portal/exit3.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_exit4 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/portal/exit4.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_exit5 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/portal/exit5.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_exit6 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/portal/exit6.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_exit7 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/portal/exit7.xpm", &so_long->image_width, \
		&so_long->image_height);
}

static void	spray_fire_image(t_long *so_long)
{
	so_long->image_fire1 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/fire/fire1.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_fire2 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/fire/fire2.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_fire3 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/fire/fire3.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_fire4 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/fire/fire4.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_fire5 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/fire/fire5.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_fire6 = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/fire/fire6.xpm", &so_long->image_width, \
		&so_long->image_height);
}

void	init_game_image(t_long *so_long)
{
	so_long->image_wall = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/wall.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_grass = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/grass.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_loot = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/loot.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_player = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/player.xpm", &so_long->image_width, &so_long->image_height);
	so_long->image_player_D = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/player_d.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_player_A = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/player_a.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_player_S = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/player_s.xpm", &so_long->image_width, \
		&so_long->image_height);
	so_long->image_player_W = mlx_xpm_file_to_image(so_long->mlx, \
		"img_bonus/player_w.xpm", &so_long->image_width, \
		&so_long->image_height);
	spray_exit_image(so_long);
	spray_fire_image(so_long);
	if_nothing(so_long);
}
