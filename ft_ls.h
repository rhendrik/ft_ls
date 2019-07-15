#ifndef FT_LS_H
#define FT_LS_H
#define CURR_DIR "."
#define R "-R"
#define L "-l"
#define A "-a"
#define LR "-r"
#define T "-t"
#define NONE "ls"

#include "libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <sys/xattr.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct opts{
	int r;
	int l;
	int a;
	int lr;
	int t;
	int ls;
	/*fp*/
	char **flagstr;
} fs;

typedef struct sfile{
	char *mod;
	int links;
	char *uid;
	char *gid;
	int bytes;
	char *modtime;
	char* f_name;

} t_file;

void set_bools(char *av, fs flags);
int flagcmp(char *av);
int dircmp(char *av);
int check_flags(char **av, int ac, fs flags);
int just_ls(DIR *current);

#endif
