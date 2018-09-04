/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:34:05 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/04 11:34:33 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void		sort_t_light(t_args_node **a, t_args_node **b, t_args_node **tmp)
{
	if (ft_strcmp((*a)->content, (*b)->content) < 0)
	{
		*tmp = *a;
		(*tmp)->next = sorted_merge_t((*a)->next, *b);
	}
	else
	{
		*tmp = *b;
		(*tmp)->next = sorted_merge_t(*a, (*b)->next);
	}
}

t_args_node	*sorted_merge_r(t_args_node *a, t_args_node *b)
{
	t_args_node *elem;

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

t_args_node	*sorted_merge(t_args_node *a, t_args_node *b)
{
	t_args_node *elem;

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

void		split_list(t_args_node *elem, t_args_node **front,\
		t_args_node **back)
{
	t_args_node *fast;
	t_args_node *slow;

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

void		merge_sort(t_args_node **head, t_flags opts)
{
	t_args_node *elem;
	t_args_node *a;
	t_args_node *b;

	elem = *head;
	if (elem == NULL || elem->next == NULL)
		return ;
	split_list(elem, &a, &b);
	merge_sort(&a, opts);
	merge_sort(&b, opts);
	if (opts.r == 1)
		*head = sorted_merge_r(a, b);
	else
		*head = sorted_merge(a, b);
}
