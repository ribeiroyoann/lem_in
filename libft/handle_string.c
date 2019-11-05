/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:29:36 by yoann             #+#    #+#             */
/*   Updated: 2019/03/20 14:28:54 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_strwidth(t_parser *p, int len, int *ret)
{
	if (!(p->f & LEFT_ALIGN))
		while (len < p->width)
		{
			ft_putchar(' ');
			(*ret)++;
			len++;
		}
}

int			handle_string(t_parser *p, va_list args)
{
	int		len;
	int		i;

	i = 0;
	p->s = va_arg(args, char *);
	if (!p->s)
		p->s = "(null)";
	len = ft_strlen(p->s);
	if (p->f & PRECISION)
		len = (len < p->precision ? len : p->precision);
	print_strwidth(p, len, &i);
	while ((*p->s && (!(p->f & PRECISION) || p->precision--)))
	{
		ft_putchar(*p->s);
		p->s++;
		i++;
	}
	print_width(p, len, &i, 1);
	return (i);
}
