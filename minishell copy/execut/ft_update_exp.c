/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:40:01 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/07 23:36:31 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_exp(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		if (!ft_strcmp(tmp->split_exp[0], "PWD"))
		{
			tmp->split_exp[1] = ft_substr(ft_pwd(), 0, ft_strlen(ft_pwd()));
			tmp->exp = ft_strjoin("PWD=", tmp->split_exp[1]);
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}

char	*ft_current_exp(t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		if (!ft_strcmp(tmp->split_exp[0], "PWD"))
			return (tmp->split_exp[1]);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_update_old_exp(t_var **var)
{
	char	*old_pwd;
	t_var	*tmp;

	tmp = *var;
	// old_pwd = malloc(sizeof(char) * ft_strlen(ft_current_exp(var)));
	// if (!old_pwd)
	// 	return ;
	old_pwd = ft_current_exp(var);
	while (tmp)
	{
		if (!ft_strcmp(tmp->split_exp[0], "OLDPWD"))
		{
			tmp->exp = ft_strjoin("OLDPWD=", old_pwd);
			return ;
		}
		tmp = tmp->next;
	}
	//free(old_pwd);
	return ;
}
