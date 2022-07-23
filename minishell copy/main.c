/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/23 19:38:14 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

void	freee_more(m_list *m)
{
	int	i;

	i = 0;
	while (m->ouf[i])
		free(m->ouf[i++]);
	i = 0;
	while (m->inf[i])
		free(m->inf[i++]);
	i = 0;
	while (m->herdo[i])
		free(m->herdo[i++]);
	i = 0;
	while (m->value[i])
		free(m->value[i++]);
}

void	the_freeee(b_list *p)
{
	m_list	*tmp;

	while (p->m != NULL)
	{
		freee_more(p->m);
		free(p->m->value);
		free(p->m->ouf);
		free(p->m->inf);
		free(p->m->herdo);
		free(p->m->otype);
		tmp = p->m;
		p->m = p->m->next;
		free(tmp);
	}
	free(p->line);
	free(p->m);
	free(p->dollar);
	free(p);
}

int	main(int ac, char **av, char **env)
{
	b_list	*p;
	t_var	*t_env;
	t_var	*t_exp;

	(void)ac;
	(void)av;
	t_env = cpy_env(&t_env, env);
	t_exp = cpy_env(&t_exp, env);
	while (1)
	{
		p = parser(t_env);
		builtins(&t_env, &t_exp, p);
		//the_freeee(p);
	}
}
