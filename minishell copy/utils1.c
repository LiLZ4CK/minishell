/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:40 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/19 19:22:08 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

int	pr_wnb2(char *str, char c)
{
	int		i;
	int		j;
	char	cc;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '|')
			i++;
		if (str[i] == '"' || str[i] == '\'')
		{
			cc = str[i];
			i++;
			while (str[i] != cc && str[i])
				i++;
			if (str[i])
				i++;
			j++;
		}
		if ((str[0] != c && i == 0) || (str[i] != c && str[i - 1] == c)
			|| (str[0] != '<' && i == 0) || (str[i] != '<' && str[i - 1] == '<')
			|| (str[0] != '>' && i == 0) || (str[i] != '>' && str[i - 1] == '>'))
		{
			i++;
			j++;
		}
		if (str[i] || str[i] == '|')
			i++;
	}
	return (j);
}

int	pr_wnbb(char *str, char c)
{
	int		i;
	int		j;
	char	cc;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			cc = str[i];
			i++;
			while (str[i] != cc && str[i])
				i++;
			if(str[i])
				i++;
			j++;
		}
		if (str[i] != '<' || str[i] != '>')
			i++;
		if ((str[0] != c && i == 0) || (str[i] != c && str[i - 1] == c))
		{
			i++;
			j++;
		}
		else if (str[i])
			i++;
	}
	return (j);
}

m_list	*goto_last(m_list *m)
{
	if (!m)
		return (0);
	while (m->next != NULL)
		m = m->next;
	return (m);
}

m_list	*addlast_node(m_list **m, m_list *new)
{
	if (*m == NULL)
		*m = new;
	else
	{
		*m = goto_last(*m);
		(*m)->next = new;
	}
	return (*m);
}
