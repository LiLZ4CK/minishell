/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:40:01 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/21 14:41:08 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_exp(t_var **t_exp)
{
	t_var	*tmp;

	tmp = *t_exp;
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

char	*ft_current_exp(t_var **t_exp)
{
	t_var	*tmp;

	tmp = *t_exp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PWD"))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_update_old_exp(t_var **t_exp)
{
	char	*old_pwd;
	t_var	*tmp;

	tmp = *t_exp;
	// old_pwd = malloc(sizeof(char) * ft_strlen(ft_current_exp(var)));
	// if (!old_pwd)
	// 	return ;
	old_pwd = ft_current_exp(t_exp);
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
