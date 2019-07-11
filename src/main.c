#include "../ft_ls.h"

int ass_flags(char **flags, char **av, int ac)
{
	size_t counter;

	counter = ac - 1;
	if (ac == 1)
		return (-1);
	while (counter > 1)
	{
		flags[counter] = ft_strdup(av[counter]);
		counter--;
	}
	return (0);
}

int main(int ac, char **av)
{
        /*includes*/

        /*definitions:*/
	char **flags;
        extern int errno ;
	
	flags = NULL;
        errno = 0;
	if (ass_flags(flags, av, ac) < 0)
		flags[0] = ft_strdup(NONE);
        /*assign struct based on av*/

        /*open directory*/
	return (0);
}

