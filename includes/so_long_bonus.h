/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 13:37:55 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:39:05 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFF_SIZE 1
# define IM_SIZE 64
# define A_BUT 0
# define S_BUT 1
# define D_BUT 2
# define W_BUT 13
# define ESC_BUT 53

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

typedef struct s_long
{
	void		*mlx;
	void		*win;
	char		**map;
	int			len_map;
	int			boundaries;
	int			count_p;
	int			count_ex;
	int			count_loot;
	void		*image_wall;
	void		*image_grass;
	void		*image_loot;
	void		*image_player;
	void		*image_player_W;
	void		*image_player_A;
	void		*image_player_S;
	void		*image_player_D;
	void		*image_exit1;
	void		*image_exit2;
	void		*image_exit3;
	void		*image_exit4;
	void		*image_exit5;
	void		*image_exit6;
	void		*image_exit7;
	void		*image_fire1;
	void		*image_fire2;
	void		*image_fire3;
	void		*image_fire4;
	void		*image_fire5;
	void		*image_fire6;
	int			image_width;
	int			image_height;
	char		*itoa_res;
	int			moves;
	int			flag_ex;
	int			flag_fi;
	int			play_x;
	int			play_y;
}				t_long;

int		ft_strlen(char *s);
int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);

void	parser(t_long *so_long, char *av);
void	errorout(t_long *so_long, int i);
void	freeall(t_long *so_long);
void	checking_map(t_long *so_long, int x, int y);
void	init_game_image(t_long *so_long);
void	init_map(t_long *so_long, int x, int y);
int		esc_button(int keycode, t_long *so_long);
void	loose(t_long *so_long);
void	win(t_long *so_long);
int		key_hook(int keycode, t_long *so_long);
int		spray_animation(t_long *so_long);
void	spray_exit(t_long *so_long, int x, int y);
void	spray_fire(t_long *so_long, int x, int y);
void	init_map_2(t_long *so_long, int y, int x);

#endif