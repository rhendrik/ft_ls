#include "../includes/ft_ls.h"

int print_time(time_t *tab, char **tmp, ff flags, char *dir)
{
	int i;
	int j;
	struct stat statbuff;
	char *abs;
	int len;

	i = 0;
	j = 0;
	len = count_res(tmp);
	while(i < len)
	{
		j = 0;
		abs = set_abs(tmp[i], dir);
		while(ft_strcmp(tmp[j], "end\n") != 0)
		{
			if(stat(abs, &statbuff) == -1)
			{
				perror("Stat Error\n");
				return (-1);
			}
			else
			{
				if(statbuff.st_mtime == tab[j])
				{
					if(flags.l == 1)
					{
						print_l(tmp[j], dir);
						ft_putchar('\n');
					}
					else
						put_spc(tmp[j]);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

