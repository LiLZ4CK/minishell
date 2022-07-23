/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:54 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/19 15:19:47 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

b_list	*grep_token(b_list *p)
{
	if (p->line[p->i] == '<')
		p = south_face(p);
	else if(p->line[p->i] == '>')
		p = north_face(p);
	p->i = skip_space(p->line, p->i);
	return (p);
}

int	single_inqts(char *line)
{
	int i;
	int d;
	
	i = 0;
	d = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			i++;
			while(line[i] != '"' && line[i])
			{
				if (line[i] == '\'')
					d++;
				i++;
			}
			if(line[i] == '\0')
				d = 0;
		}
		i++;
	}
	return (d);
}

int	double_inqts(char *line)
{
	int i;
	int d;
	
	i = 0;
	d = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			i++;
			while(line[i] != '\'' && line[i])
			{
				if (line[i] == '"')
					d++;
				i++;
			}
			if(line[i] == '\0')
				d = 0;
		}
		i++;
	}
	return (d);
}

void	qts_check(char *line)
{
	int	i;
	int	s;
	int	d;

	s = 0;
	d = 0;
	i = 0;
	while(line[i])
	{
		if (line[i] == '\'')
			s++;
		if (line[i] == '"')
			d++;
		i++;
	}
	d -= double_inqts(line);
	s -= single_inqts(line);
	if (d % 2 || s % 2)
	{
			printf("unclosed quotes\n");
			exit(1);
	}
}
 