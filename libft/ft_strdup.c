/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:22:33 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/09 16:04:12 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(src);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
