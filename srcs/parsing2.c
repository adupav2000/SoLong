/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:21:28 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/07/16 18:24:53 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SoLong.h"

int	save_map(int fd, t_solong *allinfo)
{
	t_str	*m;
	char	*tmp;

	allinfo->map = (t_str *)malloc(sizeof(t_str));
	if (!allinfo->map)
		return (exit_error(allinfo, "Malloc erro"));
	if (get_next_line(fd, &tmp))
		allinfo->map->str = tmp;
	else
		return (exit_error(allinfo, "Map has no line"));
	allinfo->map->next = NULL;
	m = allinfo->map;
	while (get_next_line(fd, &tmp) || ft_strlen(tmp) > 0)
	{
		m->next = (t_str *)malloc(sizeof(t_str));
		if (!m->next)
			return (exit_error(allinfo, "Malloc erro"));
		m = m->next;
		m->next = NULL;
		m->str = tmp;
	}
	return (0);
}

int	check_walls(t_solong *info)
{
	size_t		i;
	size_t		length;
	t_str		*map;

	map = info->map;
	i = 0;
	while (map && map->str[i] == '1')
		i++;
	if (i != ft_strlen(map->str))
		return (exit_error(info, " Map not surrounded by wall"));
	length = ft_strlen(map->str);
	while (map && map->next)
	{
		if (map->str[0] != '1' || map->str[ft_strlen(map->str) - 1] != '1'
			|| ft_strlen(map->str) != length)
			return (exit_error(info, " Map not surrounded by wall"));
		map = map->next;
	}
	i = 0;
	while (map && map->str[i] == '1' && map->str[i] != 0)
		i++;
	if (i != ft_strlen(map->str))
		return (exit_error(info, " Map not surrounded by wall"));
	return (0);
}

int	is_right_map_char(t_solong *info, char map_char)
{
	if ((map_char != WALL && map_char != FLOOR
			&& map_char != COLLECT && map_char != EXIT
			&& map_char != PLAYER)
		|| (map_char == PLAYER && info->play_set))
		return (-1);
	if (map_char == PLAYER)
		info->play_set = 1;
	if (map_char == COLLECT)
	{
		info->coll_set = 1;
		info->coll_amount += 1;
	}
	if (map_char == EXIT)
		info->exit_set += 1;
	return (0);
}

int	init_solong(t_solong *info)
{
	info->play_set = 0;
	info->exit_set = 0;
	info->coll_set = 0;
	info->coll_amount = 0;
	info->mov_num = 0;
	info->posX = 0;
	info->posY = 0;
	info->map_w = 0;
	info->map_h = 0;
	return (0);
}

int	check_single_user_and_correct(t_solong *info, t_str *map)
{
	int		x;
	int		y;
	t_str	*tmp;

	x = 0;
	y = 0;
	tmp = map;
	while (tmp)
	{
		x = 0;
		while (tmp->str[x])
		{
			if (is_right_map_char(info, tmp->str[x]))
				return (exit_error(info, "There is a wrong char in the map"));
			x++;
		}
		tmp = tmp->next;
		y++;
	}
	info->map_col = x;
	info->map_row = y;
	if (!(info->coll_set) || !(info->exit_set) || !(info->play_set))
		return (-1);
	return (0);
}
