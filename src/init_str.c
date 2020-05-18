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
	int i;
	int len;

	i = 0;
	len = count_res(tmp);
	tab = init_tab(tmp, dir, len);
	print_time(tab, tmp, flags, dir);
	(void)i;
	(void)flags;
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
	ret = sort_tab(ret, len);
	return(ret);
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

time_t *sort_tab(time_t *tab, int len)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j =  + 1;
	tmp = 0;
	while(j < len)
	{
		if(tab[j] > tab[i])
		{
			tmp = tab[j];
			tab[j] = tab[i];
			tab[i] = tmp;
		}
		i++;
		j++;
	}
	i = 0;
	j =  + 1;
	tmp = 0;
	while(j < len)
	{
		if(tab[j] > tab[i])
		{
			tmp = tab[j];
			tab[j] = tab[i];
			tab[i] = tmp;
		}
		i++;
		j++;
	}
	return (tab);
}
