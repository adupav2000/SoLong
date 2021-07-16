/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:48:03 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 01:00:57 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

int	autorised_position(t_solong *info, int x, int y)
{
	if (get_map_char(info, x, y) == WALL
		|| (get_map_char(info, x, y) == EXIT && info->coll_amount > 0))
		return (-1);
	return (0);
}

int	erase_player(t_solong *info)
{
	t_str	*tmp;
	int		i;

	if (info->posX > info->map_col || info->posY > info->map_row)
		return (-1);
	tmp = info->map;
	i = 0;
	while (tmp && i++ < info->posY)
		tmp = tmp->next;
	if (!tmp)
		return (-1);
	tmp->str[info->posX] = '0';
	return (0);
}

int	change_map_char_to_player(t_solong *info, int posX, int posY)
{
	int		i;
	t_str	*tmp;

	if (posX > info->map_col || posY > info->map_row)
		return (-1);
	i = 0;
	tmp = info->map;
	while (tmp && i++ < posY)
		tmp = tmp->next;
	if (!tmp)
		return (-1);
	tmp->str[posX] = 'P';
	return (0);
}

int	init_move(t_solong *info, int moveX, int moveY)
{
	if (set_pos_player(info))
		return (-1);
	if (autorised_position(info, (info->posX + moveX), (info->posY + moveY)))
		return (0);
	if (get_map_char(info, (info->posX + moveX), (info->posY + moveY))
		== COLLECT)
	{
		erase_player(info);
		change_map_char_to_player(info,
			(info->posX + moveX), (info->posY + moveY));
		info->coll_amount--;
	}
	else if (get_map_char(info,
			(info->posX + moveX), (info->posY + moveY)) == EXIT)
	{
		erase_player(info);
		change_map_char_to_player(info,
			(info->posX + moveX), (info->posY + moveY));
		return (exit_success(info));
	}
	if (get_map_char(info, (info->posX + moveX), (info->posY + moveY)) == FLOOR)
		return (erase_player(info) || change_map_char_to_player(info,
				(info->posX + moveX), (info->posY + moveY)));
	return (0);
}
