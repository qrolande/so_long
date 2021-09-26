/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:03:28 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:36:18 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	rewrite_map(t_long *so_long, int x, int y, int but)
{
	so_long->map[(so_long->play_y + y)][(so_long->play_x + x)] = 'P';
	if (but == W_BUT)
		so_long->image_player = so_long->image_player_W;
	if (but == S_BUT)
		so_long->image_player = so_long->image_player_S;
	if (but == A_BUT)
		so_long->image_player = so_long->image_player_A;
	if (but == D_BUT)
		so_long->image_player = so_long->image_player_D;
	so_long->map[so_long->play_y][so_long->play_x] = '0';
	so_long->play_x = so_long->play_x + x;
	so_long->play_y = so_long->play_y + y;
	so_long->moves++;
	printf("Your moves = %d\n", so_long->moves);
}

void	steps(t_long *so_long, int x, int y, int but)
{
	if (so_long->map[so_long->play_y + y][so_long->play_x + x] != '1')
	{
		if (so_long->map[so_long->play_y + y][so_long->play_x + x] == 'C')
		{
			so_long->count_loot--;
			rewrite_map(so_long, x, y, but);
		}
		else if ((so_long->map[so_long->play_y + y][so_long->play_x + x] == 'E')
			&& (so_long->count_loot == 0))
		{
			so_long->moves++;
			win(so_long);
		}
		else if (so_long->map[so_long->play_y + y][so_long->play_x + x] == '0')
			rewrite_map(so_long, x, y, but);
		else if (so_long->map[so_long->play_y + y][so_long->play_x + x] == 'F')
			loose(so_long);
		init_map_2(so_long, 0, 0);
	}
}

int	key_hook(int keycode, t_long *so_long)
{
	if (keycode == ESC_BUT)
		esc_button(53, so_long);
	if (keycode == W_BUT)
		steps(so_long, 0, -1, W_BUT);
	if (keycode == S_BUT)
		steps(so_long, 0, 1, S_BUT);
	if (keycode == A_BUT)
		steps(so_long, -1, 0, A_BUT);
	if (keycode == D_BUT)
		steps(so_long, 1, 0, D_BUT);
	if (!so_long->flag_ex && so_long->count_loot == 0)
		so_long->flag_ex = 1;
	so_long->itoa_res = ft_itoa(so_long->moves);
	mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_wall, 2 * IM_SIZE, 0 * IM_SIZE);
	mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_wall, 1 * IM_SIZE, 0 * IM_SIZE);
	mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->image_wall, 0 * IM_SIZE, 0 * IM_SIZE);
	mlx_string_put(so_long->mlx, so_long->win, 143, 17, 0xFFFFFF, \
	so_long->itoa_res);
	mlx_string_put(so_long->mlx, so_long->win, 20, 17, 0xFFFFFF, \
	"Your moves =");
	free (so_long->itoa_res);
	return (0);
}
