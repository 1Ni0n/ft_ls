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

#include "../ft_ls.h"

void	print_list(S_list *list, options *opts)
{
	args_node	*arg;

	arg = list->head;
	if (opts != NULL && opts->l == 1)
		option_l(list);
	else
	{
		while (arg)
		{
			ft_putstr(arg->content);
			ft_putchar('\n');
			arg = arg->next;
		}
	}
	/*if (opts != NULL)
		free(opts);*/
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