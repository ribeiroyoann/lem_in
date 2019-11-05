/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:12:56 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 18:24:27 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		INITIALIZE ENVIRONMENT STRUCTURE
*/

t_env		*init_env(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(t_env))))
		return (NULL);
	env->line = NULL;
	env->ant_nb = 0;
	env->flag_link = 0;
	env->links = NULL;
	env->start = NULL;
	env->end = NULL;
	env->queue = NULL;
	env->read = NULL;
	env->end_queue = env->queue;
	env->optimal_sol = NULL;
	env->path_nb = 0;
	env->total_len = 0;
	env->ants_sent = 0;
	env->steps = 2147483648;
	env->countsteps = 0;
	env->shortest_path = NULL;
	env->second_shortest = NULL;
	env->table = NULL;
	return (env);
}

/*
***		INITIALIZE HASH TABLE
*/

void		init_hashtable(t_room **table)
{
	int i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		table[i] = NULL;
		i++;
	}
}
