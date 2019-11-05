/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:42:11 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 18:28:54 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		CASE OF START END
*/

void	print_end(t_env *env, t_sol *sol, t_path *head)
{
	unsigned long	i;
	int				first;

	i = 1;
	first = 0;
	sol->path = head;
	while ((long)i <= sol->ants)
	{
		if (!first)
		{
			ft_printf("L%lu-%s", i, env->end->name);
			first = 1;
		}
		else
			ft_printf(" L%lu-%s", i, env->end->name);
		i++;
	}
	env->steps = 1;
	env->countsteps = 1;
	ft_putchar('\n');
}

/*
***		MOVE ANTS
*/

void	print_ants(t_env *env, t_sol *sol, unsigned long *i)
{
	if (!ft_strcmp(sol->path->room->name, env->end->name))
	{
		if (sol->ants_arrived < sol->ants_sent)
		{
			if ((*i)++ != 0)
				ft_printf(" ");
			ft_printf("L%lu-%s", sol->path->ant_index, sol->path->room->name);
			sol->ants_arrived++;
		}
	}
	else if (sol->path->ant_index != sol->path->next->ant_index)
	{
		if ((*i)++ != 0)
			ft_printf(" ");
		ft_printf("L%lu-%s", sol->path->ant_index, sol->path->room->name);
	}
	sol->path = sol->path->prev;
}

/*
***		UPDATING ANT INDEX FOR EACH NODE
*/

void	move_ants(t_env *env, t_sol *sol, t_path *head, unsigned long *i)
{
	while (ft_strcmp(sol->path->room->name, head->next->room->name))
	{
		if (sol->path->prev)
			sol->path->ant_index = sol->path->prev->ant_index;
		print_ants(env, sol, i);
	}
	if (!ft_strcmp(sol->path->room->name, head->next->room->name)
	&& (long)sol->ants_sent < sol->ants)
	{
		sol->path->ant_index = env->next_ant;
		sol->ants_sent++;
		if ((*i)++ != 0)
			ft_printf(" ");
		ft_printf("L%lu-%s", sol->path->ant_index, sol->path->room->name);
		(env->next_ant)++;
	}
	sol->path = head;
}

/*
***		PRINT SOLUTION
*/

void	print_sol(t_env *env, t_sol *solution, unsigned long i)
{
	t_sol			*sol;
	t_path			*head;

	env->next_ant = 1;
	sol = solution;
	while (env->steps)
	{
		solution = sol;
		i = 0;
		while (solution)
		{
			head = solution->path;
			if (!ft_strcmp(solution->path->room->name, env->start->name))
				solution->path = solution->path->next;
			while (solution->path->ant_index && solution->path->next)
				solution->path = solution->path->next;
			if (!ft_strcmp(head->next->room->name, env->end->name))
				return (print_end(env, solution, head));
			move_ants(env, solution, head, &i);
			solution->path = head;
			solution = solution->next;
		}
		(env->steps)--;
		ft_printf("\n");
	}
}
