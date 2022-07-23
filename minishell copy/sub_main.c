/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/23 19:23:39 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

b_list *parser(t_var *var)
{
	b_list	*p;
	m_list	*tmp;
	
	p = malloc(sizeof(b_list));		
	p->var = var;
	p = struct_init(p);
	tmp = p->m;
	p->m->j = 0;
	p->i = 0;
	while (p->line[p->i])
	{
		p->i = skip_space(p->line, p->i);
		if (p->line[p->i] != '<' && p->line[p->i] != '>' && p->line[p->i] != '|')
			p = grep_command(p);
		if (p->line[p->i] == '<' || p->line[p->i] == '>')
			p = grep_token(p);
		if(p->line[p->i] == '|')
			p = pipe_pipe(p);
	}
	p->m->value[p->m->j] = NULL;
	p->m->inf[p->m->ii] = NULL;
	p->m->ouf[p->m->oo] = NULL;
	p->m->herdo[p->m->hr] = NULL;
	p->m = tmp;
	printf("%s \nfinish parse!! \n[abel-bou]➜\n", p->m->value[0]);
	return(p);
}
