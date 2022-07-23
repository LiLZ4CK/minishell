/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:54:02 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/21 22:32:22 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	pr_strchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (i);
}

int	pr_counterr(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if(str[i] == c && pr_isalnum(str[i + 1]))
			j++;
		i++;
	}
	return (j);
}

int	pr_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int	pr_strncmpp(char *str1, char *str2)
{
	size_t	i;

	if (pr_strlen(str1) != pr_strlen(str2))
		return (2);
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	check_dollar(b_list *p, char *dollo)
{
	int		i;
	int		j;
	t_var	*tmp;

	i = 0;
	tmp = p->var;
	if (dollo == NULL)
		return (0);
	j = pr_strlen(dollo);
	while (p->var != NULL)
	{
		//printf("			TEST HERE\n");
		//printf("	==	%s\n", p->var->split_env[0]);
		if (pr_strncmpp(p->var->split_env[0], dollo) == 0)
		{
			p->valo = pr_strdup(p->var->split_env[1]);
			return (1);
		}
		p->var = p->var->next;
	}
	p->var = tmp;
	return(0);
}

b_list	*dollar_init(b_list *p)
{
	while (p->line2[p->i])
	{
		if (p->line2[p->i] == '\'')
		{
			p->line = pr_charjoin(p->line, p->line2[p->i++]);
			while (p->line2[p->i] != '\'' && p->line2[p->i])
				p->line = pr_charjoin(p->line, p->line2[p->i++]);
			if (p->line2[p->i] == '\'')
				p->line = pr_charjoin(p->line, p->line2[p->i++]);
		}
		if (p->line2[p->i] == '$')
			p = grep_dollar(p);
		else
			p->line = pr_charjoin(p->line, p->line2[p->i++]);
	}
	return (p);
}