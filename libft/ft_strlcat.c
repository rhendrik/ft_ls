/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 07:52:25 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/19 08:10:03 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	while (i < size && *dest && *dest++)
		i++;
	len = size - i;
	if (!len)
		return (i + ft_strlen(src));
	while (*src)
	{
		if (len != 1)
		{
			*(dest++) = *src;
			len--;
		}
		i++;
		src++;
	}
	*dest = '\0';
	return (i);
}
