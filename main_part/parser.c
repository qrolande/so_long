/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:25:01 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/06 21:45:06 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_len(t_long *so_long, char *av)
{
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		so_long->len_map++;
		free (line);
	}
	free (line);
	so_long->len_map += 1;
}

static void	same_size(t_long *so_long)
{
	int	i;
	int	res;

	i = 0;
	so_long->boundaries = ft_strlen(so_long->map[i]);
	while (so_long->map[i])
	{
		res = ft_strlen(so_long->map[i]);
		if (so_long->boundaries != res)
			errorout(so_long, 2);
		i++;
	}
}

void	parser(t_long *so_long, char *av)
{
	int		fd;
	int		i;
	int		flag;
	char	*line;

	i = 0;
	flag = 1;
	fd = open(av, O_RDONLY);
	map_len(so_long, av);
	so_long->map = (char **)malloc(sizeof(char *) * (so_long->len_map + 1));
	if (so_long->map == NULL)
		errorout(so_long, 5);
	while (flag)
	{
		flag = get_next_line(fd, &line);
		if (flag == -1)
			errorout(so_long, 5);
		so_long->map[i] = line;
		i++;
	}
	so_long->map[i] = NULL;
	same_size(so_long);
	checking_map(so_long, -1, 0);
}
