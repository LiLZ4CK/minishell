/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:40:36 by abel-bou        #+#    #+#             */
/*   Updated: 2022/07/19 14:51:24 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtins(t_var **t_env, t_var **t_exp, b_list *b)
{
	if (b->m->value[0] == 0)
		return;
	if (!strcmp(b->m->value[0], "echo"))
		ft_echo(b);
	else if (!strcmp(b->m->value[0], "cd"))
	 	ft_cd(b, t_env, t_exp);
	else if (!strcmp(b->m->value[0], "pwd"))
		printf("%s\n", ft_pwd());
	else if (!strcmp(b->m->value[0], "env"))
		ft_env(t_env);
	else if (!strcmp(b->m->value[0], "exit"))
		ft_exit();
	else if (!strcmp(b->m->value[0], "unset"))
		ft_unset(t_env, t_exp, b);
	else if (!strcmp(b->m->value[0], "export"))
		ft_export(t_env, t_exp, b);
	else
		perror("Command Not Found\n");
}
