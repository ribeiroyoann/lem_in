/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:36:38 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 12:00:40 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		NEW PATHLINK
*/

t_path		*create_pathlink(t_env *env, t_room *room)
{
	t_path *pathlink;

	if (room->inpath != 0 && (ft_strcmp(room->name, env->start->name)
	&& ft_strcmp(room->name, env->end->name)))
		return (NULL);
	room->inpath = 1;
	if (!(pathlink = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	pathlink->room = room;
	pathlink->ant_index = 0;
	pathlink->next = NULL;
	pathlink->prev = NULL;
	return (pathlink);
}

/*
***		CHECK LINK FLOWS
*/

int			check_flows(t_env *env, t_path **path, t_link **link, t_path **head)
{
	while (*link && (*link)->flow != 1)
		*link = (*link)->next;
	if (!(*link && ((*path)->next = create_pathlink(env, (*link)->dest))))
	{
		free_path(head);
		return (-1);
	}
	(*path)->next->prev = *path;
	*path = (*path)->next;
	*link = (*path)->room->linked_rooms;
	return (0);
}

/*
***		GET ONE PATH IN SOLUTION SYSTEM
*/

t_path		*get_path(t_env *env, t_room *next, t_sol *sol)
{
	t_path *path;
	t_path *head;
	t_link *link;

	if (next->inpath == 0)
	{
		if (!(path = create_pathlink(env, env->start))
		|| !(path->next = create_pathlink(env, next)))
			return (NULL);
		head = path;
		path = path->next;
		link = next->linked_rooms;
		sol->pathlen += 1;
		while (ft_strcmp(path->room->name, env->end->name))
		{
			if (check_flows(env, &path, &link, &head) == -1)
				return (NULL);
			sol->pathlen += 1;
		}
		env->total_len += sol->pathlen;
		return (head);
	}
	return (NULL);
}

/*
***		REMOVE PATH THAT IS TOO LONG
*/

int			remove_path(t_env *env, t_sol *remove)
{
	t_sol	*current;
	t_sol	*prev;

	current = env->current_sol;
	prev = env->current_sol;
	while (current != remove && current->next)
	{
		prev = current;
		current = current->next;
	}
	free_path(&(remove->path));
	if (current == env->current_sol && current->next)
		env->current_sol = current->next;
	else if (current->next)
		prev->next = current->next;
	else
		prev->next = NULL;
	free(remove);
	return (1);
}

/*
***		COPY PATH FOR COPY SOLUTION
*/

t_path		*copy_path(t_env *env, t_sol *solution)
{
	t_path		*head;
	t_path		*path;
	t_path		*current;
	t_path		*new;

	path = solution->path;
	head = NULL;
	new = NULL;
	current = NULL;
	while (path)
	{
		reset_inpath(env->current_sol);
		new = create_pathlink(env, path->room);
		new->prev = current;
		head = head ? head : new;
		if (current)
			current->next = new;
		current = new;
		path = path->next;
	}
	return (head);
}
