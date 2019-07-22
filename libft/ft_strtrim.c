/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:17:45 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/14 10:39:58 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t max;
	size_t min;
	size_t i;

	if (s == NULL)
		return (NULL);
	min = 0;
	while (s[min] && (s[min] == ' ' || s[min] == '\t' || s[min] == '\n'))
		min++;
	max = ft_strlen((char *)s);
	while (min < max &&
			(s[max - 1] == ' ' || s[max - 1] == '\t' || s[max - 1] == '\n'))
		max--;
	if (min == max)
		return (ft_strnew(1));
	i = max - min;
	return (ft_strsub(s, min, i));
}
