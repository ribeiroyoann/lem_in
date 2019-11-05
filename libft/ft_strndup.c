/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:09:48 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/15 15:10:24 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *src, int n)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(src);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (src[i] && n)
	{
		ret[i] = src[i];
		n--;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
