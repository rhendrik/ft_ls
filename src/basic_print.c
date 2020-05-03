#include "../includes/ft_ls.h"

int b_print(DIR *dir)
{
	struct dirent *entry;

	if ((dir = opendir(".")))
	{
		while((entry = readdir(dir)) != NULL)
		{
			if(entry->d_name[0] != '.')
			{
				ft_putstr(entry->d_name);
				ft_putstr(" ");
			}
		}
		ft_putendl("");
		closedir(dir);
		return (0);
	}
	closedir(dir);
	return (1);
}
