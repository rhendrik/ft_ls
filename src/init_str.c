#include "../includes/ft_ls.h"

ff init_str(ff flags)
{
	flags.files = (char **)malloc(1024 * sizeof(char **));
	flags.l = 0;
	flags.a = 0;
	flags.lr = 0;
	flags.ur = 0;
	flags.t = 0;
	flags.ll = 0;
	flags.er = 0;
	flags = set_end(flags, 0);
	flags.filenum = 0;
	return(flags);
}

int print_tmp_time(char **tmp, ff flags, char *dir)
{
	time_t *tab;
	int len;

	len = count_res(tmp);
	tab = (time_t *)malloc((len + 1) * sizeof(time_t));
	init_tab(tmp, dir, len);
	(void)flags;
	(void)tab;
	return (0);
}

time_t *init_tab(char **tmp, char *dir, int len)
{
	struct stat statbuff;
	char *abs;
	time_t *ret;
	int i;

	i = 0;
	ret = (time_t *)malloc((len) * sizeof(time_t));
	while(ft_strcmp(tmp[i], "end\n") != 0)
	{
		if(ft_strcmp(dir, ".") == 0)
		{
			abs = set_abs(tmp[i], "");
		}
		else
			abs = set_abs(tmp[i], dir);	
		if(stat(abs, &statbuff) == -1)
		{
			perror("Stat Error\n");
			return (NULL);
		}
		else
		{
			ret[i] = statbuff.st_mtime;
		}
		i++;
	}
	(void) statbuff;
	(void)len;
	return(NULL);
}

char *set_abs(char *name, char *dir)
{
	char *abs;

	abs = ft_strnew(ft_strlen(name) + ft_strlen(dir) + 2);
	abs = ft_strdup("./");
	abs = ft_strcat(abs, dir);
	abs = ft_strcat(abs, "/");
	abs =ft_strcat(abs, name);
	return (abs);
}
