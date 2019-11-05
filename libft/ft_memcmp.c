/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:05 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/09 17:36:40 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1ptr;
	const unsigned char *s2ptr;

	if (!n)
		return (0);
	s1ptr = s1;
	s2ptr = s2;
	while (--n && *s1ptr == *s2ptr)
	{
		s1ptr++;
		s2ptr++;
	}
	return (*s1ptr - *s2ptr);
}
