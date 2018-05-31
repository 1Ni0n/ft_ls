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

void	print_with_opts(S_list *list, options *opts)
{
	args_node	*arg;

	arg = list->head;
	if (opts->t == 1)
		printf("afonwf\n");
		//sort_list_t(list);
	if (opts->r == 1)
		printf("r= 1\n");
		//sort_list_r(list);
	if (opts->a == 1)
	{
		while (arg)
		{
			ft_putstr(arg->content);
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

void	print_list(S_list	*list)
{
	args_node	*entity;

	entity = list->head;
	while (entity)
	{
		//printf("PATH----------------> %s\n", entity->path);
		if (entity->content[0] != '.')
		{
			ft_putstr(entity->content);
			ft_putchar('\n');
		}
		entity = entity->next;
	}
	//free(list);
}
