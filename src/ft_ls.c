#include "../includes/ft_ls.h"

ff set_end(ff flags, int pos)
{
	flags.files[pos] = ft_strnew(5);
	flags.files[pos] = ft_strcpy(flags.files[pos], "end\n");
	return (flags);
}

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
	flags = init_str(flags);
	flags = flag_init(flags, av, ac);
	if(flags.er == 1)
	{
		closedir(dir);
		return(0);
	}
	else
	{
		if(ft_strcmp(flags.files[0], "end\n") == 0)
			exec_flags(flags, dir, ".");
		else
			exec_flags_files(flags, dir);
	}
	closedir(dir);
	return(0);
}
