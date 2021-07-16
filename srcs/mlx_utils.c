/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:24:17 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 13:44:29 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->img + (x * img->bpp / 8 + y * img->line_length)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->img + (x * mlx_img->bpp / 8 + y * mlx_img->line_length);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

void	draw_square(t_solong *info, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	printf("img w : %d, img h : %d\n", img->width, img->height);
	while (j < 16)
	{
		i = 0;
		while (i < 16)
		{
			printf("Here\n");
			color = mlx_get_pixel(img, i, j);
			printf("not here but here\n");
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
			{
				printf("Here ?\n");
				mlx_draw_pixel(&(info->view), x + i, y + j, color);
			}
			i++;
		}
		j++;
	}
}
