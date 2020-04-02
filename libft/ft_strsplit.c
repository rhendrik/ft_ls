/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:38:34 by rhendrik          #+#    #+#             */
/*   Updated: 2019/06/17 09:54:54 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int		get_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ret;

	if (!s || !(ret = (char **)malloc(sizeof(*ret) *
		(ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(ret[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			ret[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			ret[i][k++] = s[j++];
		ret[i][k] = '\0';
	}
	ret[i] = 0;
	return (ret);
}
