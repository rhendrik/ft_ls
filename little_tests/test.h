#ifndef TEST_H
#define TEST_H

#include "../ft_ls.h"

typedef struct node{
	char *filenames[255];
	struct dirent *dp;
	struct tree *next;
} tree;

#endif
