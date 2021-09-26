/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:40:22 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/06 21:44:48 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_value(t_long *so_long)
{
	if (so_long->count_p > 1 || so_long->count_p == 0)
		errorout(so_long, 2);
	else if (so_long->count_ex == 0 || so_long->count_loot == 0)
		errorout(so_long, 2);
	else if (so_long->len_map > 250 || so_long->boundaries > 250)
		errorout(so_long, 2);
}

static int	what_letter(char c)
{
	if (c != 'P' && c != 'C' && c != 'E' && c != '1' && c != '0')
		return (1);
	return (0);
}

static void	check_frame(t_long *so_long, int i)
{
	while (so_long->map[0][++i])
		if (so_long->map[0][i] != '1')
			errorout(so_long, 2);
	i = -1;
	while (so_long->map[++i])
		if (so_long->map[i][0] != '1')
			errorout(so_long, 2);
	i = -1;
	while (so_long->map[so_long->len_map - 1][++i])
		if (so_long->map[so_long->len_map - 1][i] != '1')
			errorout(so_long, 2);
	i = -1;
	while (so_long->map[++i])
		if (so_long->map[i][so_long->boundaries - 1] != '1')
			errorout(so_long, 2);
}

void	checking_map(t_long *so_long, int x, int y)
{
	while (so_long->map[++y])
	{
		x = -1;
		while (so_long->map[y][++x])
		{
			if (what_letter(so_long->map[y][x]) == 1)
				errorout(so_long, 2);
			if (so_long->map[y][x] == 'P')
			{
				so_long->count_p += 1;
				so_long->play_x = x;
				so_long->play_y = y;
			}
			if (so_long->map[y][x] == 'C')
				so_long->count_loot += 1;
			if (so_long->map[y][x] == 'E')
				so_long->count_ex += 1;
		}
	}
	check_value(so_long);
	check_frame(so_long, -1);
}
