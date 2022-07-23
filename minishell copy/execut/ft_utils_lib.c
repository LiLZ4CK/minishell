/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessamad <abdessamad@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:35:35 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/22 03:11:58 by abdessamad       ###   ########.fr       */
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
	node->content = content;
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

t_var	*ft_lstlast(t_var *lst)
{
	t_var	*st;

	st = lst;
	while (st->next)
		st = st->next;
	return (st);
}

void	delete_node_in_env(t_var **t_env, char *key)
{
	t_var	*tmp;
	t_var	*prev;

	tmp = *t_env;
	if (tmp && !(ft_strcmp(tmp->key, key)))
	{
		*t_env = (*t_env)->next;
		free(tmp);
		return ;
	}
	else
	{
		while(tmp)
		{
			if (!ft_strcmp(tmp->key, key))
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

void	delete_node_in_exp(t_var **t_exp, char *key)
{
	t_var	*tmp;
	t_var	*prev;

	tmp = *t_exp;
	if (tmp && !(ft_strcmp(tmp->key, key)))
	{
		*t_exp = (*t_exp)->next;
		free(tmp);
		return ;
	}
	else
	{
		while(tmp)
		{
			if (!ft_strcmp(tmp->key, key))
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
