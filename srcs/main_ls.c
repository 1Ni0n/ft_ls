/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:24:40 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/29 14:24:41 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static char	*check_path(char *dir_name, char *name)
{
	size_t	len;
	char	*full_path;
	char	end;

	len = ft_strlen(dir_name);
	full_path = NULL;
	end = dir_name[len - 1];
	if (end == '/')
	{
		full_path = ft_strjoin(dir_name, name);
		return (full_path);
	}
	else if (end != '/')
	{
		full_path = ft_strjoin(dir_name, "/");
		full_path = ft_strjoin(full_path, name);
		return (full_path);
	}
	return (NULL);
}

void		main_ls(char *dir_name, options *opts, int print_newline)
{

	DIR			*rep;
	dirent		*truc_lu;
	struct stat	sb;
	long		mtime;
	char 		*full_path;
	S_list 		*list;

	rep = NULL;
	truc_lu = NULL;
	mtime = 0;
	list = new_s_list();
	if ((rep = opendir(dir_name)) == NULL)
	{
		perror("");
		return;
	}
	while ((truc_lu = readdir(rep)) != NULL)
	{
		full_path = check_path(dir_name, truc_lu->d_name);
		if (stat(full_path, &sb) == 0)
			mtime = sb.st_mtime;
		if (truc_lu->d_name[0] == '.' && opts != NULL && opts->a == 1)
			append_to_list(list, truc_lu->d_name, mtime, full_path);
		else if (truc_lu->d_name[0] != '.')
		{
			//printf("CHECK: %s, len: %zu\n", check_path(dir_name, truc_lu->d_name), ft_strlen(check_path(dir_name, truc_lu->d_name)));
			append_to_list(list, truc_lu->d_name, mtime, full_path);
		}
	}
	closedir(rep);
	merge_sort(&(list->head), opts);
	print_list(list, opts, print_newline);
	if (opts != NULL && opts->R == 1)
		ls_recursive(list, opts);
	//free(list);
}