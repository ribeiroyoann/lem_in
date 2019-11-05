/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:18:20 by yoribeir          #+#    #+#             */
/*   Updated: 2018/11/08 17:19:43 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned	int	i;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	i = nb;
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd(i % 10 + '0', fd);
	}
	else
		ft_putchar_fd(i + '0', fd);
}
