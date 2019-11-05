/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:10:34 by yoribeir          #+#    #+#             */
/*   Updated: 2019/04/02 16:50:13 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_parser(t_parser *p)
{
	p->width = 0;
	p->precision = 0;
	p->f = 0;
	p->base = 0;
	p->slen = 0;
	p->s = NULL;
}

void	apply_spec_flags(t_parser *p, char c)
{
	if (c != 'i' && c != 'd')
		p->f &= ~(PLUS | SPACE);
	if (p->f & PRECISION)
		p->f &= ~ZERO_FILL;
	if (p->base == 10)
		p->f &= ~PREFIX;
	if (p->f & ZEROVALUE)
		p->f &= ~PREFIX;
	if (c == 'x' || c == 'X' || c == 'u' || c == 'o' || c == 'b')
		p->f |= UNSIGNED;
	if (p->f & PRECISION && !p->precision)
		p->f |= ZEROPREC;
}

int		parser(t_parser *p, char **format)
{
	init_parser(p);
	parse_flags(p, format);
	parse_width(p, format);
	parse_precision(p, format);
	parse_length(p, format);
	p->format = **format;
	if (p->format == 'O' || p->format == 'U' || p->format == 'D'
		|| p->format == 'F')
	{
		if (p->format == 'U')
			p->f |= UMAJ;
		p->format += 32;
	}
	p->base = get_base(p, p->format);
	p->prefix = get_prefix(p, p->format);
	apply_spec_flags(p, p->format);
	if (p->f & FLAGS_L && (p->format == 'c' || p->format == 's'))
		p->format -= 32;
	return (0);
}

int		process(va_list args, const char *format)
{
	int			ret;
	t_parser	*p;
	t_jumptable	jt;

	p = malloc(sizeof(t_parser));
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			parser(p, (char **)&format);
			jt = init_table(p->format);
			if (jt)
				ret += jt(p, args);
			init_parser(p);
		}
		else
		{
			ft_putchar(*format);
			ret++;
		}
		format++;
	}
	free(p);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = process(args, format);
	va_end(args);
	return (ret);
}
