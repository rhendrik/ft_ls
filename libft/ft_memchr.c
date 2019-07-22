/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:24:08 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/09 09:18:00 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*plc;

	i = 0;
	plc = (unsigned char *)s;
	while (n > 0)
	{
		if (plc[i] == (unsigned char)c)
		{
			return (&plc[i]);
		}
		else
		{
			i++;
			n--;
		}
	}
	return (NULL);
}
