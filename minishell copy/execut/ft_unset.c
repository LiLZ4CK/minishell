/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessamad <abdessamad@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:20 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/22 03:08:20 by abdessamad       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_name(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (ft_isalphanum(key[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_unset_in_env(t_var **t_env, b_list *b)
{
	int		i;
	t_var	*tmp;

	i = 1;
	while (b->m->value[i])
	{
		tmp = *t_env;
		if (check_name(b->m->value[i]))
			printf("bash: unset: `%s': not a valid identifier\n", b->m->value[i]);
		else
		{
			while (tmp)
			{
				if (!ft_strcmp(tmp->key, b->m->value[i]))
				{
					delete_node_in_env(t_env ,b->m->value[i]);
					break;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void	ft_unset_in_exp(t_var **t_exp, b_list *b)
{
	int		i;
	t_var	*tmp;

	i = 1;
	while (b->m->value[i])
	{
		tmp = *t_exp;
		if (check_name(b->m->value[i]))
			printf("bash: unset: `%s': not a valid identifier\n", b->m->value[i]);
		else
		{
			while (tmp)
			{
				if (!ft_strcmp(tmp->key, b->m->value[i]))
				{
					delete_node_in_exp(t_exp ,b->m->value[i]);
					break;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void	ft_unset(t_var **t_env, t_var **t_exp, b_list *b)
{
	ft_split_env(t_env);
	spliti_export(t_exp);
	ft_unset_in_env(t_env, b);
	ft_unset_in_exp(t_exp, b);
}
