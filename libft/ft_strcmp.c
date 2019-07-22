/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:21:34 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/17 11:59:48 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

unsigned int	smin(const char s1, const char s2)
{
	unsigned int s1i;
	unsigned int s2i;

	s1i = s1;
	s2i = s2;
	return (s1i - s2i);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] != s2[i])
		{
			return (smin(s1[i], s2[i]));
		}
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (smin(s1[i], s2[i]));
		}
	}
	return (smin(s1[i], s2[i]));
}
