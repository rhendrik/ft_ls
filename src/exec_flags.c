#include "../includes/ft_ls.h"

int exec_flags(ff flags, DIR *dir)
{
	//struct dirent *entry;
	if(ft_strcmp(flags.files[0], "end\n") == 0)
		dir = opendir(".");
	return (b_print(dir));

	/*if(flags.a)
	{
		if(ac == 2)
		{
			dir = opendir(".");
			while((entry = readdir(dir)) != NULL)
			{
				ft_putstr(entry->d_name);
				ft_putstr(" ");
			}
			ft_putendl("");
			return (0);
		}	
		else
		{
			while(av[i])
			{
				// print -a

				if(ft_strcmp(av[i], "-a") == 0)
				{
					i++;
					continue;
				}
				else if ((dir = opendir(av[i])) != NULL)
				{
					while((entry = readdir(dir)) != NULL)
					{
						ft_putstr(entry->d_name);
						ft_putstr(" ");
					}
					ft_putendl("");
				}
				else if(is_file(av[i]))
				{
					ft_putstr(av[i]);
					ft_putchar(' ');
				}
				i++;
			}
		}

	}
	ft_putchar('\n');*/
	return (0);
}
