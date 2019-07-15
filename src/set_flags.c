/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:39:59 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/15 14:40:51 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void set_bools(char *av, fs flags)
{
	if (ft_strcmp(R, av) == 0)
		flags.r = 1;
	if (ft_strcmp(L, av) == 0)
		flags.l = 1;
	if (ft_strcmp(A, av) == 0)
		flags.a = 1;
	if (ft_strcmp(LR, av) == 0)
		flags.lr = 1;
	if (ft_strcmp(T, av) == 0)
		flags.t = 1;
}
