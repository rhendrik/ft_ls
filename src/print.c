#include "../includes/ft_ls.h"

int print_tmp_rev(char **tmp, ff flags, char *dir)
{
	int i;
	int j;
	char lc;
	char uc;

	i = 0;
	j = 0;
	lc = 'z';
	uc = 'Z';
	while(lc >= 'a' && uc >= 'A')
	{
		while(ft_strcmp(tmp[i], "end\n") != 0)
		{
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
			if(tmp[i][j] == '.')
			{
				j++;
				continue;
			}
			i++;
		}
		i = 0;
		j = 0;
		while(ft_strcmp(tmp[i], "end\n") != 0)
		{
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
			if(tmp[i][j] == '.')
			{
				j++;
				continue;
			}
			i++;
		}
		i = 0;
		j = 0;
		uc--;
		lc--;
	}
	i = 0;
	j = 0;
	while(ft_strcmp(tmp[i], "end\n") != 0)
	{
		if(ft_strcmp(tmp[i], "..") == 0)
		{
			if(flags.l == 1)
			{
				print_l("..", dir);
				ft_putchar('\n');
			}
			else
				put_spc(tmp[i]);
		}
		i++;
	}
	i = 0;	
	while(ft_strcmp(tmp[i], "end\n") != 0)
	{
		if(ft_strcmp(tmp[i], ".") == 0)
		{
			if(flags.l == 1)
			{
				print_l(".", dir);
				ft_putchar('\n');
			}
			else
				put_spc(tmp[i]);
		}
		i++;
	}
	return (0);
}

char *set_permissionstr(char *tmp, int mode)
{
	if( mode & S_IRUSR )
		tmp[1] = 'r';	
	if( mode & S_IWUSR )
		tmp[2] = 'w';
	if( mode & S_IXUSR )
		tmp[3] = 'x';
	if( mode & S_IRGRP )
		tmp[4] = 'r';
	if( mode & S_IWGRP )
		tmp[5] = 'w';
	if( mode & S_IXGRP )
		tmp[6] = 'x';
	if( mode & S_IROTH )
		tmp[7] = 'r';
	if( mode & S_IWOTH )
		tmp[8] = 'w';
	if( mode & S_IXOTH )
		tmp[9] = 'x';
	return(tmp);
}

int print_l(char *name, char *dir)
{
	char *tmp;
	struct stat statbuff;
	char *time;
	char *abs;

	tmp = (char *)malloc((ft_strlen(name) + 1) * sizeof(char));
	abs = ft_strnew(ft_strlen(name) + ft_strlen(dir) + 2);
	abs = ft_strdup("./");
	abs = ft_strcat(abs, dir);
	abs = ft_strcat(abs, "/");
	abs =ft_strcat(abs, name);
	if(stat(abs, &statbuff) == -1)
	{
		perror("Stat error\n");
		return(0);
	}
	else
	{
		/* filetype */
		if(S_ISDIR(statbuff.st_mode) != 0)
			tmp = ft_strcpy(tmp, "d");
		if(S_ISLNK(statbuff.st_mode) != 0)
			tmp = ft_strcpy(tmp, "|");
		if(S_ISREG(statbuff.st_mode) != 0)
			tmp = ft_strcpy(tmp, "-");
		/* permissions */
		tmp = ft_strcat(tmp, "---------");
		tmp = set_permissionstr(tmp, statbuff.st_mode);
		tmp = ft_strcat(tmp, " ");

		/* links */
		tmp = ft_strcat(tmp, ft_itoa(statbuff.st_nlink));
		tmp = ft_strcat(tmp, " ");

		/* owner name */
		tmp = ft_strcat(tmp, uid_to_name(statbuff.st_uid));
		tmp = ft_strcat(tmp, " ");

		/* group name */
		tmp = ft_strcat(tmp, gid_to_name(statbuff.st_gid));
		tmp = ft_strcat(tmp, " ");

		/* bytesize */ 
		tmp = ft_strcat(tmp, ft_itoa(statbuff.st_size));
		tmp = ft_strcat(tmp, " ");

		/* last modified */
		time = ft_strnew(ft_strlen(ctime(&statbuff.st_mtime)));
		time = ctime(&statbuff.st_mtime);
		time[16] = '\0';
		tmp = ft_strcat(tmp, time);
		tmp = ft_strcat(tmp, " ");

		/* filename */
		tmp = ft_strcat(tmp, name);
	}

	/* print */
	ft_putstr(tmp);
	return(1);
}

char *uid_to_name(uid_t uid)
{
	struct passwd *pw_ptr;

	if( (pw_ptr = getpwuid(uid)) == NULL)
		return("Error");
	else
		return (pw_ptr->pw_name);
}

char *gid_to_name(gid_t gid)
{	
	struct group *grp_ptr;

	if( (grp_ptr = getgrgid(gid)) == NULL)
		return("Error");
	else
		return (grp_ptr->gr_name);

}
