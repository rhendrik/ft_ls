#include "../ft_ls.h"

void init_flags(char **flagstr)
{
	flagstr[0] = ft_strdup(R);
	flagstr[1] = ft_strdup(L);
	flagstr[2] = ft_strdup(A);
	flagstr[3] = ft_strdup(LR);
	flagstr[4] = ft_strdup(T);
}

int ass_struct(int ac, char **av, fs flags)
{
	(void)ac;
	(void)av;
	init_flags(flags.flagstr);
	/*  initialise flagstr with macros. helper function?
	 ** declare iterators i & j; i = 1, j = 0;
	 ** while(i < ac)
	 **	{
	 **		while (j < 6)
	 **		 	if flag_bool(av[i], fs flags) == 1
	 **			i++ j = 0;
	 **			else
	 **			j++
	 **	}
	 ** return (0);*/
	return (0);
}

int check_flags(int ac, char **av, fs flags)
{
	(void)av;
	(void)flags;
	int i;
	//int j;

	i = 1;
	//j = 0;
	while(i < ac)
	{
			/*  if av[i] != any flags && does not open a directory
			 ** return -1
			 ** else if it does i++*/
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	fs flags = { .r = 0, .flagstr = NULL};
	ass_struct(ac, av, flags);
	return (0);
}
