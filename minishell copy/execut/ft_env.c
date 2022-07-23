/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:17 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/20 00:11:05 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_var	*cpy_env(t_var **t_env, char **env)
{
	int	i;

	*t_env = ft_lstnew(env[0]);
	i = 1;
	while (env[i])
	{
		ft_lstadd_back(t_env, ft_lstnew(env[i]));
		i++;
	}
	return (*t_env);
}

void	ft_env(t_var **t_env)
{
	t_var	*tmp;

	tmp = *t_env;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}