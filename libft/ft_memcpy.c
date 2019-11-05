/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:28:13 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/09 17:41:18 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dsts;
	const unsigned char	*srcs;

	dsts = dst;
	srcs = src;
	while (n--)
	{
		*dsts = *srcs;
		dsts++;
		srcs++;
	}
	return (dst);
}
