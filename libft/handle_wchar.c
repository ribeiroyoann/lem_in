/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:57:41 by yoann             #+#    #+#             */
/*   Updated: 2019/03/28 15:06:40 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

void	ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
}

int		*handle_nullstring(t_parser *p, int *str)
{
	p->f |= ZEROVALUE;
	if (!(str = malloc(sizeof(int) * 7)))
		return (0);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

int		wcharlen(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	else if (chr <= 0x7FF)
		return (2);
	else if (chr <= 0xFFFF)
		return (3);
	else if (chr <= 0x10FFFF)
		return (4);
	return (-1);
}

int		handle_wchar(t_parser *p, va_list args)
{
	wchar_t		chr;
	int			ret;
	int			len;
	int			i;

	ret = 0;
	chr = va_arg(args, wchar_t);
	len = wcharlen(chr);
	i = len;
	print_strwidth(p, len, &ret);
	ft_putwchar(chr);
	ret += wcharlen(chr);
	if (p->f & LEFT_ALIGN)
		while (i++ < p->width)
		{
			ft_putchar(' ');
			ret++;
		}
	return (ret);
}

int		handle_wstring(t_parser *p, va_list args)
{
	int		*str;
	int		*tmp;
	int		len;
	int		i;

	i = 0;
	str = va_arg(args, int*);
	if (!str)
		str = handle_nullstring(p, str);
	tmp = str;
	len = ft_wstrlen(str);
	if (p->f & PRECISION)
		len = (len < p->precision ? len : p->precision);
	print_strwidth(p, len, &i);
	while ((*str && (!(p->f & PRECISION) || p->precision--)))
	{
		ft_putwchar(*str);
		i += wcharlen(*str);
		str++;
	}
	print_width(p, len, &i, 1);
	if (p->f & ZEROVALUE)
		free(tmp);
	return (i);
}
