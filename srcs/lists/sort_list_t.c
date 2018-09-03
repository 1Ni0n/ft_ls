/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:29:03 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 11:19:42 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

int				rev_list(t_args_node **head)
{
	t_args_node *prev;
	t_args_node *elem;
	t_args_node *next;

	prev = NULL;
	elem = NULL;
	next = NULL;
	if (head == NULL)
		return (-1);
	elem = *head;
	while (elem != NULL)
	{
		next = elem->next;
		elem->next = prev;
		prev = elem;
		elem = next;
	}
	*head = prev;
	return (0);
}

t_args_node		*sorted_merge_t(t_args_node *a, t_args_node *b)
{
	t_args_node *tmp;

	tmp = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->mtime > b->mtime)
	{
		tmp = a;
		tmp->next = sorted_merge_t(a->next, b);
	}
	else if (a->mtime == b->mtime)
		sort_t_light(&a, &b, &tmp);
	else
	{
		tmp = b;
		tmp->next = sorted_merge_t(a, b->next);
	}
	return (tmp);
}

void			merge_sort_t(t_args_node **head)
{
	t_args_node *elem;
	t_args_node *a;
	t_args_node *b;

	elem = *head;
	if (elem == NULL || elem->next == NULL)
		return ;
	split_list(elem, &a, &b);
	merge_sort_t(&a);
	merge_sort_t(&b);
	*head = sorted_merge_t(a, b);
}

void			get_time_info(t_args_node **head, char *dir_name)
{
	t_args_node	*elem;
	struct stat	sb;
	char		*full_path;

	elem = *head;
	while (elem)
	{
		full_path = check_path(dir_name, elem->content);
		if (lstat(full_path, &sb) == 0 && elem->mtime == 0)
			elem->mtime = sb.st_mtime;
		elem = elem->next;
		free(full_path);
	}
}

void			sort_list_t(t_args_node **head, char *dir_name)
{
	get_time_info(head, dir_name);
	merge_sort_t(head);
}
