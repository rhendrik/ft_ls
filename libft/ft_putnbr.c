/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:55:38 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/18 08:45:08 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	minmax(int n)
{
	if (n == INTMIN)
	{
		ft_putstr(MINSTR);
		return (1);
	}
	if (n == INTMAX)
	{
		ft_putstr(MAXSTR);
		return (1);
	}
	return (0);
}

void		ft_putnbr(int n)
{
	if (minmax(n) == 1)
		return ;
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
	return ;
}
