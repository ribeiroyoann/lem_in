/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:57:31 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 13:52:17 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***			CHECK IF START AND END STILL HAVE AVAILABLE LINKS
*/

int			check_start_end(t_env *env)
{
	t_link		*start;
	t_link		*end;
	int			fullstart;
	int			fullend;

	start = env->start->linked_rooms;
	end = env->end->linked_rooms;
	fullend = 1;
	fullstart = 1;
	while (start && end)
	{
		fullstart = start->flow != 1 ? 0 : 1;
		fullend = end->rev->flow != 1 ? 0 : 1;
		if (fullstart)
			start = start->next;
		if (fullend)
			end = end->next;
		if (!fullstart && !fullend)
			return (1);
	}
	return (0);
}

/*
***     INITIALIZE BFS : PREV TO NULL AND VISITED TO 0
*/

int			init_bfs(t_env *env)
{
	t_queue		*head;
	t_queue		*tmp;

	if (env->queue)
	{
		head = env->queue;
		while (head)
		{
			head->room->prev = NULL;
			head->room->visited = 0;
			head->room->inqueue = 0;
			head->room->weight = 0;
			tmp = head;
			head = head->next;
			free(tmp);
		}
		env->queue = NULL;
		env->end_queue = NULL;
	}
	if (!check_start_end(env))
		return (0);
	return (1);
}

/*
***     BFS
*/

int			bfs(t_env *env)
{
	t_room		*current;
	t_queue		*queue;

	current = env->start;
	if (env->optimal_sol && env->optimal_sol->pathlen == 1)
		return (0);
	if (init_bfs(env))
	{
		current->visited = 1;
		get_queue(env, env->start);
		if (!env->queue)
			return (0);
		queue = env->queue;
		current = queue->room;
		while (ft_strcmp(current->name, env->end->name))
		{
			get_queue(env, current);
			if (!queue->next)
				return (0);
			queue = queue->next;
			current = queue->room;
		}
		return (1);
	}
	return (0);
}
