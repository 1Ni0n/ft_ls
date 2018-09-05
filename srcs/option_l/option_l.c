/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:53:55 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 12:40:58 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	option_l(t_list *list, t_flags opts, char *dir_name)
{
	t_args_node		*elem;
	t_longest		longest;

	elem = list->head;
	if (ft_strcmp(dir_name, "dont print the blocks 887712*%$") != 0)
		print_blocks_if_dir_full(list, opts, dir_name);
	longest = get_longest(list);
	option_l_printing(list, longest, opts);
}
