/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:24:17 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 13:25:35 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

void	draw_square(t_solong *info, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(info->mlx.mlx_win, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->line_length)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->addr + (x * mlx_img->bpp / 8 + y * mlx_img->line_length);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}
