#include "../includes/ft_ls.h"

char *set_tmp(char *name)
{
	char *ret;

	ret = ft_strnew(ft_strlen(name) + 1);
	ret = ft_strcpy(ret, name);
	return (ret);
}

int print_tmp(char **tmp, ff flags, char *dir)
{
	int i;
	int j;
	char lc;
	char uc;

	i = 0;
	j = 0;
	lc = 'a'; /* lowercase checker */
	uc = 'A'; /* uppercase checker */
	/* if -l print totak */
	if(flags.l == 1)
	{
		i = count_res(tmp);
		ft_putstr("total ");
		ft_putendl(ft_itoa(count_res(tmp)));
	}
	i = 0;
	/*******************************/
	/* Check for current directory */
	/*******************************/
	while(ft_strcmp(tmp[i], "end\n") != 0) 
	{
		if(ft_strcmp(tmp[i], ".") == 0) 
		{
			if(flags.l == 1)
			{
				print_l(tmp[i], dir);
				ft_putchar('\n');
			}
			else
			{
				put_spc(tmp[i]);
			}
		}
		i++;
	}
	i = 0;
	/*****************************/
	/* heck for parent directory */
	/*****************************/
	while(ft_strcmp(tmp[i], "end\n") != 0)
	{
		if(ft_strcmp(tmp[i],  "..") == 0)
		{
			if(flags.l == 1)
			{
				print_l(tmp[i], dir);
				ft_putchar('\n');
			}
			else
				put_spc(tmp[i]);
		}
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
				if(flags.l == 1)
				{
					print_l(tmp[i], dir);
					ft_putchar('\n');
				}
				else
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
				if(flags.l == 1)
				{
					print_l(tmp[i], dir);
					ft_putchar('\n');
				}
				else
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
			if(flags.l == 1)
			{
				print_l(dname, "");
			}
			else
				ft_putstr(dname);
			return (0);
		}
	/***************************************************/
	/*This is where we set the tmp 2d array with dir's */
	/*contents                                         */
	/***************************************************/
	while((entry = readdir(dir)) != NULL)
	{
		if(flags.a != 1)
		{
			if(entry->d_name[0] != '.')
			{
				tmp[j] = set_tmp(entry->d_name);
				j++;
			}
		}
		else
		{
			tmp[j] = set_tmp(entry->d_name);
			j++;
		}
		i++;
	}
	tmp[j] = set_tmp("end\n");
	if(flags.t == 1)
		print_tmp_time(tmp, flags, dname);
	else if(flags.lr == 0)
	{
		print_tmp(tmp, flags, dname);
		if(flags.l != 1)
			ft_putendl("");
	}
	else
	{
		print_tmp_rev(tmp, flags, dname);
		if(flags.l != 1)
			ft_putchar('\n');
	}
	return (0);
}

int exec_flags_files(ff flags, DIR *dir)
{
	int i;
	struct stat path_stat;

	i = 0;
	while(ft_strcmp(flags.files[i], "end\n") != 0)
	{
		stat(flags.files[i], &path_stat);
		if(S_ISDIR(path_stat.st_mode))
		{
			ft_putstr(flags.files[i]);
			ft_putendl(":");
		}
		exec_flags(flags, dir, flags.files[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int count_res(char **tmp)
{
	int i;

	i = 0;
	while(ft_strcmp(tmp[i], "end\n") != 0)
		i++;
	return (i);
}
