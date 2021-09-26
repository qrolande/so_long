/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spray_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:34:25 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:34:27 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	spray_exit(t_long *so_long, int x, int y)
{
	if (so_long->flag_ex == 1)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->image_exit1, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_ex == 750)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->image_exit2, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_ex == 1500)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->image_exit3, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_ex == 2250)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->image_exit4, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_ex == 3000)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->image_exit5, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_ex == 3750)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->image_exit6, x * IM_SIZE, y * IM_SIZE);
	else if (so_long->flag_ex == 4500)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->image_exit7, x * IM_SIZE, y * IM_SIZE);
}
