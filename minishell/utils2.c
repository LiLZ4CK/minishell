/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:51 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/29 17:11:43 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"
#include	"libft/libft.h"

m_list	*new_node(b_list *p)
{
	m_list *m;
	
	m = malloc(sizeof(m_list));
	m->value = malloc(sizeof(char *) * p->wn);
	m->next = NULL;
	return (m);
}

char	*ft_charjoin(char  *s, char c)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
	{
		s = ft_strdup("");
	}
	i = ft_strlenn(s);
	len = i + 2;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	skip_space(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	check_cmd(char c, int i)
{
	if (i == 1)
	{
		if (c == '<' || c == '>' || c == '|')
			return (0);
	}
	if (i == 2)
	{
		if(c == ' ' || c == '\t' || c == '\n' || c == '\0' 
			|| c == '<' || c == '>' || c == '|')
			return(0);
			
	}
	return (1);
}

b_list	*grep_command(b_list *p)
{
	char	c;

	p->m->j = 0;
	while(check_cmd(p->line[p->i], 1) && p->line[p->i])
	{
		if (check_cmd(p->line[p->i], 2) && p->line[p->i])
		{
			p->m->value[p->m->j] = ft_strdup("");
			while(check_cmd(p->line[p->i], 2) && p->line[p->i])
			{
				if(p->line[p->i] == '"' || p->line[p->i] == '\'')
				{
					c = p->line[p->i];
					printf(" cccc ==== %c\n", c);
					p->i++;
					while (p->line[p->i] != c && p->line[p->i])
						p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
				}
				else
					p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
			}
			p->m->j++;
		}
		p->i = skip_space(p->line, p->i);
		if (p->line[p->i] == '-')
		{
			p->m->value[p->m->j] = ft_strdup("");
			while(check_cmd(p->line[p->i], 2) && p->line[p->i])
				p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
			p->m->j++;
		}
		p->i = skip_space(p->line, p->i);
	}
	//p->m->j++;
	//p->m->value[p->m->j] = NULL;
	return (p);
}
