/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ex_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessamad <abdessamad@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:43:06 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/22 03:07:49 by abdessamad       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	spliti_export(t_var **var)
{
	t_var	*tmp;
	int		len;

	tmp = *var;
	len = 0;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '='))
		{
			len = ft_strlen(ft_strchr(tmp->content, '='));
			tmp->key = ft_substr(tmp->content, 0, ft_strlen(tmp->content) - len);
			tmp->value = ft_substr(tmp->content, ft_strlen(tmp->content) - len + 1, ft_strlen(tmp->content));
		}
		else
			tmp->key = tmp->content;
		tmp = tmp->next;
	}
}

void	ft_split_env(t_var **var)
{
	t_var	*tmp;
	int		len;

	tmp = *var;
	len = 0;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '='))
		{
			len = ft_strlen(ft_strchr(tmp->content, '='));
			tmp->key = ft_substr(tmp->content, 0, ft_strlen(tmp->content) - len);
			tmp->value = ft_substr(tmp->content, ft_strlen(tmp->content) - len + 1, ft_strlen(tmp->content));
		}
		else
			tmp->key = tmp->content;
		tmp = tmp->next;
	}
}
