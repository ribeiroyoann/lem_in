/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:46:02 by epham             #+#    #+#             */
/*   Updated: 2019/10/18 18:01:18 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		error_invalid_file(t_env *env)
{
	ft_strdel(&env->line);
	if (env->read)
		free_lines(env->read);
	if (env->table)
		free_table(env->table);
	ft_putstr_fd("ERROR : NOT A VALID MAP\n", 2);
}

void		invalid_ants(t_env *env)
{
	ft_strdel(&env->line);
	ft_putstr_fd("ERROR : INVALID NUMBER OF ANTS\n", 2);
}

void		room_problems(t_env *env, int i)
{
	ft_strdel(&env->line);
	free_lines(env->read);
	free_table(env->table);
	if (i == 1)
		ft_putstr_fd("ERROR : LINK TO UNKNOWN ROOM\n", 2);
	else if (i == 2)
		ft_putstr_fd("ERROR : ROOM END OR START ALREADY EXISTS\n", 2);
	else if (i == 3)
		ft_putstr_fd("ERROR : DOUBLE ROOM\n", 2);
	else if (i == 4)
		ft_putstr_fd("ERROR : ROOM START OR END MISSING\n", 2);
	else if (i == 5)
		ft_putstr_fd("ERROR : ROOM AFTER LINKS\n", 2);
}

void		no_path(t_env *env)
{
	ft_strdel(&env->line);
	free_lines(env->read);
	free_table(env->table);
	free_queue(env);
	ft_putstr_fd("ERROR : THERE IS NO PATH BETWEEN ROOM START AND END\n", 2);
}

void		link_to_itself(t_env *env)
{
	ft_strdel(&env->line);
	free_lines(env->read);
	free_table(env->table);
	ft_putstr_fd("ERROR : ONE ROOM IS LINKED TO ITSELF\n", 2);
}
