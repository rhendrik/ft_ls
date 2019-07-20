/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:40:17 by rhendrik          #+#    #+#             */
/*   Updated: 2019/07/15 14:40:27 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int flagcmp(char *av)
{
	if (ft_strcmp(av, R) == 0 || ft_strcmp(av, L) == 0 || ft_strcmp(av, A) == 0 ||
		     	ft_strcmp(av, LR) == 0 || ft_strcmp(av, T) == 0)
		return (0);
	return (-1);
}

int dircmp(char *av)
{
	DIR *dir;
	dir = opendir(av);
	if (dir == NULL)
		return (-1);
	closedir(dir);
	return (0);
}

int check_flags(char **av, int ac, fs flags)
{
	int i;

	i = 1;
	while(i < ac)
	{
		if (flagcmp(av[i]) != 0 && dircmp(av[i]) != 0)
			return (-1);
		set_bools(av[i], flags);
		i++;
	}
	return (0);
}

int just_ls(DIR *current)
{
	struct dirent *sd;
	current = opendir(CURR_DIR);
	if (current == NULL)
	{
		ft_putstr("Error: Could not open directory\n");
		return (-1);
	}
	while ((sd = readdir(current)) != NULL)
	{
		if (sd->d_name[0] != '.')
		{
			ft_putstr(sd->d_name);
			ft_putchar('\n');
		}
	}
	closedir(current);
	return (0);
}

int main(int ac, char **av)
{
	int counter;
	DIR *current;
	fs flags;
	(void)counter;
	(void)av;

/*	counter = ac;*/
	current = NULL;
	flags.r = 0;
	if (ac == 1)
	{
		if (just_ls(current) == -1)
			return (-1);
		else
			return (0);
	}
	else
	{
		if(check_flags(av, ac, flags) == -1)
		{
			ft_putstr("Error: could not open directory ");
			ft_putstr(av[1]);
			ft_putchar('\n');
			return (-1);
		}
	}

	/*resolve_flags(fs flags, char **av)*/
	
	return (0);
}
