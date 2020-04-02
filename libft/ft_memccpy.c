/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:21:15 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/09 13:22:40 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	lim;
	size_t			index;

	index = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	lim = (unsigned char)c;
	while (index < n)
	{
		s2[index] = s1[index];
		if (s1[index] == lim)
		{
			return (dest + index + 1);
			break ;
		}
		index++;
	}
	return (NULL);
}
