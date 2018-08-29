/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplest_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:28:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/14 19:28:44 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	simplest_ls(void)
{
	DIR		*rep;
	dirent	*truc_lu;
	S_list	*list;

	rep = NULL;
	truc_lu = NULL;
	if ((rep = opendir(".")) == NULL)
	{
		perror("");
		exit(1);
	}
	list = new_s_list();
	while ((truc_lu = readdir(rep)) != NULL)
	{
		if (truc_lu->d_name[0] != '.')
			append_to_list(list, truc_lu->d_name, 0, NULL);
	}
	closedir(rep);
	merge_sort(&(list->head), NULL);
	print_list(list, NULL, NULL);
	free_list(list);
}

