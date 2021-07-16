/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:30:19 by AlainduPa         #+#    #+#             */
/*   Updated: 2021/07/16 18:33:12 by AlainduPa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/SoLong.h"

int	key_hook(int keycode, t_solong *info)
{
	(void)info;
	if (keycode == 123 || keycode == 0)
		init_move(info, -1, 0);
	else if (keycode == 125 || keycode == 1)
		init_move(info, 0, 1);
	else if (keycode == 124 || keycode == 2)
		init_move(info, 1, 0);
	else if (keycode == 126 || keycode == 13)
		init_move(info, 0, -1);
	else if (keycode == 53)
		exit_success(info);
    printf("tkeycode : %d\n", keycode);
	update_view(info);
	info->mov_num++;
	ft_putstr_fd("Move number ", 1);
	ft_putnbr_fd(info->mov_num, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	info;

	if (parsing(ac, av, &info))
		return (-1);
	if (init_view(&info))
		return (-1);
	mlx_key_hook(info.mlx.mlx_win, key_hook, &info);
	// mlx_hook(info.mlx.mlx_win, 33, (1L << 5), exit_success, &info);
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
