/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:56:06 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/28 17:47:30 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_nblen(unsigned long long n, int base)
{
	unsigned int	count;

	count = 1;
	while (n /= base)
		count++;
	return (count);
}
