/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:58 by abdessamad        #+#    #+#             */
/*   Updated: 2022/07/07 23:34:29 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void   	ft_cd(b_list *b, t_var **var)
{
	t_var	*tmp;

	tmp = *var;
	if (b->wn == 2)
	{
		while (tmp)
		{
			if (!strcmp(tmp->split_env[0], "HOME"))
			{
				//printf("******%s\n", tmp->split_env[0]);
				if (chdir(tmp->split_env[1]))
					perror("bash: cd: HOME not set\n");
				//update_env_exp(var);
				return ;
			}
			tmp = tmp->next;
		}
	}
	else if (chdir(b->m->value[1]))
		perror("bash: Error changing directory\n");
	update_env_exp(var);
	return ;
}