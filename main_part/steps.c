/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:03:28 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:40:27 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	rewrite_map(t_long *so_long, int x, int y)
{
	so_long->map[(so_long->play_y + y)][(so_long->play_x + x)] = 'P';
	so_long->map[so_long->play_y][so_long->play_x] = '0';
	so_long->play_x = so_long->play_x + x;
	so_long->play_y = so_long->play_y + y;
	so_long->moves++;
	printf("Your moves = %d\n", so_long->moves);
}

void	steps(t_long *so_long, int x, int y)
{
	if (so_long->map[so_long->play_y + y][so_long->play_x + x] != '1')
	{
		if (so_long->map[so_long->play_y + y][so_long->play_x + x] == 'C')
		{
			so_long->count_loot--;
			rewrite_map(so_long, x, y);
		}
		else if ((so_long->map[so_long->play_y + y][so_long->play_x + x] == 'E')
			&& (so_long->count_loot == 0))
		{
			so_long->moves++;
			win(so_long);
		}
		else if (so_long->map[so_long->play_y + y][so_long->play_x + x] == '0')
			rewrite_map(so_long, x, y);
		init_map(so_long, 0, 0);
	}
}

int	key_hook(int keycode, t_long *so_long)
{
	if (keycode == ESC_BUT)
		esc_button(53, so_long);
	if (keycode == A_BUT)
		steps(so_long, -1, 0);
	if (keycode == S_BUT)
		steps(so_long, 0, 1);
	if (keycode == D_BUT)
		steps(so_long, 1, 0);
	if (keycode == W_BUT)
		steps(so_long, 0, -1);
	return (0);
}
