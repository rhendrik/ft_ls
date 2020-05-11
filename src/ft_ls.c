#include "../includes/ft_ls.h"

void put_spc(char *str)
{
	ft_putstr(str);
	ft_putchar(' ');
}

int main(int ac, char **av)
{
	DIR *dir;
	ff flags;



	dir = opendir("/");
	if(ac == 1)
	{
		if (b_print(dir) == 0)
		{
			closedir(dir);
			return (0);
		}
	}
	else
	{
		flags = init_str(flags);
		flags = flag_init(flags, av);
		if(flags.er == 1)
		{
			closedir(dir);
			return(0);
		}
		else
		{
			exec_flags(flags, dir);
		}
	}
	closedir(dir);
	return(0);
}
