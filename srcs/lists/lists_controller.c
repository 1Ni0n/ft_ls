/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguillot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:33:14 by aguillot          #+#    #+#             */
/*   Updated: 2018/09/03 11:56:23 by aguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	free_elem(t_list **list, t_args_node *elem)
{
	t_args_node *tmp;

	tmp = (*list)->head;
	while (tmp)
	{
		if (ft_strcmp(tmp->next->content, elem->content) == 0)
			break ;
		tmp = tmp->next;
	}
	tmp->next = elem->next;
	if (elem->content)
		free(elem->content);
	if (elem->path)
		free(elem->path);
	free(elem);
}

void	free_list(t_list *list)
{
	t_args_node	*elem;
	t_args_node	*next;

	if (list == NULL)
		return ;
	elem = list->head;
	while (elem)
	{
		if (elem->content)
			free(elem->content);
		if (elem->path)
			free(elem->path);
		next = elem->next;
		free(elem);
		elem = next;
	}
	free(list);
}

void	append(t_args_node **arg, char *content, char *path)
{
	(*arg)->content = ft_strdup(content);
	if (path)
	{
		(*arg)->path = ft_strdup(path);
		lstat(path, &(*arg)->stats);
	}
	else
	{
		(*arg)->path = NULL;
		lstat(content, &(*arg)->stats);
	}
}

void	append_to_list(t_list *list, char *content, char *path)
{
	t_args_node *arg;

	if (list != NULL)
	{
		if ((arg = malloc(sizeof(*arg))))
		{
			append(&arg, content, path);
			arg->mtime = 0;
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
}

t_list	*new_s_list(void)
{
	t_list	*args;

	if (!(args = malloc(sizeof(*args))))
		return (NULL);
	args->length = 0;
	args->head = NULL;
	args->tail = NULL;
	return (args);
}
