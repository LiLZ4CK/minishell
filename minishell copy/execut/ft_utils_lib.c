/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:35:35 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/08 16:21:53 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_var	*ft_lstnew(char *content)
{
	t_var	*node;

	node = NULL;
	node = malloc(sizeof(t_var));
	if (!node)
		return (0);
	node->env_line = content;
	node->exp = content;
	node->next = NULL;
	return (node);
}
void	ft_lstadd_back(t_var **lst, t_var *new)
{
	t_var	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstadd_front(t_var **lst, t_var *new)
{
	new->next = *lst;
	*lst = new;
}

t_var	*ft_lstlast(t_var *lst)
{
	t_var	*st;

	st = lst;
	while (st->next)
		st = st->next;
	return (st);
}

int	ft_lstsize(t_var *list)
{
	int	size;

	size = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

void	delete_node(t_var **var, char *key)
{
	t_var	*tmp;
	t_var	*prev;

	tmp = *var;
	if (tmp && !ft_strcmp(tmp->split_env[0], key))
	{
		*var = (*var)->next;
		free(tmp);
		return ;
	}
	else
	{
		while(tmp)
		{
			if (!ft_strcmp(tmp->split_env[0], key))
			{
				prev->next = tmp->next;
				free(tmp);
				break;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
