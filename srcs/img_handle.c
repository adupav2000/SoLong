/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:34:39 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 14:16:34 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

int	load_texture(char *tex_link, t_img *img, t_data *mlx)
{
	if (ft_strncmp(&tex_link[ft_strlen(tex_link) - 3], "png", 3) == 0)
	{
		img->img = mlx_png_file_to_image(mlx->mlx_ptr, tex_link,
				&(img->width), &(img->height));
		if (img->img == NULL)
			return (-1);
		img->addr = mlx_get_data_addr(img->img, &(img->bpp),
				&(img->line_length), &(img->endian));
	}
	if (img->addr != NULL)
		return (0);
	return (-1);
}

int	img_well_set(t_solong *info)
{
	if (info->img_floor.width != info->img_coll.width
		|| info->img_coll.width != info->img_wall.width
		|| info->img_wall.width != info->img_exit.width
		|| info->img_exit.width != info->img_player.width)
		return (-1);
	if (info->img_floor.height != info->img_coll.height
		|| info->img_coll.height != info->img_wall.height
		|| info->img_wall.height != info->img_exit.height
		|| info->img_exit.height != info->img_player.height)
		return (-1);
	return (0);
}

int	init_img(t_solong *info)
{
	if (load_texture("tex/floor.png", &(info->img_floor), &(info->mlx)))
		return (-1);
	if (load_texture("tex/coll.png", &(info->img_coll), &(info->mlx)))
		return (-1);
	if (load_texture("tex/wall.png", &(info->img_wall), &(info->mlx)))
		return (-1);
	if (load_texture("tex/exit.png", &(info->img_exit), &(info->mlx)))
		return (-1);
	if (load_texture("tex/player.png", &(info->img_player), &(info->mlx)))
		return (-1);
	return (img_well_set(info));
}
