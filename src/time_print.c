#include "../includes/ft_ls.h"

int print_time(time_t *tab, char **tmp, ff flags, char *dir)
{
	int i;
	int j;
	struct stat statbuff;
	char *abs;

	i = 0;
	j = 0;
	while(ft_strcmp(tmp[i], "end\n") != 0)
	{
		abs = set_abs(tmp[i], dir);
		while(ft_strcmp(tmp[j], "end\n"))
		{
			if(stat(abs, &statbuff) == -1)
			{
				perror("Stat Error\n");
				return (-1);
			}
		}
	}
	(void) tab;
	(void) flags;
	return (0);
}

