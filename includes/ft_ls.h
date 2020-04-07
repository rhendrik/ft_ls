# ifndef _FT_LS_H_
# define _FT_LS_H

#include "../libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <uuid/uuid.h>
#include <errno.h>
#include <time.h>

typedef struct flags {
	int l;
	int a;
	int lr;
	int ur;
	int t;
	int ll;
	char **dirs;
	int er;
} ff;

int b_print(DIR *dir);
ff flag_init(ff flags, char **av);
ff init_str(ff flags);
int acc_err(char *avi);
int recur(ff flags, char *dir);
int recur(ff flags, char *d);

# endif
