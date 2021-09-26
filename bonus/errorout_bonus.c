/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:52:12 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/06 22:03:02 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	freeall(t_long *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i])
	{
		free (so_long->map[i]);
		i++;
	}
	free (so_long->map);
}

void	errorout(t_long *so_long, int i)
{
	if (i == 1)
	{
		printf("Attention\nError (code 1): Can't import image\n");
		freeall(so_long);
	}
	if (i == 2)
	{
		printf("Attention\nError (code 2): Invalid map\n");
		freeall(so_long);
	}
	if (i == 3)
		printf("Attention\nError (code 3): Can't read file\n");
	if (i == 4)
		printf("Attention\nError (code 4): Wrong number of arguments\n");
	if (i == 5)
	{
		printf("Attention\nError (code 5): Can't allocate memory\n");
		freeall(so_long);
	}
	if (i == 6)
		printf("Attention\nError (code 6): Wrong map format\n");
	exit (1);
}
