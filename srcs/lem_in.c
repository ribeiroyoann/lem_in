/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:59:33 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 18:29:29 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int				main(int ac, char **av)
{
	t_env			*env;
	unsigned int	i;

	i = 0;
	if (!(env = init_env()))
		return (0);
	parse(env);
	print_map(env);
	if (edmond(env) != 0)
	{
		env->countsteps = env->steps;
		print_sol(env, env->optimal_sol, i);
	}
	options(env, ac, av);
	free_env(env);
	free(env);
	return (0);
}
