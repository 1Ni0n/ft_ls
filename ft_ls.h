/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:58:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/04 15:47:28 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "libft/libft.h"

typedef struct dirent dirent;
typedef struct S_list S_list;
typedef struct args_node args_node;
typedef struct options options;

struct args_node
{
	char			*content;
	char 			*path;
	struct stat		sb;
	long			time;
	dirent			*f_flow;
	args_node 		*next;
	args_node		*prev;
};
struct S_list
{
	size_t		length;
	args_node	*head;
	args_node	*tail;
};
struct options
{
	int l;
	int a;
	int r;
	int R;
	int t;
	int one;
};

void		simplest_ls(void);
void		args_controller(int ac, char **av);
S_list		*new_s_list(void);
S_list 		*append_to_list(S_list *list, char *content, long mtime, char *path);
void 		sort_list(S_list **list);
void		print_list(S_list 	*list);
options		*check_for_illegal_opt(int ac, char **av);
void		ls_controller(char **av, options *opts);
void		print_does_not_exist_list(S_list *no_list);
void		print_with_opts(S_list *list, options *opts);
void		ls_recursive(S_list *dir_list, options *opts);
void		main_ls(char *dir_name, options *opts);
//void		prev_ptr(S_list **list, args_node *elem, args_node *next);
void		sort_list_t(S_list **list);
void		sort_list_r(S_list **list);
int			check_if_only_opts(char **av);

#endif
