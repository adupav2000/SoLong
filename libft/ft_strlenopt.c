/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenopt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:53:22 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/04/20 20:57:14 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	int	ft_strlenopt(const char *str, const char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}
