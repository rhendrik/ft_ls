#include "../includes/ft_ls.h"

ff flag_init(ff flags, char **av)
{
	int i;
	int j;
	int k;
	DIR *dummy;

	i = 1;
	j = 0;
	k = 0;
	while(av[i])
	{
		if ((dummy = opendir(av[i])) != NULL)
		{
			flags.dirs[k] = ft_strnew(ft_strlen(av[i]) + 1);
			flags.dirs[k] = ft_strcpy(flags.dirs[k], av[i]);
			k++;
		}
		else if(av[i][0] == '-')
		{
			j = 0;
			while(av[i][j])
			{
				if(av[i][j] == 't')
				{
					flags.t = 1;
					j++;
				}
				else if(av[i][j] == 'r')
				{
					flags.lr = 1;
					j++;
				}
				else if(av[i][j] == 'R')
				{
					flags.ur = 1;
					j++;
				}
				else if(av[i][j] == 'l')
				{
					flags.l = 1;
					j++;
				}
				else if(av[i][j] == 'a')
				{
					flags.a = 1;
					j++;
				}
				else
				{
					flags.er = 1;
					return(flags);
				}
			}

		}
		flags.er = 1;
		return(flags);
	}

	return (flags);
}
