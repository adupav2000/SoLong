/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:33:40 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 00:07:16 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

char	get_map_char(t_solong *info, int x, int y)
{
	t_str	*tmp;

	tmp = info->map;
	if (y > info->map_row || x > info->map_col || x < 0 || y < 0)
		return (-1);
	while (y > 0)
	{
		tmp = tmp->next;
		y--;
	}
	return (tmp->str[x]);
}

int		set_pos_player(t_solong *info)
{
	int		y;
	int		x;
	t_str	*tmp;

	y = 0;
	tmp = info->map;
	while (tmp)
	{
		x = 0;
		while (tmp->str[x] && tmp->str[x] != PLAYER)
			x++;
		if (tmp->str[x] == PLAYER)
		{
			info->posX = x;
			info->posY = y;
			return (0);
		}
		tmp = tmp->next;
		y++;
	}
	return (-1);
}