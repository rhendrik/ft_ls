#include "../includes/ft_ls.h"

char *set_end(char *str)
{
	str = ft_strcpy(str, "end\n");
	return (str);
}

void put_spc(char *str)
{
	ft_putstr(str);
	ft_putstr("  ");
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
		free(flags.files);
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
