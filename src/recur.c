#include "../includes/ft_ls.h"

int pad(char *s, int num)
{
	int i;
	int range;

	i = 0;
	range = num - ft_strlen(s);
	ft_putstr(s);
	while (i < range)
	{
		ft_putchar(' ');
		i++;
	}
	return (0);
}

int recur(ff flags, char *d)
{
	DIR *dir;
	struct dirent *entry;
	char *path;
	int i;

	path = (char *)malloc(1024 * sizeof(char));
	path = ft_strcpy(path, d);
	dir = opendir(d);
	i = 0;
	while((entry = readdir(dir)) != NULL)
	{
		if(entry->d_type == DT_DIR)
		{
			if(flags.a == 0)
			{
				if(entry->d_name[0] == '.')
					continue;
			}
			if(entry->d_type == DT_DIR)
			{
				path = ft_strjoin(path, "/");
				path = ft_strjoin(path, entry->d_name);
				ft_putstr(ft_strjoin(path, ":"));
				ft_putstr("\n\n");
				recur(flags, path);
			}
		}
		else
		{
			if(entry->d_name[0] != '.')
			{
				i++;
				if(i % 13 != 0)
					pad(entry->d_name, 16);
				else
				{
					ft_putstr(entry->d_name);
					ft_putchar('\n');
				}
			}
		}
	}
	closedir(dir);
	return(0);
}
