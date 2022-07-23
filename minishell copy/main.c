/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/23 03:32:36 by zwalad           ###   ########.fr       */
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
	t_var	*var;

	(void)ac;
	(void)av;
	var = NULL;
	var = cpy_env(&var, env);
	while (1)
	{
		ft_split_env(&var);
		spliti_export(&var);
		p = parser(var);
		builtins(&var, p);
		//the_freeee(p);
	}
}
