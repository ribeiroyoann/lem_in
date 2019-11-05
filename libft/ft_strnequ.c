/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:09:30 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/09 18:12:34 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	while (*s2 && *s1 && n--)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (!*s1 == !*s2)
		return (1);
	return (0);
}
