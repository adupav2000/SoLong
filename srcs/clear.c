/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:37:58 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 14:18:02 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

void	clear_mlx(t_data *mlx)
{
	if (mlx->mlx_ptr != NULL && mlx->mlx_win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
}

void	clear_map_info(t_solong *info)
{
	t_str	*str;

	if (info->img_coll.img != NULL)
		mlx_destroy_image(info->mlx.mlx_ptr, info->img_coll.img);
	if (info->img_wall.img != NULL)
		mlx_destroy_image(info->mlx.mlx_ptr, info->img_wall.img);
	if (info->img_floor.img != NULL)
		mlx_destroy_image(info->mlx.mlx_ptr, info->img_floor.img);
	if (info->img_exit.img != NULL)
		mlx_destroy_image(info->mlx.mlx_ptr, info->img_exit.img);
	if (info->img_player.img != NULL)
		mlx_destroy_image(info->mlx.mlx_ptr, info->img_player.img);
	if (info->view.img != NULL)
		mlx_destroy_image(info->mlx.mlx_ptr, info->view.img);
	while (info->map != NULL && ((info->map->next) != NULL))
	{
		str = info->map->next;
		if ((info->map->str) != NULL)
			free(info->map->str);
		free(info->map);
		info->map = str;
	}
}

void	clear_all_variables(t_solong *info)
{
	(void)info;
	clear_map_info(info);
	clear_mlx(&(info->mlx));
}

int	exit_error(t_solong *info, char *message)
{
	clear_all_variables(info);
	if (message == NULL || message[0] == 0)
	{
		perror("Error ");
	}
	else
	{
		ft_putstr_fd("Error : ", 1);
		ft_putstr_fd(message, 1);
		ft_putstr_fd("\n", 1);
	}
	exit(EXIT_FAILURE);
	return (-1);
}

int		exit_success(t_solong *info)
{
	clear_all_variables(info);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
