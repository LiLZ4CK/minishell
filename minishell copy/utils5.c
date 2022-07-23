/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:28:18 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/21 12:04:32 by zwalad           ###   ########.fr       */
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
		erorat("syntax error");
	while (p->line[i] == '>' || p->line[i] == '<')
		i++;
	if ((i - p->i) >= 3)
		erorat("syntax error");
	if(p->line[i] == ' ' || p->line[i] == '\t')
	{
		i = skip_space(p->line, i);
		if (p->line[i] == '>' || p->line[i] == '<' || p->line[i] == '|'
			|| p->line[i] == '\0' || p->line[i] == '\n')
			erorat("syntax error");
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
		erorat("syntax error");
	if(p->line[i] == ' ' || p->line[i] == '\t')
	{
		i = skip_space(p->line, i);
		if (p->line[i] == '>' || p->line[i] == '<' || p->line[i] == '|'
			|| p->line[i] == '\0' || p->line[i] == '\n')
			erorat("syntax error");
	}
	return (p);
}

b_list  *grep_dollar(b_list *p)
{
	char	*dollo;
	int		j;

	dollo = pr_strdup("");
	p->i++;
	j = 0;
	while (pr_isalnum(p->line2[p->i]) && p->line2[p->i])
		dollo = pr_charjoin(dollo, p->line2[p->i++]);
	if (check_dollar(p, dollo))
	{
		while (p->valo[j])
			p->line = pr_charjoin(p->line, p->valo[j++]);
	}
	p->doll++;
	free(dollo);
	return (p);
}
