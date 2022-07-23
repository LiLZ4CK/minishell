/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessamad <abdessamad@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:45:45 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/22 03:09:55 by abdessamad       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_pwd(t_var **t_env)
{
	t_var	*tmp;

	tmp = *t_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
		{
			tmp->value = ft_substr(ft_pwd(), 0, ft_strlen(ft_pwd()));
			tmp->content = ft_strjoin("PWD=", tmp->value);
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}

char	*ft_current_pwd(t_var **t_env)
{
	t_var	*tmp;

	tmp = *t_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_update_old_pwd(t_var **t_env)
{
	char	*old_pwd;
	t_var	*tmp;

	tmp = *t_env;
	// old_pwd = malloc(sizeof(char) * ft_strlen(ft_current_pwd(var)));
	// if (!old_pwd)
	// 	return ;
	old_pwd = ft_current_pwd(t_env);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "OLDPWD"))
		{
			tmp->content = ft_strjoin("OLDPWD=", old_pwd);
			return ;
		}
		tmp = tmp->next;
	}
	//free(old_pwd);
	return ;
}

void    update_pwd_env_exp(t_var **t_env, t_var **t_exp)
{
    ft_update_old_pwd(t_env);
	ft_update_old_exp(t_exp);
	ft_update_pwd(t_env);
	ft_update_exp(t_exp);
}