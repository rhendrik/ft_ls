#include "../includes/ft_ls.h"

int acc_err(char *avi)
{
	ft_putstr("ft_ls: cannot access '");
	ft_putstr(avi);
	ft_putstr("' No such file or directory\n");
	return (0);
}
