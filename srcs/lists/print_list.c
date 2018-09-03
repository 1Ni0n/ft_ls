/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:45:31 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 17:36:09 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	print_list_no_opts(t_list *list)
{
	t_args_node *arg;

	arg = list->head;
	while (arg)
	{
		colors(arg, arg->stats);
		ft_putchar('\n');
		arg = arg->next;
	}
}

void	print_it(t_args_node *arg, options opts, int max_s_len, int max_i_len)
{
	while (arg)
	{
		if (opts.i == 1)
			option_i(arg, max_i_len);
		if (opts.s == 1)
			option_s(arg, max_s_len);
		colors(arg, arg->stats);
		if (opts.ff == 1)
			option_ff(arg);
		ft_putchar('\n');
		arg = arg->next;
	}
}

void	print_list(t_list *list, options opts, char *dir_name)
{
	t_args_node	*arg;
	int			max_i_len;
	int			max_s_len;

	arg = list->head;
	max_i_len = 0;
	max_s_len = 0;
	if (opts.l == 1)
		option_l(list, opts, dir_name);
	else
	{
		if (opts.i == 1)
			max_i_len = get_inode(list);
		if (opts.s == 1)
			max_s_len = get_size(list, opts);
		print_it(arg, opts, max_s_len, max_i_len);
	}
}

void	print_does_not_exist_list(t_list *no_list)
{
	t_args_node	*elem;

	elem = no_list->head;
	while (elem)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(elem->content);
		ft_putstr(": No such file or directory");
		ft_putchar('\n');
		elem = elem->next;
	}
}
