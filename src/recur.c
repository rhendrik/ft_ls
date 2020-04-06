#include "../includes/ft_ls.h"

int recur(ff flags, char *d)
{
	DIR *dir;
	struct dirent *entry;
	char *path;

	path = (char *)malloc(1024 * sizeof(char));
	path = ft_strcpy(path, d);
	dir = opendir(d);
	while((entry = readdir(dir)) != NULL)
	{
		if(entry->d_type == DT_DIR)
		{
		if(flags.a == 0)
		{
			if(entry->d_name[0] == '.')
				continue;
		}
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, entry->d_name);
		ft_putstr(path);
		ft_putchar('\n');
		}
		else
		{
			ft_putstr(entry->d_name);
			ft_putchar('\n');
		}
	}
	closedir(dir);
	return(0);
}
