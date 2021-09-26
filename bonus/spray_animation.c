/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spray_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:34:03 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:34:12 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	spray_animation(t_long *so_long)
{
	int	y;
	int	x;

	y = -1;
	while (so_long->map[++y])
	{
		x = -1;
		while (so_long->map[y][++x])
		{
			if (so_long->map[y][x] == 'F')
				spray_fire(so_long, x, y);
			if (so_long->map[y][x] == 'E' && so_long->flag_ex != 0 \
				&& so_long->flag_ex < 6001)
				spray_exit(so_long, x, y);
		}
	}
	so_long->flag_fi += 1;
	if (so_long->flag_fi == 6000)
		so_long->flag_fi = 0;
	if (so_long->flag_ex)
		so_long->flag_ex += 1;
	return (0);
}
