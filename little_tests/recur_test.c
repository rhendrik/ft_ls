#include "test.h"
#include "../ft_ls.h"

void listdir(const char *name)
{
	DIR *dir;
	struct dirent *entry;
	char *path;

	if(!(dir = opendir(name)))
		return ;
	while((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
			ft_putchar('\n');
		path = (char *)malloc(((ft_strlen(name) + ft_strlen(entry->d_name)) + 2) * sizeof(char));
		if (ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)	
			continue ;
		ft_putstr(entry->d_name);
		ft_putchar('\n');
		path = ft_strjoin(name, "/");
		path = ft_strjoin(path, entry->d_name);
		listdir(path);
		}
		else
		{
			ft_putstr(entry->d_name);
			ft_putchar('\n');
		}
	}
	closedir(dir);
}

int main(void)
{
	listdir("testrdir");
	return(0);
}
