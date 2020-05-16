#include "../includes/ft_ls.h"

ff init_str(ff flags)
{
	flags.files = (char **)malloc(1024 * sizeof(char **));
       	flags.l = 0;
        flags.a = 0;
        flags.lr = 0;
        flags.ur = 0;
        flags.t = 0;
        flags.ll = 0;
	flags.er = 0;
	flags = set_end(flags, 0);
	flags.filenum = 0;
	return(flags);
}
