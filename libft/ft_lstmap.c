/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:54:24 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/14 17:48:58 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;

	if (!lst)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		if (!f(lst))
			return (NULL);
		ft_lstpushback(&newlst, f(lst));
		lst = lst->next;
	}
	return (newlst);
}
