/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:25:03 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 12:55:18 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

int	check_map(t_solong *all_info)
{
	if (check_walls(all_info))
		return (-1);
	if (check_single_user_and_correct(all_info, all_info->map))
		return (-1);
	return (0);
}

int	parsing(int ac, char **av, t_solong *all_info)
{
	int	fd;

	if (ac != 2)
		return (exit_error(all_info, "Missing or wrong map file"));
	if (ft_strlen(av[1]) < 5
		|| ft_strncmp(&(av[1][ft_strlen(av[1]) - 4]), ".ber", 4) != 0)
		return (exit_error(all_info, "Missing or wrong map file"));
	printf("Problem ")
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || init_solong(all_info))
		return (exit_error(all_info, "Wrong file path."));
	if (save_map(fd, all_info) || check_map(all_info))
		return (-1);
	return (0);
}
