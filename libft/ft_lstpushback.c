/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:28:11 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/12 15:31:55 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!lst)
	{
		ft_lstadd(alst, new);
		return ;
	}
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	new->next = NULL;
}
