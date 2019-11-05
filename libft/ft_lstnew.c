/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:20:34 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/09 19:06:32 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		node->content = 0;
		node->content_size = 0;
	}
	else
	{
		node->content = malloc(sizeof(content) * content_size);
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
