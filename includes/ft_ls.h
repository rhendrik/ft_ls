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
	int er;
	char **files;
	int filenum;
} ff;

int b_print(DIR *dir);
ff flag_init(ff flags, char **av, int ac);
ff init_str(ff flags);
int acc_err(char *avi);
int recur(ff flags, char *dir);
int recur(ff flags, char *d);
int exec_flags(ff flags, DIR *dir, char *dname);
int is_file(char *path);
void put_spc(char *str);
int exec_flags_files(ff flags, DIR *dir);
ff set_end(ff flags, int pos);
int print_tmp(char **tmp);
int print_tmp_l(char**tmp);
int print_l(char *name);
char *set_permissionstr(char *tmp, int mode);
char *uid_to_name(uid_t uid);
int count_res(char **tmp);
char *gid_to_name(gid_t gid);

# endif
