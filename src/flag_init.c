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
		}
		else if(flag[i] == 'l')
		{
			flags.l = 1;
		}
		else if(flag[i] == 'r')
		{
			flags.lr = 1;
		}
		else if(flag[i] == 'R')
		{
			flags.ur = 1;
		}
		else if(flag[i] == 't')
		{
			flags.t = 1;
		}
		else if(flag[i] == '1')
		{
			flags.one = 1;
		}
		else
		{
			flags.er = 1;
			return(flags);
		}
		i++;
	}
	return(flags);
}

ff set_file(ff flags, int pos, char *av)
{
	flags.files[pos] = ft_strnew(ft_strlen(av) + 1);
	flags.files[pos] = ft_strcpy(flags.files[pos], av);
	return (flags);

}

ff flag_init(ff flags, char **av, int ac)
{
	int i;
	int j;
	DIR *dummy;


	j = 0;
	i = 1;
	if(ac == 1)
	{
		flags.files[0] = ft_strnew(ft_strlen("end\n"));
		flags.files[0] = ft_strcpy(flags.files[0],"end\n");
		return (flags);
	}
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
	flags.files[j] = ft_strnew(ft_strlen("end\n") +1);
	flags.files[j] = ft_strcpy(flags.files[j], "end\n");
	return (flags);
}
