/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplest_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:28:42 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 11:47:17 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_flags		*set_useless_opts(void)
{
	t_flags *opts;

	if (!(opts = malloc(sizeof(*opts))))
		return (NULL);
	opts->l = 0;
	opts->a = 0;
	opts->r = 0;
	opts->rr = 0;
	opts->t = 0;
	return (opts);
}

void		simplest_ls(void)
{
	DIR			*rep;
	t_dirent	*truc_lu;
	t_list		*list;
	t_flags		*opts;
	t_flags		opt;

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
			append_to_list(list, truc_lu->d_name, NULL);
	}
	closedir(rep);
	opts = set_useless_opts();
	opt = *opts;
	merge_sort(&(list->head), opt);
	print_list_no_opts(list);
	free_list(list);
}
