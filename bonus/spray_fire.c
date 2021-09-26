/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spray_fire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:34:33 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:34:36 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	spray_fire(t_long *so_long, int x, int y)
{
	if (so_long->flag_fi == 1)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image_fire1, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_fi == 1000)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image_fire2, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_fi == 2000)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image_fire3, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_fi == 3000)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image_fire4, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_fi == 4000)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image_fire5, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_fi == 5000)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image_fire6, x * IM_SIZE, y * IM_SIZE);
}
