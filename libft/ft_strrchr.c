/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:51:45 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/17 12:09:52 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = NULL;
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == c)
		{
			ptr = (char *)&s[i];
			break ;
		}
		i--;
	}
	return (ptr);
}
