/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:31:50 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/19 18:42:34 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int		i;
	int		y;

	if (!(find[0]))
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		y = 0;
		while (find[y] == str[i + y] && find[y])
		{
			if (find[y + 1] == '\0')
				return ((char *)str + i);
			y++;
		}
		i++;
	}
	return (0);
}
