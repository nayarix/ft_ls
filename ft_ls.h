#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include "libft.h"

typedef struct		s_opt
{
	int		l:1;
	int		a:1;
	int		r:1;
	int		t:1;
	int		u:1;
	int		i:1;
	int		o:1;
	int		g:1;
	int		m:1;
	int		p:1;
	int		n:1;
	int		one:1;
	int		cap_a:1;
	int		cap_r:1;
	int		cap_s:1;
	int		cap_g:1;
}			t_opt;

typedef struct	s_max
{
	int			total;
	int			count;
	int			link;
	int			size;
	int			own;
	int			grp;
	int			nown;
	int			ngrp;
	int			major;
	int			minor;
}				t_max;

typedef struct	s_file
{
	int			error;
	t_opt		*opts;
	char		*name;
	char		*path;
	struct stat	*stats;
	t_bt		*node;
	t_bt		*dirs;
	t_max		*c_mw;
	t_max		*p_mw;
}				t_file;

typedef struct	s_ls
{
	t_max		mw;
	t_opt		opts;
	t_file		*file;
	t_bt		*root;
	t_bt		*invtree;
}				t_ls;

void			print_enoent(void *item);
void			print_item(void *item);
void			print_lvl1(void *item);
void			print_lgformat(t_file *file);
void			freef(void **item);
void			add_opts(t_ls *ls, char *s);
int				ft_cmp_enoent(void *item1, void *item2);
int				ft_cmp(void* item1, void *item2);
void			init_mw(t_max *mw);
void			init_opts(t_ls *ls);
void			fill_mw(t_max *p_mw, t_file *file);
t_file			*init_file(char *name, char *path, t_opt *opts);
void			ft_ls(void *arg);
void			lsdir_r(t_file *file);
void			lsr(void *arg);
void			lsdir(t_file *file);
void			parse(int ac, char **av, t_ls *ls);

#endif
