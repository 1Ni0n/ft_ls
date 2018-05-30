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

	printf("Main ls\n");
	/*DIR			*rep;
	dirent		*truc_lu;
	S_list 		*list;

	rep = NULL;
	truc_lu = NULL;
	list = new_s_list();
	if ((rep = opendir(path)) == NULL)
		perror("");
	while ((truc_lu = readdir(rep)) != NULL)
		append_to_list(list, truc_lu->d_name);
	sort_list(&list);
	print_with_opts(list, opts);
	if (opts->R == 1)
		ls_recursive(list, opts);*/
	//free(list);
}

