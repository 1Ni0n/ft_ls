/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:29:03 by aguillot          #+#    #+#             */
/*   Updated: 2018/06/20 15:29:16 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

int	rev_list(args_node **head)
{
	args_node *prev;
	args_node *elem;
 	args_node *next;

 	prev = NULL;
	elem = NULL;
	next = NULL;
	if(head == NULL)
		return -1;
	elem = *head;
	while(elem != NULL)
	{
		/* Prend l'adresse de la structure suivante */
		next = elem->next;
		/* Redirige le pointeur suivant sur la précédente */
		elem->next = prev;
		/* Garde la structure courante comme précédente */
		prev = elem;
		/* Passe à la suivante. */
		elem = next;		
	}
	*head = prev;
	return (0);
}

args_node	*sorted_merge_t(args_node *a, args_node *b)
{
	args_node *tmp;

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
	{
		if (ft_strcmp(a->content, b->content) < 0)
		{
			tmp = a;
			tmp->next = sorted_merge_t(a->next, b);
		}
		else
		{
			tmp = b;
			tmp->next = sorted_merge_t(a, b->next);
		}
	}
	else
	{
		tmp = b;
		tmp->next = sorted_merge_t(a, b->next);
	}
	return (tmp);
}

void	merge_sort_t(args_node **head)
{
	args_node *elem;
	args_node *a;
	args_node *b;

	elem = *head;
	if (elem == NULL || elem->next == NULL)
		return;
	split_list(elem, &a, &b);
	merge_sort_t(&a);
	merge_sort_t(&b);
	*head = sorted_merge_t(a, b);
}