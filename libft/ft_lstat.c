/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:38:07 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/12 15:39:45 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, unsigned int nbr)
{
	unsigned int i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		if (i == nbr)
			return (lst);
		i++;
		lst = lst->next;
	}
	return (0);
}
