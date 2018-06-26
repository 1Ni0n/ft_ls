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

char	*check_path(char *dir_name, char *name)
{
	size_t	len;
	char	*full_path;
	char	end;
	char 	*tmp;

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
		tmp = full_path;
		full_path = ft_strjoin(dir_name, "/");
		free(tmp);
		tmp = full_path;
		full_path = ft_strjoin(full_path, name);
		free(tmp);
		return (full_path);
	}
	return (NULL);
}

void	main_ls(char *dir_name, options *opts)
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
	if (opts != NULL && opts->l == 1 && lstat(dir_name, &sb) == 0)
	{
		printf("ELEM: %s, BLOCKS: %d\n", dir_name, lstat(dir_name, &sb));
		print_blocks(dir_name, opts);
	}
	while ((truc_lu = readdir(rep)) != NULL)
	{
		full_path = check_path(dir_name, truc_lu->d_name);
		if (lstat(full_path, &sb) == 0)
			mtime = sb.st_mtime;
		if (truc_lu->d_name[0] == '.' && opts != NULL && opts->a == 1)
			append_to_list(list, truc_lu->d_name, mtime, full_path);
		else if (truc_lu->d_name[0] != '.')
		{
			//printf("CHECK: %s, len: %zu\n", check_path(dir_name, truc_lu->d_name), ft_strlen(check_path(dir_name, truc_lu->d_name)));
			append_to_list(list, truc_lu->d_name, mtime, full_path);
			//printf("NAME: %s, TIME: %ld\n", truc_lu->d_name, mtime);
		}
		free(full_path);
	}
	closedir(rep);
	if (opts != NULL && opts->t == 1)
	{
		merge_sort_t(&(list->head));
		if (opts->r == 1)
			rev_list(&(list->head));
	}
	else
		merge_sort(&(list->head), opts);
	print_list(list, opts);
	if (opts != NULL && opts->R == 1)
		ls_recursive(list, opts);
	free_list(list);
}