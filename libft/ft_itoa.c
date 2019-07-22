/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:06:38 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/22 08:48:41 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_strlen(int n)
{
	size_t i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	size_t	strlen;
	char	*s;
	int		n_cpy;

	n_cpy = n;
	strlen = l_strlen(n);
	if (n == INTMIN)
	{
		return (ft_strdup(MINSTR));
	}
	if (n == INTMAX)
		return (MAXSTR);
	if (n < 0)
	{
		strlen++;
		n_cpy = -n;
	}
	if (!(s = ft_strnew(strlen + 1)))
		return (NULL);
	s[strlen--] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		s[strlen--] = n_cpy % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
