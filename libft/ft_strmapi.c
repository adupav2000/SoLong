/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:12:19 by adu-pavi          #+#    #+#             */
/*   Updated: 2021/04/20 20:56:18 by adu-pavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret_val;

	i = -1;
	ret_val = NULL;
	if (!s)
		return (0);
	ret_val = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(ret_val))
		return (0);
	i = 0;
	while (s[i])
	{
		ret_val[i] = (*f)(i, s[i]);
		i++;
	}
	ret_val[i] = '\0';
	return (ret_val);
}
