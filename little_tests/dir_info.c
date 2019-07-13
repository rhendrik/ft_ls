#include "../ft_ls.h"

int main(int ac, char **av)
{
	(void)ac;
	DIR *current;
	struct dirent *sd;

	current = opendir(av[1]);
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
	closedir(current);
	return (0);
}
