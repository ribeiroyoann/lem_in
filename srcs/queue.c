/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:17:16 by epham             #+#    #+#             */
/*   Updated: 2019/10/16 13:19:55 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***     CREATE QUEUE MAILLON AND APPEND IT
*/

void		append_queue(t_env *env, t_link *link, t_room *prev)
{
	t_queue		*last;

	if (!(last = (t_queue*)malloc(sizeof(t_queue))))
		return ;
	last->room = link->dest;
	link->dest->inqueue = 1;
	link->dest->from = link;
	last->room->prev = prev;
	last->prev_flow = link->flow;
	link->dest->weight = link->flow == -1 ? prev->weight - 1 : prev->weight + 1;
	last->next = NULL;
	if (!env->queue)
	{
		env->queue = last;
		env->end_queue = env->queue;
		return ;
	}
	env->end_queue->next = last;
	env->end_queue = last;
}

/*
***		INSERT TO QUEUE IN MIDDLE BUT AFTER PREV
*/

void		insert_after_queue(t_env *env, t_link *link, t_room *prev)
{
	t_queue		*insert;
	t_queue		*find;
	t_queue		*tmp;

	find = env->queue;
	if (!(insert = (t_queue*)malloc(sizeof(t_queue))))
		return ;
	insert->room = link->dest;
	link->dest->inqueue = 1;
	link->dest->from = link;
	insert->room->prev = prev;
	insert->prev_flow = link->flow;
	link->dest->weight = link->flow == -1 ? prev->weight - 1 : prev->weight + 1;
	insert->next = NULL;
	while (find && ft_strcmp(find->room->name, prev->name))
		find = find->next;
	tmp = find->next;
	find->next = insert;
	insert->next = tmp;
	if (!tmp)
		env->end_queue = insert;
}

/*
***		INSERT TO QUEUE IN MIDDLE BUT BEFORE PREV
*/

void		insert_before_queue(t_env *env, t_link *link, t_room *prev)
{
	t_queue		*insert;
	t_queue		*find;
	t_queue		*tmp;

	find = env->queue;
	if (!(insert = (t_queue*)malloc(sizeof(t_queue))))
		return ;
	insert->room = link->dest;
	link->dest->inqueue = 1;
	link->dest->from = link;
	link->dest->prev = prev;
	insert->prev_flow = link->flow;
	link->dest->weight = link->flow == -1 ? prev->weight - 1 : prev->weight + 1;
	insert->next = NULL;
	while (find->next && ft_strcmp(find->next->room->name, prev->name))
		find = find->next;
	tmp = find->next;
	find->next = insert;
	insert->next = tmp;
}

/*
***     GET QUEUE FROM ROOM
*/

void		get_queue(t_env *env, t_room *room)
{
	t_link		*currlink;
	int			weight;

	weight = 0;
	room->visited = 1;
	currlink = room->linked_rooms;
	if (remontada(env, room, currlink) == 1)
		return ;
	while (currlink)
	{
		weight = currlink->flow == -1 ? room->weight - 1 : room->weight + 1;
		if (currlink->dest->inqueue == 0 && currlink->flow != 1)
			append_queue(env, currlink, room);
		else if (ft_strcmp(currlink->dest->name, env->start->name)
		&& ft_strcmp(currlink->dest->name, env->end->name)
		&& currlink->dest->inqueue && currlink->dest->weight > weight)
		{
			if (check_change_source(env, currlink->dest, room) == 1)
				change_source(env, currlink->dest, currlink, room);
		}
		currlink = currlink->next;
	}
}
