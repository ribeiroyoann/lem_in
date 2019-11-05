/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:15:38 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/14 16:54:38 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static int		word_len(char const *str, char c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!s || !(tab = malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i < word_count(s, c))
	{
		k = 0;
		tab[i] = ft_strnew(word_len(&s[j], c) + 1);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
