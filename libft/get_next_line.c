/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:38:10 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/17 14:18:33 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *str, char *buffer, size_t sz)
{
	char	*tmp;
	char	*ret;

	buffer[sz] = '\0';
	if (ft_strlen(buffer) != sz)
		return (NULL);
	tmp = str;
	ret = ft_strjoin(str, buffer);
	free(tmp);
	return (ret);
}

char	*save_rest(char *str, int sz)
{
	char *tmp;
	char *ret;

	tmp = str;
	ret = ft_strdup(str + sz);
	free(tmp);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int				readsz;
	char			buffer[BUFF_SIZE + 1];
	static	char	*str;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	if (!str)
		str = ft_strdup("");
	while ((readsz = read(fd, buffer, BUFF_SIZE)))
	{
		if (!(str = read_line(str, buffer, readsz)))
			return (-1);
		if (ft_strchr(str, '\n'))
			break ;
	}
	readsz = 0;
	while (str[readsz] != '\n' && str[readsz])
		readsz++;
	*line = ft_strndup(str, readsz);
	if (str[readsz] == '\n')
		readsz++;
	str = save_rest(str, readsz);
	return (readsz > 0 ? 1 : 0);
}
