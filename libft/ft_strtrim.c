/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:26:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/09 14:45:09 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && ft_isblanko(s[i]))
		i++;
	while (s[j] && ft_isblanko(s[j]) && j > i)
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
