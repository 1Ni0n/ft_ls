/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:23:28 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 17:29:43 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		check_files_end(t_list *no_dir_list, t_flags opts)
{
	if (no_dir_list->head == NULL)
	{
		free_list(no_dir_list);
		return (0);
	}
	merge_sort(&(no_dir_list->head), opts);
	print_list(no_dir_list, opts, "dont print the blocks 887712*%$");
	free_list(no_dir_list);
	return (1);
}

void	args_controller(char **av)
{
	options	*opts;

	opts = NULL;
	if (av[1][0] == '-')
	{
		opts = check_for_illegal_opts(av);
		ls_controller(av, *opts);
	}
	else
		ls_controller(av, *set_useless_opts());
	free(opts);
}
