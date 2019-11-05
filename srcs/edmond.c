/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmond.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:42:39 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 18:28:39 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		UPDATE FLOWS
*/

static void		update_flows(t_env *env)
{
	t_link	*link;
	t_room	*current;

	current = env->end;
	while (ft_strcmp(current->name, env->start->name))
	{
		link = current->linked_rooms;
		while (link)
		{
			if (!ft_strcmp(link->dest->name, current->prev->name))
				break ;
			link = link->next;
		}
		if (link)
		{
			link->flow -= 1;
			link->rev->flow += 1;
			current = current->prev;
		}
	}
}

/*
***		RESET INPATH VARIABLE
*/

void			reset_inpath(t_sol *solution)
{
	t_sol		*head_sol;
	t_path		*head_path;

	if (solution)
	{
		head_sol = solution;
		while (solution)
		{
			head_path = solution->path;
			while (solution->path)
			{
				solution->path->room->inpath = 0;
				solution->path = solution->path->next;
			}
			solution->path = head_path;
			solution = solution->next;
		}
		solution = head_sol;
	}
}

/*
***		FIND ALL SOLUTION PATHS
*/

static int		find_sol_paths(t_env *env)
{
	t_sol		*current_sol;
	t_link		*link;
	int			i;

	i = 0;
	link = env->start->linked_rooms;
	while (link)
	{
		if (link->flow == 1)
		{
			if (i == 0 && (env->current_sol =
			create_solution(env, link->dest, 0, NULL)))
			{
				i = 1;
				env->path_nb += 1;
			}
			else if (i == 1 && (current_sol =
			create_solution(env, link->dest, 0, NULL)))
				append_sol(env, current_sol, env->current_sol);
		}
		link = link->next;
	}
	return (i);
}

/*
***		EDMONDS KARP
*/

int				edmond(t_env *env)
{
	int				first;
	unsigned long	steps;

	while (bfs(env) == 1)
	{
		env->path_nb = 0;
		env->total_len = 0;
		env->ants_sent = 0;
		update_flows(env);
		first = find_sol_paths(env);
		if (first == 0 && !env->current_sol && !env->optimal_sol)
			return (0);
		else if (env->current_sol && first)
		{
			reset_inpath(env->current_sol);
			if ((steps = check_steps(env)) < 0 && free_sol(&env->current_sol))
				continue ;
			env->current_sol->steps = steps;
			if (env->current_sol->steps <= env->steps)
				update_solution(env);
			else
				free_sol(&env->current_sol);
		}
	}
	return (1);
}
