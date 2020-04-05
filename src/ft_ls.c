#include "../includes/ft_ls.h"

int main(int ac, char **av)
{
	/* Delete this*/
	(void)av;

	DIR *dir;
	ff flags;


	flags = init_str(flags);
	dir = opendir("/");
	if(ac == 1)
	{
		if (b_print(dir) == 0)
			return (0);
	}
	else{
		flags = flag_init(flags, av);
		if(flags.er == 1)
		{
			return(0);
		}
		else
		{
			ft_putchar('\n');
			ft_putnbr(flags.a);
			ft_putchar('\n');
			ft_putnbr(flags.l);
			ft_putchar('\n');
			ft_putnbr(flags.lr);
			ft_putchar('\n');
			ft_putnbr(flags.ur);
			ft_putchar('\n');
			ft_putnbr(flags.t);
			ft_putchar('\n');
			ft_putstr(flags.dirs[0]);
		}
	}
	return(0);
}
