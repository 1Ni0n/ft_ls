/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:33:14 by aguillot          #+#    #+#             */
/*   Updated: 2018/05/15 17:33:16 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

longest	*new_longest(void)
{
	longest *longest;

//	if (!(longest = malloc(sizeof(longest))))
//		return (NULL);
	longest->hardlinks = 0;
	longest->uid = 0;
	longest->gid = 0;
	longest->size = 0;
	return (longest);
}

void	free_list(S_list **list)
{
	args_node	*elem;
	args_node	*tmp;

	elem = (*list)->head;
	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		free(tmp);
	}
}

S_list 	*append_to_list(S_list *list, char *content, long mtime, char *path)
{
	if (list != NULL)
	{
		args_node *arg;
		if ((arg = malloc(sizeof *arg)))
		{
			arg->content = ft_strdup(content);
			arg->path = path;
			arg->mtime = mtime;
			arg->next = NULL;
			if (list->head == NULL)
				list->head = arg;
			if (list->tail == NULL)
			{
				list->tail = arg;
				arg->next = NULL;
			}
			else
			{
				list->tail->next = arg;
				list->tail = arg;
				arg->next = NULL;
			}
			list->length++;
		}
	}
	return (list);
}

S_list 	*new_s_list(void)
{
	S_list 	*args;

	if (!(args = malloc(sizeof *args)))
		return (NULL);
	args->length = 0;
	args->head = NULL;
	args->tail = NULL;
	return (args);
}