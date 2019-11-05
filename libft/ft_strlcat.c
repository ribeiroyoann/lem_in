/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:49:40 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/12 16:13:57 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int				i;
	unsigned int	srclen;
	unsigned int	destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = 0;
	if (size < destlen)
		return (srclen + size);
	while (destlen + i < size - 1 && src[i])
	{
		dest[i + destlen] = src[i];
		i++;
	}
	dest[i + destlen] = '\0';
	return (destlen + srclen);
}
