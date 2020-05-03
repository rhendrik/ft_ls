#include "../includes/ft_ls.h"

ff flag_init(ff flags, char **av)
{
	int i;
	DIR *dummy;
	char *tmp;
	int j;

	i = 1;
	j = 1;
	flags.dirs[0] = ft_strnew(3);
	flags.dirs[0] = ft_strcpy(flags.dirs[0], ".");
	while(av[i])
	{
		if(ft_strcmp("-a", av[i]) ==0)
		{
			flags.a = 1;
			i++;
			continue;
		}
		tmp = ft_strnew(3 + ft_strlen(av[i]));
		tmp = ft_strjoin("./", av[i]);
		if ((dummy = opendir(tmp)) != NULL)
		{
			if(dummy->d_type == DT_REG)
			{
				flags.dirs[j] = ft_strnew(ft_strlen(avi) + 1);
				flags.dirs[j] = ft_strcpy(flags.dirs[j], av[i]);
				j++;
				i++;
				continue;
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

	if(flags.dirs[0] == NULL)
	{
		flags.dirs[0] = (char *)malloc(3 * sizeof(char));
		flags.dirs[0] = ft_strcpy(flags.dirs[0], ".");
	}
	return (flags);
}
