/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:24:12 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 18:08:36 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "../includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_str{
	char			*str;
	struct s_str	*next;
}	t_str;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}				t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}				t_data;

typedef struct s_solong{
	t_data	mlx;
	t_img	view;
	int		texY;
	int		texX;

	t_str	*map;
	int		map_w;
	int		map_h;
	int		map_col;
	int		map_row;
	int		posX;
	int		posY;
	int		movX;
	int		moveY;
	int		play_set;
	int		exit_set;
	int		coll_set;
	int		coll_amount;
	int		mov_num;
	t_img	img_coll;
	t_img	img_wall;
	t_img	img_floor;
	t_img	img_exit;
	t_img	img_player;
}	t_solong;

int		parsing(int ac, char **av, t_solong *all_info);
int		init_view(t_solong *info);
int		exit_error(t_solong *info, char *message);
int		exit_success(t_solong *info);
int		save_map(int fd, t_solong *allinfo);
int		check_walls(t_solong *info);
int		is_right_map_char(t_solong *info, char map_char);
int		init_solong(t_solong *info);
int		check_single_user_and_correct(t_solong *info, t_str *map);

int		set_pos_player(t_solong *info);
char	get_map_char(t_solong *info, int x, int y);
int		int_move(t_solong *info, int moveX, int moveY);
int		change_map_char_to_player(t_solong *info, int posX, int posY);
int		erase_player(t_solong *info);
int		autorised_position(t_solong *info, int x, int y);

int		load_texture(char *tex_link, t_img *img, t_data *mlx);
int		img_well_set(t_solong *info);
int		init_img(t_solong *info);

int		set_up_window(t_solong *info);
int		nd_wall(t_solong *info, int x, int y, char c);
int		put_all_items(t_solong *info, int x, int y, char c);
int		set_up_view(t_solong *info);

int		autorised_position(t_solong *info, int x, int y);
int		erase_player(t_solong *info);
int		change_map_char_to_player(t_solong *info, int posX, int posY);
int		init_move(t_solong *info, int moveX, int moveY);
int		update_view(t_solong *info);

unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void	draw_square(t_solong *info, t_img *img, int x, int y);
#endif