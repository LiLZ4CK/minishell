/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:06:26 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/19 23:15:19 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int pr_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

char	*pr_strdup(char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(pr_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

b_list	*pipe_pipe(b_list *p)
{
	p->i++;
	p->i = skip_space(p->line, p->i);
	if (p->line[p->i] == '|' || p->line[p->i] == '\0')
	{
		printf("parse error near '|'\n");
		exit(1);
	}
	p->m = addlast_node(&p->m, new_node(p));
	p->m = p->m->next;
	p->m->next = NULL;
	return(p);
}

b_list	*s_quote(b_list *p)
{
	char	c;
	
	c = p->line[p->i];
	p->i++;
	while (p->line[p->i] != c && p->line[p->i])
		p->m->value[p->m->j] = pr_charjoin(p->m->value[p->m->j], p->line[p->i++]);
	p->i++;
	return (p);
}

b_list	*d_quotes(b_list *p)
{
	char	c;
	
	c = p->line[p->i];
	p->i++;
	while (p->line[p->i] != c && p->line[p->i])
		p->m->value[p->m->j] = pr_charjoin(p->m->value[p->m->j], p->line[p->i++]);
	p->i++;	
	return (p);
}
