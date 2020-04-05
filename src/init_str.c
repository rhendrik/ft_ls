#include "../includes/ft_ls.h"

ff init_str(ff flags)
{
       	flags.l = 0;
        flags.a = 0;
        flags.lr = 0;
        flags.ur = 0;
        flags.t = 0;
        flags.ll = 0;
	flags.er = 0;
	flags.dirs[1] = ft_strcpy(flags.dirs[1], ".");
	return(flags);
}
