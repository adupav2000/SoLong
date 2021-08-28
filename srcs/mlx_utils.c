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
	return (*(int *)
		(img->addr + (x * img->bpp / 8 + y * img->line_length)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	//printf("x : %d, y : %d\n", x, y);
	//printf("line_length : %d, bpp : %d, endian : %d\n", mlx_img->bpp,
	//	mlx_img->line_length, mlx_img->endian);
	//printf("view height : %d, width %d\n", mlx_img->height, mlx_img->width);
	//printf("target : %d\n", (x * mlx_img->bpp / 8 + y * mlx_img->line_length));

	target = mlx_img->addr + (x * mlx_img->bpp / 8 + y * mlx_img->line_length);
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

	printf("x : %d, map_col : %d\n", x, info->map_col);
	printf("WHAT :x %d , y : %d\n", x, y);
	printf("img->height : %d, img->width : %d", img->height, img->width);
	printf("info->view.height: %d, info->view.width  : %d\n", info->view.height, info->view.width);
	j = 0;
	while (j < img->height && (y + j) < info->view.height)
	{
		i = 0;
		while (i < img->width && (x + i) < info->view.width)
		{
			//printf("img w : %d, img h : %d\n", img->width, img->height);
			//printf("i = %d, j = %d\n", i, j);
			color = mlx_get_pixel(img, i, j);
	//		printf("i = %d, j = %d\n", i + y, j + x);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
			{
				printf("Here ?\n");
				info->view.addr[(y + j) * info->view.line_length + (x + i) * info->view.bpp
					/ 8] = img->addr[j * img->line_length
					+ i * (img->bpp / 8)];
				info->view.addr[(y + j) * info->view.line_length + (x + i) * info->view.bpp
					/ 8 + 1] = img->addr[j * img->line_length
					+ i * (img->bpp / 8) + 1];
				info->view.addr[(y + j) * info->view.line_length + (x + i) * info->view.bpp
					/ 8 + 2] = img->addr[j * img->line_length
					+ i * (img->bpp / 8) + 2];
				//mlx_draw_pixel(&(info->view), x + i, y + j, color);
			//	printf("not after ?\n");
			}
			i++;
		}
		j++;
	}
}
