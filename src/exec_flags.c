#include "../includes/ft_ls.h"

int exec_flags(ff flags)
{
	(void) flags;
	if(flags.a)
	{
		ft_putstr(flags.dirs[0]);
		ft_putchar('\n');
	//	print_a(flags);
	}
	return (0);
}
