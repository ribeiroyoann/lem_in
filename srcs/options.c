/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:44:50 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/18 18:05:52 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			options(t_env *env, int ac, char **av)
{
	if (ac == 2 && !ft_strcmp(av[1], "-c"))
		ft_printf("\nTotal number of lines : %lu\n", env->countsteps);
	else if (ac == 2 && !ft_strcmp(av[1], "-p"))
		print_paths(env->optimal_sol);
	else if ((ac == 3
	&& ((!ft_strcmp(av[1], "-c") && !ft_strcmp(av[2], "-p"))
	|| (!ft_strcmp(av[2], "-c") && !ft_strcmp(av[1], "-p"))))
	|| (ac == 2 && (!(ft_strcmp(av[1], "-cp")) || !(ft_strcmp(av[1], "-pc")))))
	{
		print_paths(env->optimal_sol);
		ft_printf("\nTotal number of lines : %lu\n", env->countsteps);
	}
}
