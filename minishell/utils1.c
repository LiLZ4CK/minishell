/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:40 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/29 16:14:56 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"
#include	"libft/libft.h"
int	ft_wnb2(char *str, char c)
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
		if ((str[0] != c && i == 0) || (str[i] != c && str[i - 1] == c))
		{
			i++;
			j++;
		}
		if (str[i])
			i++;
	}
	return (j);
}

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_wnbb(char *str, char c)
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
