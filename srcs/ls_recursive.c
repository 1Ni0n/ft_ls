/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:13:15 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/28 15:13:17 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	ls_recursive(S_list *list, options *opts)
{
	args_node	*arg;
	struct stat sb;

	arg = list->head;
	while (arg)
	{
		if (stat(arg->content, &sb) == 1)
			main_ls(arg->content, opts);
		arg = arg->next;
	}
	while (arg)
	{
		arg = arg->next; 
	}
}
