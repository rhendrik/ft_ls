#include "../includes/ft_ls.h"

char *set_end()
{
	char *ret;
	ret = ft_strnew(5);
	ret = ft_strcpy(ret, "end\n");
	return (ret);
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
	free(flags.files);
	closedir(dir);
	return(0);
}
