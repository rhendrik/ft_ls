/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:26:54 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/18 17:06:54 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	if (src[0] == '\0')
	{
		while (dst[i])
		{
			dst[i++] = '\0';
		}
		return (dst);
	}
	while (len > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	if (!src[i] && len > 0)
	{
		while (len-- > 0)
		{
			dst[i++] = '\0';
		}
	}
	return (dst);
}
