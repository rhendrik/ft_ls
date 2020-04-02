/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:38:20 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/16 11:03:07 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	while (s1[i] != '\0' || s2[i] != '\0' || n > 0)
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
		}
		else if (s1[i] != s2[i])
		{
			return (smin(s1[i], s2[i]));
		}
		if (s1[i] == '\0' || s2[i] == '\0' || n == 0)
		{
			return (smin(s1[i], s2[i]));
		}
	}
	return (smin(s1[i], s2[i]));
}
