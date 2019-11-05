/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:10:46 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/17 16:22:15 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		PRINT LINKS OF A ROOM
*/

void	print_links(t_room *room)
{
	t_link *head;

	head = room->linked_rooms;
	ft_printf("room %s is connected to : ", room->name);
	while (head)
	{
		if (head->next)
			ft_printf("room %s, ", head->dest->name);
		else
			ft_printf("room %s", head->dest->name);
		head = head->next;
	}
}

/*
***		PRINT SINGLE PATH
*/

void	print_path(t_path *head)
{
	t_path *current;

	if (head)
	{
		current = head;
		while (current)
		{
			if (current->next)
				ft_printf("[%s] => ", current->room->name);
			else
				ft_printf("[%s]", current->room->name);
			current = current->next;
		}
		ft_printf("\n");
	}
}

/*
***		PRINT SET OF SOLUTION PATHS
*/

void	print_paths(t_sol *sol)
{
	t_sol		*head;
	t_path		*start;

	head = sol;
	if (!sol)
		return ;
	ft_printf("\nSOLUTION SET :\n");
	while (sol)
	{
		ft_printf("PATHLEN : %d, STEPS %lu\n", sol->pathlen, sol->steps);
		ft_printf("ANTS TO SEND IN THIS PATH : %d\n", sol->ants);
		start = sol->path;
		while (sol->path)
		{
			if (sol->path->next)
				ft_printf("[%s] => ", sol->path->room->name);
			else
				ft_printf("[%s]", sol->path->room->name);
			sol->path = sol->path->next;
		}
		sol->path = start;
		ft_printf("\n\n");
		sol = sol->next;
	}
	sol = head;
}

/*
***		PRINT QUEUE OF BFS
*/

void	print_queue(t_env *env)
{
	t_queue *queue;

	if (env->queue)
	{
		queue = env->queue;
		ft_printf("\nQUEUE : ");
		while (queue->next)
		{
			ft_printf("[room %s] , ", queue->room->name, queue);
			queue = queue->next;
		}
		ft_printf("[room %s]\n\n", queue->room->name, queue);
	}
}

/*
***		PRINT BFS PATH
*/

void	print_bfs(t_env *env)
{
	t_room *cur;

	cur = env->end;
	while (cur && ft_strcmp(cur->name, env->start->name))
	{
		ft_printf(" %s w=%d <-", cur->name, cur->weight);
		cur = cur->prev;
	}
	ft_printf("\n\n");
}
