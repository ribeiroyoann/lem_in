/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:30:33 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/09 16:17:21 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sptr;

	sptr = (char *)s + ft_strlen(s);
	if (!s)
		return (0);
	while (*sptr != c)
	{
		if (sptr == s)
			return (0);
		sptr--;
	}
	return (sptr);
}
