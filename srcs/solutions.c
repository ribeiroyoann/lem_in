/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 19:22:01 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 11:54:04 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		NEW PATH IN SAME SOLUTION SYSTEM
*/

t_sol		*create_solution(t_env *env, t_room *next, int copy, t_sol *path)
{
	t_sol *new;

	if (!(new = (t_sol*)malloc(sizeof(t_sol))))
		return (NULL);
	new->ants = 0;
	new->ants_sent = 0;
	new->ants_arrived = 0;
	new->pathlen = 0;
	new->steps = 0;
	new->next = NULL;
	if (copy == 0)
	{
		if (!(new->path = get_path(env, next, new)))
		{
			free(new);
			return (NULL);
		}
	}
	else
		new->path = copy_path(env, path);
	return (new);
}

/*
***		APPEND SOLUTION TO HEAD
*/

void		append_sol(t_env *env, t_sol *new, t_sol *to)
{
	t_sol *first;

	first = to;
	while (first->next)
		first = first->next;
	first->next = new;
	first = to;
	if (to == env->current_sol)
		env->path_nb += 1;
}

/*
***		DISTRIBUTES ANTS OVER ALL PATHS OF SOLUTION
*/

t_sol		*dispatch_ants(t_env *env, t_sol *head)
{
	t_sol	*sol;

	sol = head;
	while (sol)
	{
		sol->ants = (env->ant_nb + env->total_len)
		/ env->path_nb - sol->pathlen;
		if (sol->ants < 0)
			return (sol);
		env->ants_sent += sol->ants;
		sol = sol->next;
	}
	sol = head;
	return (NULL);
}

/*
***		COPY CURRENT SOLUTION
*/

t_sol		*copy_solution(t_env *env)
{
	t_sol	*curr_sol;
	t_sol	*new;
	t_sol	*head;

	curr_sol = env->current_sol;
	head = NULL;
	new = NULL;
	while (curr_sol)
	{
		new = create_solution(env, curr_sol->path->room, 1, curr_sol);
		new->pathlen = curr_sol->pathlen;
		new->steps = env->current_sol->steps;
		new->ants = curr_sol->ants;
		if (!head)
			head = new;
		else
			append_sol(env, new, head);
		curr_sol = curr_sol->next;
	}
	free_sol(&env->current_sol);
	return (head);
}

/*
***		REPLACE OPTIMAL SOLUTION
*/

void		update_solution(t_env *env)
{
	free_sol(&env->optimal_sol);
	env->optimal_sol = copy_solution(env);
	env->steps = env->optimal_sol->steps;
}
