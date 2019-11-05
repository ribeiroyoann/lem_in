/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:11:33 by yoribeir          #+#    #+#             */
/*   Updated: 2019/10/15 15:41:25 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
***		COMPUTE HASH VALUE (INDEX) OF ROOM
*/

unsigned long long	hash_value(char *key)
{
	unsigned long long	hashedvalue;

	hashedvalue = 0;
	while (*key)
	{
		hashedvalue = *key + 31 * hashedvalue;
		key++;
	}
	return (hashedvalue % TABLE_SIZE);
}

/*
***		INSERT ROOM IN HASH TABLE
*/

void				insert_hash_table(t_room **table, t_room *room, t_env *env)
{
	t_room *newnode;
	t_room *tmp;
	size_t hashedvalue;

	if (find_room(table, room->name))
		ft_error(8, env);
	hashedvalue = hash_value(room->name);
	if (table[hashedvalue] == NULL)
		table[hashedvalue] = room;
	else
	{
		newnode = room;
		tmp = table[hashedvalue];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newnode;
	}
}

/*
***		FREE HASH TABLE
*/

void				free_table(t_room **table)
{
	int i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		if (table[i])
			free_rooms(table[i]);
		i++;
	}
	free(table);
}

/*
***		FREE ROOM STRUCTURE
*/

void				free_rooms(t_room *rooms)
{
	t_room *tmp;
	t_room *tmp1;

	tmp = rooms;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		if (tmp1->linked_rooms)
			free_links(tmp1->linked_rooms);
		ft_strdel(&tmp1->name);
		free(tmp1);
		tmp1 = NULL;
	}
}

/*
***		FREE LINK STRUCTURE
*/

void				free_links(t_link *links)
{
	t_link	*tmp;
	t_link	*tmp1;

	tmp = links;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
		tmp1 = NULL;
	}
}
