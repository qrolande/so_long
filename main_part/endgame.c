/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:18:16 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/06 21:44:52 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win(t_long *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	printf("Enjoy your victory!\nYour moves - %d\n", so_long->moves);
	freeall(so_long);
	exit (0);
}

int	esc_button(int keycode, t_long *so_long)
{
	if (keycode == ESC_BUT)
	{
		mlx_destroy_window(so_long->mlx, so_long->win);
		printf("Esc button activated\n");
		freeall(so_long);
	}
	exit (0);
	return (0);
}
