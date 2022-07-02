/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/02 16:11:38 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int main()
{
	b_list	*p;
	m_list	*tmp;
	
	while (1)
	{
		p = malloc(sizeof(b_list));		
		p = struct_init(p);
		p->i = 0;
		tmp = p->m;
		p->m->j = 0;
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
		p->m = tmp;
		m_list *tmpp;
		while (p->m != NULL)
		{
			int i = 0;
			while(p->m->value[i - 1])
				free(p->m->value[i++]);
			free(p->m->value);
			free(p->m->type);
			tmpp = p->m;
			p->m = p->m->next;
			free(tmpp);
		}
		free(p->line);
		free(p);
	}
}

