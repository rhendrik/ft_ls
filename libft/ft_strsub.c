/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:50:46 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/06 14:29:53 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(ret = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len > 0)
	{
		ret[i++] = s[start++];
		len--;
	}
	ret[i] = '\0';
	return (ret);
}
