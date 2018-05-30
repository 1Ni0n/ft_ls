/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_controller_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:01:02 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/30 14:01:03 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	sort_list_t(S_list **list)
{
	args_node	*elem;
	args_node	*tmp;
	args_node	*tmp2;

	if ((*list)->head == NULL)
		return;
	elem = (*list)->head;
	while (elem)
	{
		if (elem->next != NULL && (elem->time - elem->next->time) < 0)
		{
			if (elem == (*list)->head)
				(*list)->head = elem->next;
			if (elem->next == (*list)->tail)
				(*list)->tail = elem;
			tmp = elem;
			tmp2 = elem->next;
			tmp->next = tmp->next->next;
			tmp2->next = elem;
			prev_ptr(list, tmp2, tmp2->next);
			elem = (*list)->head;
		}
		else
			elem = elem->next;
	}
}

void	sort_list_r(S_list **list)
{
	args_node 	*elem;
	args_node 	*prev;
	args_node	*next;

	prev = NULL;
	next = NULL;
	if ((*list)->head == NULL)
		return;
	elem = (*list)->head;
	while (elem)
	{
		next = elem->next;
		elem->next = prev;
		prev = elem;
		elem = next;
	}
	(*list)->head = prev;
}
