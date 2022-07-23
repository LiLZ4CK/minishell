/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:20 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/08 16:19:53 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_name(char *key)
{
	int	i;

	i = 0;
	// if (ft_isalpha(key[0]) == 0)
	// 	return (-1);
	while (key[i])
	{
		if (ft_isalphanum(key[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

// void	ft_unset_in_exp(t_var **var, char *arg)
// {
// 	t_var	*tmp;

// 	tmp = *var;
// 	while (tmp)
// 	{
// 		if (!ft_strcmp(tmp->split_exp[0], arg))
// 		{
// 			// 5asni hna n free dik nod lifiha null
// 			//delete_node(var, arg);
// 			// printf("bla bla\n");
// 			//tmp->exp = NULL;
// 			//tmp->split_exp = NULL;
// 			return ;
// 		}
// 		tmp = tmp->next;
// 	}
// 	return ;
// }

void	ft_unset_in_env(t_var **var, b_list *b)
{
	int		i;
	t_var	*tmp;

	i = 1;
	while (b->m->value[i])
	{
		tmp = *var;
		if (check_name(b->m->value[i]))
			printf("bash: unset: `%s': not a valid identifier\n", b->m->value[i]);
		else
		{
			while (tmp)
			{
				if (!ft_strcmp(tmp->split_env[0], b->m->value[i]))
				{
					//printf("bla bla\n");
					delete_node(var ,b->m->value[i]);
					break;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}


void	ft_unset(t_var **var, b_list *b)
{
	//ft_split_env(var);
	ft_unset_in_env(var, b);
}