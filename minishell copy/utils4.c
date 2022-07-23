/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:58 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/23 03:50:00 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

b_list	*struct_init(b_list *p)
{
	p->line2 = readline("\x1B[1;31m➜  minishell\x1B[37m ");
	p->line = pr_strdup("");
	p->i = 0;
	p = dollar_init(p);
	p->i = 0;
	qts_check(p->line);
	p->wn = pr_wnb2(p->line, ' ') + 1;
	p->doll = pr_counterr(p->line, '$');
	p->m = malloc(sizeof(m_list));
	p->m->ii = 0;
	p->m->oo = 0;
	p->m->hr = 0;
	p->dollar = malloc(sizeof(char) * pr_counterr(p->line, '$') );
	p->m->ouf = malloc(sizeof(char *) * p->wn);
	p->m->inf = malloc(sizeof(char *) * p->wn);
	p->m->herdo = malloc(sizeof(char *) * p->wn);
	p->m->value = malloc(sizeof(char *) * p->wn);
	p->m->otype = malloc(sizeof(int) * p->wn);
	p->m->j = 0;
	p->doll = 0;
	p->m->next = NULL;
	add_history(p->line2);
	free(p->line2);
	return (p);
}

b_list	*grep_cmarg(b_list *p)
{
	char	c;
	p->m->value[p->m->j] = pr_strdup("");
	while(check_cmd(p->line[p->i], 2) && p->line[p->i])
	{
		if(p->line[p->i] == '"' || p->line[p->i] == '\'')
		{
			c = p->line[p->i];
			p->i++;
			while (p->line[p->i] != c && p->line[p->i])
				p->m->value[p->m->j] = pr_charjoin(p->m->value[p->m->j], p->line[p->i++]);
		}
		else
			p->m->value[p->m->j] = pr_charjoin(p->m->value[p->m->j], p->line[p->i++]);
	}
	p->m->j++;
	return (p);	
}

b_list	*grep_cmddd(b_list *p)
{
	char	c;
	
	p->m->value[p->m->j] = pr_strdup("");
	while (check_cmd(p->line[p->i], 2) && p->line[p->i])
	{
		if(p->line[p->i] == '"')
			p = d_quotes(p);
		else if (p->line[p->i] == '\'')
		{
			p = s_quote(p);
			c = p->line[p->i];
			p->i++;
			while (p->line[p->i] != c && p->line[p->i])
				p->m->value[p->m->j] = pr_charjoin(p->m->value[p->m->j], p->line[p->i++]);
			p->i++;
		}
		else	
			p->m->value[p->m->j] = pr_charjoin(p->m->value[p->m->j], p->line[p->i++]);
	}
	p->m->j++;
	return (p);
}

b_list	*north_face(b_list *p)
{
	p->m->ouf[p->m->oo] = pr_strdup("");
	p = south_errors(p);
	if (p->line[p->i] == '>' && p->line[p->i + 1] == '>')
	{
		p->i = skip_space(p->line, p->i + 2);
		while(pr_isalnum(p->line[p->i]))
			p->m->ouf[p->m->oo] = pr_charjoin(p->m->ouf[p->m->oo], p->line[p->i++]);
		p->m->otype[p->m->oo] = APPENDD;
	}
	else
	{
		p->i = skip_space(p->line, p->i + 1);
		while(pr_isalnum(p->line[p->i]))
			p->m->ouf[p->m->oo] = pr_charjoin(p->m->ouf[p->m->oo], p->line[p->i++]);
		p->m->otype[p->m->oo] = INFILEE;
	}
	p->m->oo++;
	return(p);
}

b_list	*south_face(b_list *p)
{
	p = south_errors(p);
	if (p->line[p->i] == '<' && p->line[p->i + 1] == '<')
	{
		p->m->herdo[p->m->hr] = pr_strdup("");
		p->i = skip_space(p->line, p->i + 2);
		while(pr_isalnum(p->line[p->i]) && p->line[p->i])
			p->m->herdo[p->m->hr] = pr_charjoin(p->m->herdo[p->m->hr], p->line[p->i++]);
		p->m->hr++;
		return (p);
	}
	else
	{
		p->m->inf[p->m->ii] = pr_strdup("");
		p->i = skip_space(p->line, p->i + 1);
		while(pr_isalnum(p->line[p->i]) && p->line[p->i])
			p->m->inf[p->m->ii] = pr_charjoin(p->m->inf[p->m->ii], p->line[p->i++]);
		p->m->ii++;
	}
	return(p);
} 
