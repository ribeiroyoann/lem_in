/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:35:56 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/12 14:05:39 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		ret;

	neg = 1;
	ret = 0;
	while (*str == '\v' || *str == '\t' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0' && *str)
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * neg);
}
