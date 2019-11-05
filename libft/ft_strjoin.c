/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:21:36 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/15 16:58:52 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
