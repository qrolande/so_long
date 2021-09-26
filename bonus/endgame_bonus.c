/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:18:16 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/07 18:39:37 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	win(t_long *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	printf("\nEnjoy your victory\nYour moves - %d\n", so_long->moves);
	freeall(so_long);
	exit (0);
}

void	loose(t_long *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	printf("\nPathetic\nYour moves - %d\n", so_long->moves);
	freeall(so_long);
	exit (0);
}

int	esc_button(int keycode, t_long *so_long)
{
	if (keycode == ESC_BUT)
	{
		mlx_destroy_window(so_long->mlx, so_long->win);
		printf("\nEsc button activated\n");
		freeall(so_long);
	}
	exit (0);
	return (0);
}
