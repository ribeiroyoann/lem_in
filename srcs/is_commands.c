/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:05 by epham             #+#    #+#             */
/*   Updated: 2019/10/11 16:42:51 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		CHECK IF LINE IS A COMMAND START/END
*/

int		is_command(char *line)
{
	if (line && ft_strlen(line) >= 2)
		if (!ft_strncmp(line, "##", 2))
			return (1);
	return (0);
}

/*
***		CHECK WHETHER COMMAND IS START OR END
*/

int		command_type(char *line)
{
	if (!ft_strcmp("##start", line))
		return (1);
	if (!ft_strcmp("##end", line))
		return (2);
	return (0);
}

/*
***		CHECK IF LINE IS A COMMENT
*/

int		is_comment(char *line)
{
	if (line && ft_strlen(line))
		if (!is_command(line) && !ft_strncmp(line, "#", 1))
			return (1);
	return (0);
}
