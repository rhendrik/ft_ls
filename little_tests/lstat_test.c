#include "../ft_ls.h"

int main(int ac, char **av)
{
	struct stat buf;
	int link;

	(void) ac;
	if (lstat(av[1], &buf) == 0)
		ft_putstr("lstat works\n");
	link = buf.st_nlink;
	ft_putnbr(link);
	return (0);
}
