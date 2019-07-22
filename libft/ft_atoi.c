/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 08:47:29 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/09 09:17:14 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negbool(const char **s)
{
	int isneg;

	isneg = 0;
	while (**s == ' ' || **s == '\t' || **s == '\f' || **s == '\v'
			|| **s == '\n' || **s == '\r')
		++*s;
	if (**s == '-')
	{
		isneg = 1;
		++*s;
	}
	else if (**s == '+')
		++*s;
	return (isneg);
}

int			ft_atoi(const char *str)
{
	int			ret;
	int			isneg;
	const char	*s;

	s = str;
	isneg = negbool(&s);
	ret = 0;
	if (ft_strcmp(str, MINSTR) == 0)
		return (INTMIN);
	if (ft_strcmp(str, MAXSTR) == 0)
		return (INTMAX);
	while (ft_isdigit(*s))
	{
		ret *= 10;
		ret += *s - '0';
		if (ret < 0 && isneg == 1)
			return (0);
		if (ret < 0)
			return (-1);
		++s;
	}
	if (isneg)
		ret = ret * -1;
	return (ret);
}
