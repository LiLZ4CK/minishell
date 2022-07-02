/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:58 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/02 16:03:44 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

b_list	*struct_init(b_list *p)
{
	p->line = readline("\x1B[1;31m➜  minishell\x1B[37m ");
	qts_check(p->line);
	p->wn = ft_wnb2(p->line, ' ') + 1;
	p->m = malloc(sizeof(m_list));
	p->m->value = malloc(sizeof(char *) * p->wn);
	p->m->type = malloc(sizeof(int) * p->wn + 1);
	p->m->next = NULL;
	return (p);
}

b_list	*grep_cmarg(b_list *p)
{
	char	c;
	p->m->value[p->m->j] = ft_strdup("");
	while(check_cmd(p->line[p->i], 2) && p->line[p->i])
	{
		if(p->line[p->i] == '"' || p->line[p->i] == '\'')
		{
			c = p->line[p->i];
			p->i++;
			while (p->line[p->i] != c && p->line[p->i])
				p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
		}
		else
			p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
	}
	p->m->type[p->m->j] = ARGG;
	p->m->j++;
	return (p);	
}

b_list	*grep_cmddd(b_list *p)
{
	char	c;
	p->m->value[p->m->j] = ft_strdup("");
	while(check_cmd(p->line[p->i], 2) && p->line[p->i])
	{
		if(p->line[p->i] == '"' || p->line[p->i] == '\'')
		{
			c = p->line[p->i];
			p->i++;
			while (p->line[p->i] != c && p->line[p->i])
				p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
		}
		else	
			p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
	}
	if(p->m->j == 0)
		p->m->type[p->m->j] = CMD;
	else
		p->m->type[p->m->j] = FILEE;
	p->m->j++;
	return (p);
}

b_list	*north_face(b_list *p)
{
	p = south_errors(p);
	if (p->line[p->i] == '>' && p->line[p->i + 1] == '>')
	{
		p->i += 2;
		p->m->type[p->m->j] = APPENDD;
		return (p);
	}
	else
		p->m->type[p->m->j] = INFILEE;
	p->i++;
	return(p);
}

b_list	*south_face(b_list *p)
{
	p = south_errors(p);
	if (p->line[p->i] == '<' && p->line[p->i + 1] == '<')
	{
		p->i += 2;
		p->m->type[p->m->j] = HEARDOC;
		return (p);
	}
	else
		p->m->type[p->m->j] = OUTFILEE;
	p->i++;
	return(p);
}