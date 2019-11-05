/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:18:14 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/15 15:43:46 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		ADD LINK TO ROOM
*/

void	add_link(t_room *room, t_link *link)
{
	t_link	*tail;

	if (!room->linked_rooms)
	{
		room->linked_rooms = link;
		return ;
	}
	tail = room->linked_rooms;
	while (tail->next)
		tail = tail->next;
	tail->next = link;
}

/*
***		CHECK THAT LINK DOESNT ALREADY EXISTS
*/

int		check_links(t_room *start, t_room *end)
{
	t_link	*links;

	links = start->linked_rooms;
	while (start->linked_rooms)
	{
		if (!ft_strcmp(start->linked_rooms->dest->name, end->name))
		{
			start->linked_rooms = links;
			return (0);
		}
		start->linked_rooms = start->linked_rooms->next;
	}
	start->linked_rooms = links;
	return (1);
}

/*
***		CREATE LINK
*/

void	*create_links(t_env *env, t_room *start, t_room *end)
{
	t_link	*firstlink;
	t_link	*secondlink;

	if (!check_links(start, end))
		return (start);
	if (!(firstlink = ft_memalloc(sizeof(t_link))))
		return (NULL);
	if (!(secondlink = ft_memalloc(sizeof(t_link))))
		return (NULL);
	firstlink->from = start;
	firstlink->dest = end;
	secondlink->from = end;
	secondlink->dest = start;
	firstlink->flow = 0;
	secondlink->flow = 0;
	firstlink->rev = secondlink;
	secondlink->rev = firstlink;
	firstlink->next = NULL;
	secondlink->next = NULL;
	add_link(start, firstlink);
	add_link(end, secondlink);
	env->flag_link = 1;
	return (firstlink);
}

/*
***		CHECK THAT ROOMS FROM LINK EXIST
*/

t_room	*find_room(t_room **table, char *room_name)
{
	t_room	*current;
	int		index;

	index = hash_value(room_name);
	current = table[index];
	if (!current)
		return (NULL);
	while (current)
	{
		if (!ft_strcmp(current->name, room_name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

/*
***		PARSE LINK
*/

void	*get_link(t_env *env, t_room **table, char *line)
{
	char	*start;
	char	*end;
	char	**split;
	t_room	*start_room;
	t_room	*end_room;

	if ((split = (ft_strsplit(line, '-'))))
	{
		start = ft_strdup(split[0]);
		end = ft_strdup(split[1]);
		start_room = find_room(table, start);
		end_room = find_room(table, end);
		ft_tabdel(split);
		if (start_room)
			free(start);
		if (end_room)
			free(end);
		if (start_room && end_room && (start_room != end_room))
			return (create_links(env, start_room, end_room));
		if (start_room == end_room)
			ft_error(9, env);
		else
			ft_error(2, env);
	}
	return (NULL);
}
