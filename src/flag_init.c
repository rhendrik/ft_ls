#include "../includes/ft_ls.h"

ff flag_init(ff flags, char **av)
{
	int i;
	int j;
	int k;
	DIR *dummy;

	i = 1;
	j = 1;
	k = 1;
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
			while(av[i][j])
			{
				if(av[i][j] == 't')
				{
					flags.t = 1;
					j++;
					continue;
				}
				else if(av[i][j] == 'r')
				{
					flags.lr = 1;
					j++;
					continue;
				}
				else if(av[i][j] == 'R')
				{
					flags.ur = 1;
					j++;
					continue;
				}
				else if(av[i][j] == 'l')
				{
					flags.l = 1;
					j++;
					continue;
				}
				else if(av[i][j] == 'a')
				{
					flags.a = 1;
					j++;
					continue;
				}

			}

		}
		else
		{
			flags.er = 1;
			acc_err(av[i]);
			return(flags);
		}
		i++;
	}

	return (flags);
}
