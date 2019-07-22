/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:53:53 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/06 15:04:14 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*nstr;

	if (!(nstr = (char *)malloc(size + 1 * sizeof(char))))
		return (NULL);
	i = 0;
	while (size > 0)
	{
		nstr[i++] = '\0';
		size--;
	}
	nstr[i] = '\0';
	if (!nstr)
		return (NULL);
	return (nstr);
}
