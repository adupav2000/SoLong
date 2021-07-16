/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:36:34 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 13:25:25 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

int	set_up_window(t_solong *info)
{
	info->mlx.mlx_win = mlx_new_window(info->mlx.mlx_ptr,
			(info->map_col * info->img_coll.width),
			(info->map_row * info->img_coll.height), "./Solong");
	if (info->mlx.mlx_win == NULL)
		return (-1);
	return (0);
}

int	put_floor_and_wall(t_solong *info, int x, int y, char c)
{
	x = x * info->img_wall.width - 1;
	y = y * info->img_wall.height - 1;
	if (c == WALL)
		mlx_put_image_to_window(info->mlx.mlx_ptr,
			info->mlx.mlx_win, info->img_wall.img, x, y);
	else
		mlx_put_image_to_window(info->mlx.mlx_ptr,
			info->mlx.mlx_win, info->img_floor.img, x, y);
	return (0);
}

int	put_all_items(t_solong *info, int x, int y, char c)
{
	x = x * info->img_wall.width;
	y = y * info->img_wall.height;
	if (c == COLLECT)
		mlx_put_image_to_window(info->mlx.mlx_ptr,
			info->mlx.mlx_win, info->img_coll.img, x, y);
	else if (c == PLAYER)
		mlx_put_image_to_window(info->mlx.mlx_ptr,
			info->mlx.mlx_win, info->img_player.img, x, y);
	else if (c == EXIT)
		mlx_put_image_to_window(info->mlx.mlx_ptr,
			info->mlx.mlx_win, info->img_exit.img, x, y);
	else if (c != WALL && c != FLOOR)
		return (-1);
	return (0);
}

int	update_view(t_solong *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->map_row)
	{
		x = 0;
		while (x < info->map_col)
		{
			if (put_floor_and_wall(info, x, y, get_map_char(info, x, y))
				|| put_all_items(info, x, y, get_map_char(info, x, y)))
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	set_up_view(t_solong *info)
{
	int	x;
	int	y;

	info->view.img = mlx_new_image(info->mlx.mlx_ptr,
			(info->map_col * info->img_coll.width),
			(info->map_row * info->img_coll.height));
	y = 0;
	while (y < info->map_row)
	{
		x = 0;
		while (x < info->map_col)
		{
			if (put_floor_and_wall(info, x, y, get_map_char(info, x, y))
				|| put_all_items(info, x, y, get_map_char(info, x, y)))
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
