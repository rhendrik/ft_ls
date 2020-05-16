#include "../includes/ft_ls.h"

char *set_tmp(char *name)
{
	char *ret;

	ret = ft_strnew(ft_strlen(name) + 1);
	ret = ft_strcpy(ret, name);
	return (ret);
}

int print_tmp(char **tmp)
{
	int i;
	int j;
	char lc;
	char uc;

	i = 0;
	j = 0;
	lc = 'a'; /* lowercase checker */
	uc = 'A'; /* uppercase checker */
	/*******************************/
	/* Check for current directory */
	/*******************************/
	while((ft_strcmp(tmp[i], "end\n") != 0) && tmp[i] != NULL)
	{
		if(ft_strcmp(tmp[i], ".") == 0) 
			put_spc(tmp[i]);
		i++;
	}
	i = 0;
	/*****************************/
	/* heck for parent directory */
	/*****************************/
	while(ft_strcmp(tmp[i], "end\n") != 0)
	{
		if(ft_strcmp(tmp[i],  "..") == 0)
			put_spc(tmp[i]);
		i++;
	}
	i = 0;
	/****************************************/
	/* CHeck lowercase && uppercase letters */
	/****************************************/
	while(uc <= 'Z' && lc <= 'z')
	{
		while(ft_strcmp(tmp[i], "end\n") != 0)
		{
			if(tmp[i][j] == '.')
				j++;
			if(tmp[i][j] == uc)
			{
				put_spc(tmp[i]);
			}
			i++;
		}
		i = 0;
		j = 0;
		while(ft_strcmp(tmp[i], "end\n") != 0)
		{
			if(tmp[i][j] == '.')
				j++;
			if(tmp[i][j] == lc)
			{
				put_spc(tmp[i]);
			}
			i++;
		}
		j = 0;
		i = 0;
		uc++;
		lc++;

	}
	return (0);
}

int exec_flags(ff flags, DIR *dir, char *dname)
{
	char **tmp;
	int i;
	struct dirent *entry;
	int j;

	tmp = (char**)malloc(1024 * sizeof(char));
	i = 0;
	j = 0;
	/**********************************************/
	/*This is where it prints for individual files*/
	/**********************************************/
	if((dir = opendir(dname)) == NULL)
		if(is_file(dname) == 1)
		{
			ft_putendl(dname);
			return (0);
		}
	/***************************************************/
	/*This is where we set the tmp 2d array with dir's */
	/*contents                                         */
	/***************************************************/
	if(flags.a == 1)
	{
		while((entry = readdir(dir)) != NULL)
		{
			tmp[j] = set_tmp(entry->d_name);
			j++;
		}
		tmp[j] = set_tmp("end\n");
		j = 0;
	}
	else
	{
		while((entry = readdir(dir)) != NULL)
		{
			if(entry->d_name[0] != '.')
			{
				tmp[j] = set_tmp(entry->d_name);
				j++;
			}
			i++;
		}
		tmp[j] = set_tmp("end\n");
	}
	/*****************/
	/* '-l' printing */
	/*****************/
	if(flags.l == 1)
		print_tmp_l(tmp);
	else
		print_tmp(tmp);
	ft_putendl("");
	return (0);
}

int exec_flags_files(ff flags, DIR *dir)
{
	int i;

	i = 0;
	while(ft_strcmp(flags.files[i], "end\n") != 0)
	{
		exec_flags(flags, dir, flags.files[i]);
		i++;
	}
	return (0);
}
