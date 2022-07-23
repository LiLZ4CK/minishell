/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:17 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/07 23:35:10 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_var	*cpy_env(t_var **var, char **env)
{
	int	i;

	*var = ft_lstnew(env[0]);
	i = 1;
	while (env[i])
	{
		ft_lstadd_back(var, ft_lstnew(env[i]));
		i++;
	}
	return (*var);
}

void	ft_env(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		printf("%s\n", tmp->env_line);
		tmp = tmp->next;
	}
}