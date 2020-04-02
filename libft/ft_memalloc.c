/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:56:53 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/12 09:01:28 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*array;
	int		i;

	array = (char *)malloc(size * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (size > 0)
	{
		array[i++] = 0;
		size--;
	}
	return ((void *)array);
}
