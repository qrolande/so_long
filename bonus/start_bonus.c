/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 13:38:00 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 21:07:56 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init_struct(t_long *so_long)
{
	so_long->boundaries = 0;
	so_long->count_loot = 0;
	so_long->count_ex = 0;
	so_long->count_p = 0;
	so_long->len_map = 0;
	so_long->flag_ex = 0;
	so_long->flag_fi = 0;
}

static void	check(char *av, t_long *so_long)
{
	int		fd;
	int		i;
	char	*buff;
	int		res;

	i = ft_strlen(av);
	if (i < 5)
		errorout(so_long, 6);
	if (av[i - 4] != '.' || av[i - 3] != 'b'
		|| av[i - 2] != 'e' || av[i - 1] != 'r')
		errorout(so_long, 6);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		errorout(so_long, 3);
	res = read(fd, &buff, BUFF_SIZE);
	if (res == -1)
		errorout(so_long, 3);
}

int	main(int ac, char **av)
{
	t_long	so_long;

	if (ac == 2)
	{
		check(av[1], &so_long);
		init_struct(&so_long);
		parser(&so_long, av[1]);
		so_long.mlx = mlx_init();
		so_long.win = mlx_new_window(so_long.mlx, so_long.boundaries * IM_SIZE, \
			so_long.len_map * IM_SIZE, "Microsoft Flight Simulator");
		init_game_image(&so_long);
		init_map(&so_long, -1, 0);
		mlx_string_put(so_long.mlx, so_long.win, 143, 17, 0xFFFFFF, "0");
		mlx_string_put(so_long.mlx, so_long.win, 20, 17, 0xFFFFFF, \
			"Your moves =");
		mlx_loop_hook(so_long.mlx, spray_animation, &so_long);
		mlx_hook(so_long.win, 17, 0, esc_button, &so_long);
		mlx_hook(so_long.win, 2, (1L << 0), key_hook, &so_long);
		mlx_loop(so_long.mlx);
	}
	else
		errorout(&so_long, 4);
	return (0);
}
