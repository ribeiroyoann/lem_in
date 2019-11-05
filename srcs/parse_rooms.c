/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:25:56 by anonymous         #+#    #+#             */
/*   Updated: 2019/10/15 15:43:25 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		CREATE ROOM
*/

t_room	*create_room(char *line)
{
	char	**split;
	t_room	*room;

	if (!(split = ft_strsplit(line, ' ')))
		return (NULL);
	if (!(room = ft_memalloc(sizeof(t_room))))
		return (NULL);
	room->name = ft_strdup(split[0]);
	room->coord_x = ft_atoi(split[1]);
	room->coord_y = ft_atoi(split[2]);
	ft_tabdel(split);
	room->linked_rooms = NULL;
	room->visited = 0;
	room->inqueue = 0;
	room->inpath = 0;
	room->prev_flow = 0;
	room->weight = 0;
	room->from = NULL;
	room->next = NULL;
	room->prev = NULL;
	return (room);
}

/*
***		PARSE START ROOM AFTER COMMAND
*/

void	parse_start(t_env *env, t_room **table)
{
	t_room	*room;

	room = NULL;
	if (env->start != NULL)
	{
		ft_strdel(&env->line);
		ft_error(6, env);
	}
	ft_strdel(&env->line);
	get_line(env);
	while (is_comment(env->line) || (is_command(env->line) &&
	!command_type(env->line)))
	{
		free(env->line);
		get_line(env);
	}
	if (!is_room(env->line))
	{
		ft_strdel(&env->line);
		ft_error(4, env);
	}
	room = create_room(env->line);
	insert_hash_table(table, room, env);
	env->start = room;
}

/*
***		PARSE END ROOM AFTER COMMAND
*/

void	parse_end(t_env *env, t_room **table)
{
	t_room	*room;

	room = NULL;
	if (env->end != NULL)
	{
		ft_strdel(&env->line);
		ft_error(6, env);
	}
	ft_strdel(&env->line);
	get_line(env);
	while (is_comment(env->line) || (is_command(env->line) &&
	!command_type(env->line)))
	{
		free(env->line);
		get_line(env);
	}
	if (!is_room(env->line))
	{
		ft_strdel(&env->line);
		ft_error(4, env);
	}
	room = create_room(env->line);
	insert_hash_table(table, room, env);
	env->end = room;
}

/*
***		PARSE START OR END
*/

void	parse_startend(t_env *env, t_room **table)
{
	if (command_type(env->line) == 1)
		parse_start(env, table);
	if (command_type(env->line) == 2)
		parse_end(env, table);
}
