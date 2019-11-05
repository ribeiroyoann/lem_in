/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:32:53 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/12 17:03:02 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t s2_size;

	s2_size = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (n && *s1)
	{
		if (n < s2_size)
			return (NULL);
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, s2_size) == 0)
				return ((char *)s1);
		}
		s1++;
		n--;
	}
	return (NULL);
}
