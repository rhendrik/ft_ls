#include "../includes/ft_ls.h"

int is_file(char *path)
{
	struct stat buffer;
	int exist;

	exist = stat(path, &buffer);
	if (exist == 0)
		return (1);
	return (0);
}

ff check_flags(ff flags, char *flag)
{
	int i = 1;
	while(flag[i])
	{
		if(flag[i] == 'a')
		{
			flags.a = 1;
			i++;
		}
		else if(flag[i] == 'l')
		{
			flags.l = 1;
			i++;
		}
		else if(flag[i] == 'r')
		{
			flags.lr = 1;
			i++;
		}
		else if(flag[i] == 'R')
		{
			flags.ur = 1;
			i++;
		}
		else if(flag[i] == 't')
		{
			flags.t = 1;
			i++;
		}
		else
			flags.er = 1;
		return(flags);
	}
	return(flags);
}

ff set_file(ff flags, int pos, char *av)
{
	flags.files[pos] = ft_strnew(ft_strlen(av) + 1);
	flags.files[pos] = ft_strcpy(flags.files[pos], av);
	return (flags);

}

ff flag_init(ff flags, char **av)
{
	int i;
	int j = 0;
	DIR *dummy;

	i = 1;
	while(av[i])
	{
		if(av[i][0] == '-')
		{
			flags = check_flags(flags, av[i]);
			if(flags.er == 1)
			{
				acc_err(av[i]);
				return(flags);
			}
			i++;
			continue;
		}
		else if (is_file(av[i]) == 1)
		{
			flags = set_file(flags, j, av[i]);
			j++;
		}
		else if((dummy = opendir(av[i]))== NULL)
		{
			flags.er = 1;
			acc_err(av[i]);
			return(flags);
		}
		i++;
	}
	flags = set_file(flags, j, "end\n");
	return (flags);
}
