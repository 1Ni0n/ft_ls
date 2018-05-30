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

void	main_ls(char *path, options *opts)
{

	DIR			*rep;
	dirent		*truc_lu;
	S_list 		*list;
	struct stat	sb;
	long		time;

	rep = NULL;
	truc_lu = NULL;
	time = 0;
	list = new_s_list();
	if ((rep = opendir(path)) == NULL)
		perror("");
	while ((truc_lu = readdir(rep)) != NULL)
	{
		if (stat(truc_lu, &sb) == 0)
			time = sb.st_mtime;
		if (truc_lu->d_name[0] == '.' && opts != NULL && opts->a == 1)
			append_to_list(list, truc_lu->d_name, time);
		else if (truc_lu->d_name[0] != '.')
			append_to_list(list, truc_lu->d_name, time);
	}
	sort_list(&list);
	//print_with_opts;
	print_list(list);
	if (opts->R == 1)
		ls_recursive(list, opts);
	//free(list);
}