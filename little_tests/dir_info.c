#include "../ft_ls.h"
#include "test.h"

int main(int ac, char **av)
{
	(void)ac;
	DIR *current;
	struct dirent *sd;
	tree *apple;
	int i;

	current = opendir(av[1]);
	apple = (tree *)malloc(sizeof(tree));
	i = 0;
	while ((sd = readdir(current)) != NULL)
	{
		if(apple->filenames[i] == NULL)
			apple->filenames[i] = ft_strnew(ft_strlen(sd->d_name));
		apple->filenames[i] = ft_strdup(sd->d_name);
		i++;
	}
	closedir(current);
	i = 0;
	while (apple->filenames[i])
	{
		ft_putstr(apple->filenames[i]);
		ft_putstr("  ");
		i++;
	}
	ft_putchar('\n');
/*	current = opendir(av[1]);
	if (current == NULL)
	{
		ft_putstr("Error: could not open directory.");
		exit(1);
	}
	while ((sd = readdir(current)) != NULL)
	{
		ft_putstr(sd->d_name);
		ft_putchar('\n');
	}
	closedir(current);*/


	return (0);
}
