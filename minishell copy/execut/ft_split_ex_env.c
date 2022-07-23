/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ex_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:43:06 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/07 23:11:43 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	spliti_export(t_var **var)
{
	t_var	*tmp;
	
	tmp = *var;
	while (tmp)
	{
		tmp->split_exp = ft_split(tmp->exp, '=');
		tmp = tmp->next;
	}
}

void	ft_split_env(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		tmp->split_env = ft_split(tmp->env_line, '=');
		tmp = tmp->next;
	}
}
