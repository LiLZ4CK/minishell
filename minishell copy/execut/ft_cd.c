/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:58 by abdessamad        #+#    #+#             */
/*   Updated: 2022/07/22 13:46:08 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void   	ft_cd(b_list *b, t_var **t_env, t_var **t_exp)
{
	t_var	*tmp;

	ft_split_env(t_env);
	spliti_export(t_exp);
	tmp = *t_env;
	if (b->wn == 2)
	{
		while (tmp)
		{
			if (!ft_strcmp(tmp->key, "HOME"))
			{
				if (!chdir(tmp->value))
					return ;
			}
			tmp = tmp->next;
		}
		if (!tmp)
			perror("bash: cd: HOME not set\n");
	}
	else if (chdir(b->m->value[1]))
	{
		printf("NAME===>%s\n", b->m->value[1]);
		perror("bash: Error changing directory\n");
	}
	update_pwd_env_exp(t_env, t_exp);
	return ;
}