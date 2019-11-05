/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:29 by epham             #+#    #+#             */
/*   Updated: 2019/10/17 15:25:47 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_letter(char *line, char letter)
{
	int		count;

	count = 0;
	while (*line)
	{
		if (*line == letter)
			count++;
		line++;
	}
	return (count);
}

int		is_link(char *line)
{
	char	**split;
	int		count;
	int		ret;

	count = 0;
	ret = 0;
	if (is_comment(line))
		return (0);
	if (count_letter(line, '-') != 1)
		return (0);
	if (!(split = ft_strsplit(line, '-')))
		return (0);
	while (split[count])
		count++;
	if (count == 2)
	{
		if (!ft_strcmp(split[0], split[1]))
			ret = 0;
		if (count_letter(line, '-') > 1)
			ret = 0;
		ret = 1;
	}
	ft_tabdel(split);
	return (ret);
}
