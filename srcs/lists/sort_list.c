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

#include "../../ft_ls.h"

args_node	*sorted_merge_r(args_node *a, args_node *b)
{
	args_node *elem;

	elem = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->content, b->content) >= 0)
	{
		elem = a;
		elem->next = sorted_merge_r(a->next, b);
	}
	else
	{
		elem = b;
		elem->next = sorted_merge_r(a, b->next);
	}
	return (elem);
}

args_node	*sorted_merge(args_node *a, args_node *b)
{
	args_node *elem;

	elem = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->content, b->content) <= 0)
	{
		elem = a;
		elem->next = sorted_merge(a->next, b);
	}
	else
	{
		elem = b;
		elem->next = sorted_merge(a, b->next);
	}
	return (elem);
}

void	split_list(args_node *elem, args_node **front, args_node **back)
{
	args_node *fast;
	args_node *slow;

	slow = elem;
	fast = elem->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = elem;
	*back = slow->next;
	slow->next = NULL;
}

void	merge_sort(args_node **head, options opts)
{
	args_node *elem;
	args_node *a;
	args_node *b;

	elem = *head;
	if (elem == NULL || elem->next == NULL)
		return;
	split_list(elem, &a, &b);
	merge_sort(&a, opts);
	merge_sort(&b, opts);
	if (opts.r == 1)
		*head = sorted_merge_r(a, b);
	else 
		*head = sorted_merge(a, b);
}