/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 16:20:36 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/18 16:22:07 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *str1, const void *str2, size_t n)
{
	int			i;
	char		*temp;
	const char	*temp2;

	i = (int)n - 1;
	temp = (char*)str1;
	temp2 = (const char*)str2;
	while (i >= 0)
	{
		temp[i] = temp2[i];
		--i;
	}
	return (str1);
}
