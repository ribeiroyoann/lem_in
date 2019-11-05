/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:12:42 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 11:55:59 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		FREE PATH
*/

void	free_path(t_path **path)
{
	t_path *tmp;
	t_path *head;

	head = *path;
	while (head)
	{
		tmp = (head);
		(head) = (head)->next;
		free(tmp);
	}
	*path = NULL;
}

/*
***		FREE SOL
*/

int		free_sol(t_sol **sol)
{
	t_sol	*tmp;
	t_sol	*head;

	head = *sol;
	if (head)
	{
		while (head)
		{
			if ((head)->path)
			{
				free_path(&((head)->path));
			}
			tmp = head;
			head = (head)->next;
			free(tmp);
		}
		*sol = NULL;
	}
	return (1);
}

/*
***		FREE QUEUE FROM BFS
*/

void	free_queue(t_env *env)
{
	t_queue	*head;
	t_queue	*tmp;

	if (env->queue)
	{
		head = env->queue;
		while (head)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
		env->queue = NULL;
		env->end_queue = NULL;
	}
}

/*
***		FREE ENVIRONMENT CONTENT
*/

void	free_env(t_env *env)
{
	free_lines(env->read);
	ft_strdel(&env->line);
	if (env->queue)
		free_queue(env);
	if (env->current_sol != NULL)
		free_sol(&env->current_sol);
	if (env->optimal_sol != NULL)
		free_sol(&env->optimal_sol);
	free_table(env->table);
}

/*
***		ERROR CASES
*/

void	ft_error(int error, t_env *env)
{
	if (error == 1)
		error_invalid_file(env);
	if (error == 2)
		room_problems(env, 1);
	if (error == 3)
		invalid_ants(env);
	if (error == 4)
		room_problems(env, 4);
	if (error == 5)
		no_path(env);
	if (error == 6)
		room_problems(env, 2);
	if (error == 7)
		ft_putstr_fd("MALLOC FAILED\n", 2);
	if (error == 8)
		room_problems(env, 3);
	if (error == 9)
		link_to_itself(env);
	if (error == 10)
		room_problems(env, 5);
	if (error == 11)
		error_invalid_file(env);
	free(env);
	exit(1);
}
