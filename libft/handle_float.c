/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:51:20 by yoann             #+#    #+#             */
/*   Updated: 2019/04/03 16:21:46 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int				calc_decimal(long double decimal, int precision, int pos)
{
	int	i;

	i = 0;
	while (precision-- > 0 && ++i)
	{
		if ((int)decimal == 9 || (int)decimal == -9)
			pos = i;
		decimal = decimal - (long long)decimal;
		decimal *= 10;
	}
	return (pos);
}

long double		round_nbr(long double nbr, int precision)
{
	long long	integer;
	long double	decimal;
	int			pos;

	if (precision == 0)
	{
		integer = nbr * 10;
		return (nbr + (integer % 10 >= 5));
	}
	decimal = (nbr - (long long)nbr) * 10;
	pos = -1;
	pos = calc_decimal(decimal, precision, pos);
	if (pos == -1)
		decimal = 0;
	else
		decimal = 0.1;
	if (nbr <= -0.0)
		decimal = -decimal;
	while (pos-- > 0)
		decimal /= 10;
	return (nbr + decimal);
}

int				ft_uputnbr(long long n)
{
	int count;

	count = 1;
	if (n < 0)
		n = -n;
	if (n >= 10)
		count += ft_uputnbr(n / 10);
	ft_putchar('0' + n % 10);
	return (count);
}

int				ft_print_float(t_parser *p, long double nbr)
{
	long long	n;
	int			ret;

	ret = 0;
	n = (long long)nbr;
	if (nbr < 0 && ++ret)
		ft_putchar('-');
	ret += ft_uputnbr(n);
	if (!p->precision)
		return (ret);
	ret += p->precision + 1;
	ft_putchar('.');
	nbr -= (long long)nbr;
	while (p->precision-- > 0)
	{
		nbr *= 10;
		n = (long long)nbr % 10;
		nbr -= (long long)nbr;
		ft_putchar('0' + ft_abs(n));
	}
	return (ret);
}

int				handle_float(t_parser *p, va_list args)
{
	long double	nbr;
	int			ret;

	if (p->f & FLAGS_L)
		nbr = va_arg(args, long double);
	else
		nbr = va_arg(args, double);
	if (!(p->f & PRECISION))
		p->precision = 6;
	nbr = round_nbr(nbr, p->precision);
	ret = ft_print_float(p, nbr);
	return (ret);
}
