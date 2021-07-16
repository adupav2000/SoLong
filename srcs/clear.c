/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:37:58 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/15 12:23:53 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

void	clear_all_variables(t_solong *info)
{
	(void)info;
	// clear_player(game);
	// clear_map_info(game);
	// clear_config(&(game->config));
	// clear_mlx(&(game->mlx));
}

int		exit_error(t_solong *info, char *message)
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
