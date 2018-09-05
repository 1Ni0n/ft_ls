/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:58:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 12:17:07 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "libft/libft.h"
# include "libft/colors.h"

# define DIR_COLOR 1
# define CHARAC_SPECIAL_COLOR 2
# define BLOCK_COLOR 3
# define FIFO_COLOR 4
# define LNK_COLOR 5
# define SOCKET_COLOR 6
# define EXEC_COLOR 7
# define ARGUMENT1 av[i][j] != 'l' && av[i][j] != 'a' && av[i][j] != 'r'
# define ARGUMENT2 av[i][j] != 'R' && av[i][j] != 't' && av[i][j] != '1'
# define ARGUMENT3 av[i][j] != 'A' && av[i][j] != 'i' && av[i][j] != 'F'
# define ARGUMENT4 av[i][j] != 's'

typedef struct dirent	t_dirent;

typedef struct			s_args_node
{
	char				*content;
	char				*path;
	struct stat			stats;
	long				mtime;
	struct s_args_node	*next;
}						t_args_node;

typedef struct			s_list
{
	size_t		length;
	t_args_node	*head;
	t_args_node	*tail;
}						t_list;

typedef struct			s_longest
{
	size_t	hardlinks;
	size_t	uid;
	size_t	gid;
	long	size;
	size_t	majmin;
}						t_longest;

typedef struct			s_flags
{
	int i;
	int aa;
	int ff;
	int s;
	int c;
	int l;
	int a;
	int r;
	int rr;
	int t;
	int one;
}						t_flags;

void					simplest_ls(void);
void					args_controller(char **av);
t_list					*new_s_list(void);
void					free_elem(t_list **list, t_args_node *elem);
void					append_to_list(t_list *list, char *content, char\
		*path);
void					sort_list(t_list **list);
void					print_list(t_list *list, t_flags opts, char *dir_name);
t_flags					*check_for_illegal_opts(char **av);
void					ls_controller(char **av, t_flags opts);
void					print_does_not_exist_list(t_list *no_list);
void					print_with_opts(t_list *list, t_flags opts);
void					ls_recursive(t_list *dir_list, t_flags opts);
void					main_ls(char *dir_name, t_flags opts);
void					sort_list_r(t_list **list);
int						check_if_only_opts(char **av);
void					merge_sort(t_args_node **head, t_flags opts);
t_args_node				*sorted_merge_t(t_args_node *a, t_args_node *b);
t_args_node				*sorted_merge_r(t_args_node *a, t_args_node *b);
void					option_l(t_list *list, t_flags opts, char *dir_name);
t_longest				*new_longest(void);
void					print_list_l(t_list *list, t_longest *longest);
void					merge_sort_t(t_args_node **head);
void					split_list(t_args_node *elem, t_args_node **front,\
		t_args_node **back);
int						rev_list(t_args_node **head);
void					print_blocks_if_dir_full(t_list *list, t_flags opts,\
		char *dir_name);
char					*check_path(char *dir_name, char *name);
void					free_list(t_list *list);
int						check_for_opt_a(t_flags opts);
int						check_if_curr_or_prev_dir(char *name);
t_longest				get_longest(t_list *list);
void					option_l_printing(t_list *list, t_longest longest,\
		t_flags opts);
void					option_l_printing_controller(t_args_node *elem,\
		t_longest longest, int special, t_flags opts);
void					print_hardlinks(struct stat stats, size_t\
		longest_hardlink);
void					print_uid(struct stat stats, size_t longest_uid);
void					print_gid(struct stat stats, size_t longest_gid);
void					print_size(struct stat stats, size_t longest_size, int\
		special);
void					print_majmin(struct stat stats);
int						is_elem_special(struct stat stats);
int						is_elem_symlink(struct stat stats);
int						look_for_special_elem(t_list *list);
void					print_correct_date(t_args_node *elem);
void					print_name(t_args_node *elem);
void					print_symlink(t_args_node *elem);
int						check_dir_for_l(char *dir_name);
void					print_usage(char c);
void					print_errors(char *name);
void					sort_list_t(t_args_node **head, char *dir_name);
int						is_arg_executable(struct stat stats);
int						is_dir_executable(char *full_path);
void					print_list_no_opts(t_list *list);
t_flags					*set_useless_opts(void);
void					option_i(t_args_node *elem, int max_len);
int						get_inode(t_list *list);
void					option_s(t_args_node *elem, int max_len);
int						get_size(t_list *list, t_flags opts);
void					option_ff(t_args_node *arg);
int						is_there_special(t_list *list);
void					colors(t_args_node *elem, struct stat stats);
void					create_list(t_dirent *lu, char *path, t_list *list,\
		t_flags opts);
void					sort_t_light(t_args_node **a, t_args_node **b,\
		t_args_node **tmp);
int						check_files_end(t_list *no_dir_list, t_flags opts);
#endif
