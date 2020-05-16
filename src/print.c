#include "../includes/ft_ls.h"

int print_tmp_l(char **tmp)
{
	int i;
	int j;
	char uc;
	char lc;
	(void)tmp;
	(void)i;
	(void)j;
	(void)uc;
	(void)lc;

	/* check for current directory */

	/* check for parent directory */

	/* check for upper & lowercase letters */
	print_l("src");
	return (0);
}

char *permissions(struct stat statbuff)
{
	char *ret;

	ret = ft_strnew(10);
	if(statbuff.S_IRUSR)
		ret[0] = 'r';
	else
		ret[0] ='-';
	if(statbuff.S_IWUSR)
		ret[1] = 'w';
	else 
		ret[1] = '-';
	if(statbuff.S_IXUSR)
		ret[2] = 'x';
	else
		ret[2] = '-';
	return (ret);
}

void print_l(char *name)
{
	char *tmp;
	struct stat statbuff;

	tmp = (char *)malloc((ft_strlen(name) + 1) * sizeof(char));
	if(stat(name, &statbuff) == 0)
	{
		/* filetype */
		if(S_ISDIR(statbuff.st_mode) != 0)
			tmp = ft_strcpy(tmp, "d");
		if(S_ISLNK(statbuff.st_mode) != 0)
			tmp = ft_strcpy(tmp, "|");
		if(S_ISREG(statbuff.st_mode) != 0)
			tmp = ft_strcpy(tmp, "-");

		/* permissions */
		tmp = ft_strcat(tmp, permissions(statbuff));	
		/* links */

		/* owner name */

		/* group name */

		/* bytesize */ 

		/* last modified */

		/* filename */
	}

	/* print */
	ft_putstr(tmp);
}
