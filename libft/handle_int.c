/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:36:58 by yoann             #+#    #+#             */
/*   Updated: 2019/04/11 17:23:07 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_int_length(t_parser *p, va_list args)
{
	intmax_t	nbr;

	nbr = va_arg(args, intmax_t);
	if (p->f & NONE)
		return ((int)nbr);
	else if (p->f & FLAGS_HH)
		return ((char)nbr);
	else if (p->f & FLAGS_LL)
		return ((long long)nbr);
	else if (p->f & FLAGS_H)
		return ((short)nbr);
	else if (p->f & FLAGS_L)
		return ((long)nbr);
	else if (p->f & FLAGS_J)
		return (nbr);
	else if (p->f & FLAGS_Z)
		return ((size_t)nbr);
	return (0);
}

void		handle_prec(t_parser *p, char *buf, int *len)
{
	while (*len < p->precision && *len < BUF_SIZE)
		buf[(*len)++] = '0';
	if (!(p->f & LEFT_ALIGN))
	{
		if (p->width && (p->f & ZERO_FILL) && (p->f & NEG
			|| (p->f & (PLUS | SPACE))))
			p->width--;
		while ((*len + (int)ft_strlen(p->prefix) < p->width)
			&& (*len < BUF_SIZE) && (p->f & ZERO_FILL))
			buf[(*len)++] = '0';
	}
}

void		append_prefix(t_parser *p, char *buf, int *len)
{
	int i;

	i = 0;
	if (p->f & PREFIX && !(p->f & ZEROVALUE))
		while (p->prefix[i])
		{
			buf[*len] = p->prefix[i];
			(*len)++;
			i++;
		}
	if (p->f & NEG)
		buf[(*len)++] = '-';
	else if (p->f & PLUS)
		buf[(*len)++] = '+';
	else if (p->f & SPACE)
		buf[(*len)++] = ' ';
}

void		print_width(t_parser *p, int len, int *ret, int flag)
{
	int		i;

	i = len;
	if (!(p->f & LEFT_ALIGN) && !(p->f & ZERO_FILL) && !flag)
		while (i++ < p->width)
		{
			ft_putchar(' ');
			(*ret)++;
		}
	if (p->f & LEFT_ALIGN && flag)
		while (i++ < p->width)
		{
			ft_putchar(' ');
			(*ret)++;
		}
}

int			handle_int(t_parser *p, va_list args)
{
	intmax_t	nbr;
	char		buf[BUF_SIZE];
	int			len;
	int			ret;

	ret = 0;
	len = -1;
	nbr = get_int_length(p, args);
	if (nbr < 0)
		p->f |= NEG;
	p->s = itoa_base_long(p, nbr, p->base, "0123456789abcdef");
	if (!p->s)
		return (-1);
	itoa_handlezero(p, nbr);
	while (p->s[++len])
		buf[len] = p->s[len];
	handle_prec(p, buf, &len);
	append_prefix(p, buf, &len);
	print_width(p, len, &ret, 0);
	print_buffer(buf, len, &ret);
	print_width(p, len, &ret, 1);
	if (p->s && (!(p->f & ZEROPREC) || nbr != 0))
		free(p->s);
	return (ret);
}
