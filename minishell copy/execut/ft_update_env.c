/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:45:45 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/07 23:36:05 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_pwd(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		if (!ft_strcmp(tmp->split_env[0], "PWD"))
		{
			tmp->split_env[1] = ft_substr(ft_pwd(), 0, ft_strlen(ft_pwd()));
			tmp->env_line = ft_strjoin("PWD=", tmp->split_env[1]);
			return ;
			//printf("%s\n", tmp->env_line);
		}
		tmp = tmp->next;
	}
	return ;
}

char	*ft_current_pwd(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		if (!ft_strcmp(tmp->split_env[0], "PWD"))
			return (tmp->split_env[1]);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_update_old_pwd(t_var **var)
{
	char	*old_pwd;
	t_var	*tmp;

	tmp = *var;
	// old_pwd = malloc(sizeof(char) * ft_strlen(ft_current_pwd(var)));
	// if (!old_pwd)
	// 	return ;
	old_pwd = ft_current_pwd(var);
	while (tmp)
	{
		if (!ft_strcmp(tmp->split_env[0], "OLDPWD"))
		{
			//printf("(ENV1)======>%s\n", tmp->env_line);
			tmp->env_line = ft_strjoin("OLDPWD=", old_pwd);
			//printf("(ENV2)======>%s\n", tmp->env_line);
			return ;
		}
		tmp = tmp->next;
	}
	//free(old_pwd);
	return ;
}

void    update_env_exp(t_var **var)
{
    ft_update_old_pwd(var);
	ft_update_old_exp(var);
	ft_update_pwd(var);
	ft_update_exp(var);
}