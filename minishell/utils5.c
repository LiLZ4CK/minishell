/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:28:18 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/02 16:09:39 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

void    *erorat(char *str)
{
    printf("%s\n", str);
    exit(1);
}

b_list  *north_errors(b_list *p)
{
    int i;

    i = p->i;
    if (p->line[p->i] == '>' && p->line[p->i + 1] == '<')
        erorat("syntax error1");
    while (p->line[i] == '>' || p->line[i] == '<')
        i++;
    if ((i - p->i) >= 3)
        erorat("syntax error2");
    if(p->line[i] == ' ' || p->line[i] == '\t')
    {
        i = skip_space(p->line, i);
        if (p->line[i] == '>' || p->line[i] == '<' || p->line[i] == '|'
            || p->line[i] == '\0' || p->line[i] == '\n')
            erorat("syntax error3");
    }
    return(p);
}

b_list  *south_errors(b_list *p)
{
    int i;

    i = p->i;
    while(p->line[i] == '<' || p->line[i] == '>')
        i++;
    if ((i - p->i) >= 3)
        erorat("syntax error4");
    if(p->line[i] == ' ' || p->line[i] == '\t')
    {
        i = skip_space(p->line, i);
        if (p->line[i] == '>' || p->line[i] == '<' || p->line[i] == '|'
            || p->line[i] == '\0' || p->line[i] == '\n')
            erorat("syntax error5");
    }
    return (p);
}

b_list  *grep_file(b_list *p)
{
    char    c;
    p->m->value[p->m->j] = ft_strdup("");
    while(p->line[p->i] != '<' && p->line[p->i] != '>' 
        && p->line[p->i] != '|' && p->line[p->i])
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
    p->m->j++;
    return (p);
}
