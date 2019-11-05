/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:10:07 by epham             #+#    #+#             */
/*   Updated: 2019/10/16 12:58:56 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***     CHECK BEFORE CHANGE SOURCE
*/

int			check_change_source(t_env *env, t_room *room, t_room *newprev)
{
	t_room		*current;

	current = newprev->prev;
	while (current)
	{
		if (!ft_strcmp(current->name, env->start->name))
			return (1);
		if (!ft_strcmp(current->name, room->name)
		|| !(ft_strcmp(current->name, newprev->name)))
			return (-1);
		current = current->prev;
	}
	return (0);
}

/*
***     CHANGE SOURCE
*/

void		change_source(t_env *env, t_room *room, t_link *link, t_room *new)
{
	t_room		*prev;
	int			roomweight;
	int			prevweight;

	prev = room->prev;
	if (prev)
	{
		roomweight = link->flow == -1 ? new->weight - 1 : new->weight + 1;
		prevweight = room->from->flow == 1 ? roomweight - 1 : roomweight + 1;
		room->prev = new;
		room->prev_flow = link->flow;
		room->weight = roomweight;
		if (prevweight <= prev->weight)
		{
			if (check_change_source(env, prev, room) == 1)
			{
				prev->prev = room;
				prev->weight = prevweight;
				prev->from = room->from->rev;
			}
		}
		room->from = link;
	}
}

/*
***		OPTI REMONTADA
*/

int			remontada(t_env *env, t_room *current, t_link *current_link)
{
	t_link		*head;

	head = current_link;
	while (current_link)
	{
		if (current_link->flow == -1 && current_link->dest->inqueue == 0
		&& current->prev_flow == 0)
		{
			insert_after_queue(env, current_link, current);
			depthfirst_queue(env, current_link->dest);
			current_link = head;
			return (1);
		}
		current_link = current_link->next;
	}
	current_link = head;
	return (0);
}

/*
***     DEPTH FIRST ON NEGATIVE FLOWS
*/

void		depthfirst_queue(t_env *env, t_room *room)
{
	t_link		*link;

	link = room->linked_rooms;
	while (link)
	{
		if (link->flow == -1 && link->dest->inqueue != 1
		&& ft_strcmp(link->dest->name, env->start->name)
		&& ft_strcmp(link->dest->name, env->end->name))
		{
			insert_before_queue(env, link, link->rev->dest);
			link = link->dest->linked_rooms;
		}
		else
			link = link->next;
	}
}
