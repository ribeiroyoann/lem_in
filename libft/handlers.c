/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:34:00 by yoann             #+#    #+#             */
/*   Updated: 2019/04/02 16:49:59 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_jumptable(t_jumptable handlers[128])
{
	handlers['d'] = &handle_int;
	handlers['D'] = &handle_int;
	handlers['i'] = &handle_int;
	handlers['o'] = &handle_unsigned;
	handlers['O'] = &handle_unsigned;
	handlers['u'] = &handle_unsigned;
	handlers['U'] = &handle_unsigned;
	handlers['x'] = &handle_unsigned;
	handlers['X'] = &handle_unsigned;
	handlers['b'] = &handle_unsigned;
	handlers['f'] = &handle_float;
	handlers['F'] = &handle_float;
	handlers['s'] = &handle_string;
	handlers['S'] = &handle_wstring;
	handlers['c'] = &handle_char;
	handlers['C'] = &handle_wchar;
	handlers['p'] = &handle_pointer;
	handlers['%'] = &handle_escape;
}

t_jumptable	init_table(char c)
{
	static t_jumptable		handlers[128];

	handlers['d'] = NULL;
	if (!handlers['d'])
		set_jumptable(handlers);
	if (ft_isascii(c) && handlers[(int)c])
		return (handlers[(int)c]);
	else
		return (NULL);
}
