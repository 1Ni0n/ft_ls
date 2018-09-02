/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:45:31 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/17 14:50:01 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void 	print_list_no_opts(S_list *list)
{
	args_node *arg;

	arg = list->head;
	while (arg)
	{
		ft_putstr(arg->content);
		//colors(arg, arg->stats);
		ft_putchar('\n');
		arg = arg->next;
	}
}

void	print_list(S_list *list, options opts, char *dir_name)
{
	args_node	*arg;
	int 		max_ino_len;
	int  		max_size_len;

	arg = list->head;
	if (opts.l == 1)
		option_l(list, opts, dir_name);
	else
	{
		if (opts.i == 1)
			max_ino_len = get_inode(list);
		if (opts.s == 1)
			max_size_len = get_size(list, opts);
		while (arg)
		{
			if (opts.i == 1)
				option_i(arg, max_ino_len);
			if (opts.s == 1)
				option_s(arg, max_size_len);
			//colors(arg, arg->stats);
			ft_putstr(arg->content);
			if (opts.ff == 1)
				option_ff(arg);
			ft_putchar('\n');
			arg = arg->next;
		}
	}
}

void	print_does_not_exist_list(S_list *no_list)
{
	args_node	*elem;

	elem = no_list->head;
	while (elem)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(elem->content);
		ft_putstr(": No such file or directory");
		ft_putchar('\n');
		elem = elem->next;
	}
	//free(list);
}