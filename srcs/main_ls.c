/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:24:40 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 11:46:50 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*check_path(char *dir_name, char *name)
{
	size_t	len;
	char	*full_path;
	char	end;
	char	*tmp;

	tmp = ft_strdup(dir_name);
	len = ft_strlen(dir_name);
	full_path = NULL;
	end = dir_name[len - 1];
	if (end == '/')
	{
		full_path = ft_strlink(&tmp, name);
		return (full_path);
	}
	else
	{
		full_path = ft_strlink(&tmp, "/");
		full_path = ft_strlink(&full_path, name);
		return (full_path);
	}
}

DIR		*check_if_openable(char *dir_name, DIR *rep)
{
	if ((rep = opendir(dir_name)) == NULL)
	{
		print_errors(dir_name);
		return (rep);
	}
	return (rep);
}

void	take_care_of_opts(t_list *list, char *dir_name, t_flags opts)
{
	if (opts.t == 1)
	{
		sort_list_t(&(list->head), dir_name);
		if (opts.r == 1)
			rev_list(&(list->head));
	}
	else
		merge_sort(&(list->head), opts);
	print_list(list, opts, dir_name);
	if (opts.rr == 1)
		ls_recursive(list, opts);
}

void	main_ls_end(t_dirent *lu, char *path, t_list *list, t_flags opts)
{
	struct stat stats;

	if (lu->d_name[0] == '.' && check_for_opt_a(opts) == 1 &&\
			lstat(path, &stats) == 0)
		append_to_list(list, lu->d_name, path);
	else if (lu->d_name[0] != '.' && lstat(path, &stats) == 0)
		append_to_list(list, lu->d_name, path);
	else if (ft_strcmp(lu->d_name, ".") != 0 &&\
			ft_strcmp(lu->d_name, "..") != 0 && opts.aa == 1 &&\
			lstat(path, &stats) == 0)
		append_to_list(list, lu->d_name, path);
	free(path);
}

void	main_ls(char *dir_name, t_flags opts)
{
	DIR			*rep;
	t_dirent	*truc_lu;
	char		*full_path;
	t_list		*list;

	rep = NULL;
	truc_lu = NULL;
	list = new_s_list();
	if ((rep = opendir(dir_name)) == NULL)
	{
		print_errors(dir_name);
		free_list(list);
		return ;
	}
	while ((truc_lu = readdir(rep)) != NULL)
	{
		full_path = check_path(dir_name, truc_lu->d_name);
		main_ls_end(truc_lu, full_path, list, opts);
	}
	closedir(rep);
	take_care_of_opts(list, dir_name, opts);
}
