/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:30:27 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 00:17:59 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

/**
 * @brief All images are meant to have the same height and width
 * 
 * @param info 
 * @return int 
 */
int	init_view(t_solong *info)
{
	info->mlx.mlx_ptr = mlx_init();
	if (!info->mlx.mlx_ptr)
		return (exit_error(info, "MLX initialisation failed."));
	if (init_img(info))
		return (exit_error(info,
				"Image reading fail (the image should have equal dimensions)"));
	if (set_up_window(info))
		return (exit_error(info, "Loading new window failed"));
	if (set_up_view(info))
		return (exit_error(info, "setting up the first image failed"));
	return (0);
}
