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
#include <pwd.h>
#include <grp.h>
#include "libft/libft.h"

typedef struct dirent dirent;
typedef struct S_list S_list;
typedef struct args_node args_node;
typedef struct options options;
typedef struct longest longest;

struct S_list
{
	size_t		length;
	args_node	*head;
	args_node	*tail;
};
struct args_node
{
	char			*content;
	char 			*path;
	struct stat 	stats;
	char 			perm[11];
	size_t 			hardlinks; //physical link
	char			*uid;
	unsigned int	uidd;// dans le cas ou get_pwuid marche pas on affiche uid cash
	char 			*gid;
	unsigned int	gidd;
	long			size;
	long 			mtime;
	char 			*mtimefull;
	long			time;
	long 			nb_of_blocks;
	char 			*symlink;
	long 			major;
	long 			minor;
	args_node 		*next;
};
struct longest
{
	size_t	hardlinks;
	size_t	uid;
	size_t	gid;
	long 	size;
  	size_t  majmin;
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
S_list 		*append_to_list(S_list *list, char *content, char *path);
void 		sort_list(S_list **list);
void		print_list(S_list 	*list, options *opts, char *dir_name);
options		*check_for_illegal_opt(int ac, char **av);
void		ls_controller(char **av, options *opts);
void		print_does_not_exist_list(S_list *no_list);
void		print_with_opts(S_list *list, options *opts);
void		ls_recursive(S_list *dir_list, options *opts);
void		main_ls(char *dir_name, options *opts);
//void		sort_list_t(S_list **list);
void		sort_list_r(S_list **list);
int			check_if_only_opts(char **av);
void		merge_sort(args_node **head, options *opts);
args_node	*sorted_merge_t(args_node *a, args_node *b);
args_node	*sorted_merge_r(args_node *a, args_node *b);
void		option_l(S_list *list, options *opts, char *dir_name);
longest		*new_longest(void);
void		print_list_l(S_list *list, longest *longest);
void		merge_sort_t(args_node **head);
void		split_list(args_node *elem, args_node **front, args_node **back);
int			rev_list(args_node **head);
void 		print_blocks_if_dir_full(S_list *list, options *opts, char *dir_name);
char		*check_path(char *dir_name, char *name);
void		free_list(S_list *list);
int		 	check_for_opt_a(options *opts);
int 		check_if_curr_or_prev_dir(char *name);
longest 	get_longest(S_list *list);
void    	option_l_printing(S_list *list, longest longest);
void    	option_l_printing_controller(args_node *elem, longest longest);
void    	print_hardlinks(struct stat stats, size_t longest_hardlink);
void    	print_uid(struct stat stats, size_t longest_uid);
void    	print_gid(struct stat stats, size_t longest_gid);
void    	print_size(struct stat stats, size_t longest_size);
void 		print_majmin(struct stat stats);
int     	is_elem_special(struct stat stats);
int 		is_elem_symlink(struct stat stats);
int 		look_for_special_elem(S_list *list);
void		print_correct_date(args_node *elem);
void 		print_name(args_node *elem);
void		print_symlink(args_node *elem);
int			check_dir_for_l(char *dir_name);
void		print_usage(char c);
void		print_errors(char *name);
void		sort_list_t(args_node **head, char *dir_name);
/*void    get_longest(args_node *elem, longest *longest);*/
#endif
