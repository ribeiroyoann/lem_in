/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:38:56 by yoann             #+#    #+#             */
/*   Updated: 2019/03/15 16:32:56 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_char(t_parser *p, va_list args)
{
	char		chr;
	int			buf[BUF_SIZE];
	int			len;
	int			ret;
	int			i;

	ret = 0;
	len = 1;
	chr = va_arg(args, int);
	buf[0] = chr;
	i = len;
	if (!(p->f & LEFT_ALIGN) && !(p->f & ZERO_FILL))
		while (i++ < p->width)
		{
			ft_putchar(' ');
			ret++;
		}
	i = -1;
	while (++i < len)
	{
		ft_putchar(buf[len - i - 1]);
		ret++;
	}
	print_width(p, len, &ret, 1);
	return (ret);
}
