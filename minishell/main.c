/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/27 21:54:40 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"
#include	"libft/libft.h"

/* da_list	*goto_last(da_list *q)
{
	if (!q)
		return (0);
	while (q->next != NULL)
		q = q->next;
	return (q);
}

void	addlast_node(da_list *q, da_list *new)
{
	if (q == NULL)
		q = new;
	else
	{
		goto_last(q)->next = new;
	}
}

da_list	*new_node(char *str, int len, int type)
{
	da_list	*p;
	int		i;

	p = NULL;
	i = 0;
	p = (da_list *)malloc(sizeof(da_list));
	if (!p)
		return (0);
	p->value = malloc(sizeof(char) * len + 1);
	if (!p->value)
		return (0);
	while ((i < len) && str[i])
	{
		p->value[i] = str[i];
		i++;
	}
	p->type = type;
	p->next = NULL;
	return (p);
}

void	mr_white(void)
{
	printf("\x1B[37m");
}

void	handler(int num)
{
	//signal(SIGINT, handler);
	write(STDOUT_FILENO, "➜ mshell  ", 13);
}

da_list	*put_token(da_list *q, char *str, int len, int type)
{
	addlast_node(q, new_node(str, len, type));
	return (q);
}

int	word_counter(t_data *q)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (q->line[i])
	{
		if ((q->line[i] == ' ' || q->line[i] == '\t') && (q->line[i + 1] != ' '
			|| q->line[i + 1] != '\t' || q->line[i + 1] != '\n') && q->line[i + 1])
		{
			i++;
			j++;
		}
		else
			i++;
	}
	return (j);
}

int da_first(t_data *p, da_list *q)
{
	int	j;

	p->i = 0;
	while (p->line[p->i] == ' ' || p->line[p->i] == '\t' || p->line[p->i] == '\n')
	{
		p->i++;
	}
	j = p->i;
	while (p->line[p->i] != ' ' && p->line[p->i] != '\t'
		&& p->line[p->i] != '\n' && p->line[p->i] != '\0')
		p->i++;
	//p->cmd = ft_substr(p->line, j, i - j);
	put_token(q, p->line + j, p->i - j, 1);
	return (p->i);
}
int	put_option(t_data *p, da_list *q)
{
	int	j;

	while (p->line[p->i] == ' ' || p->line[p->i] == '\t' || p->line[p->i] == '\n')
	{
		p->i++;
	}
	j = p->i;
	if (p->line[p->i] == '-')
	{
		while (p->line[p->i] != ' ' && p->line[p->i] != '\t'
			&& p->line[p->i] != '\n' && p->line[p->i] != '\0')
			p->i++;
		put_token(q, p->line + j, p->i - j, 2);
	}
	// p->cmd = ft_substr(p->line, j, i - j);
	return (p->i);
}

char	*line_init(char	*str)
{
	char	*strr;
	int		i;
	int		glen;

	i = 0;
	glen = 0;
	while(str[i])
	{
		if (str[i] != ' ')
	}
}
void	lexer_init(t_data *p)
{
	int		i;
	int		len;
	char	*str;
	da_list	*q;
	t_oken	*z;

	i = 0;
	
	q = new_node("hello", 1, 1);
	p->line = line_init(p->line);
	p->i = da_first(p, q);
	while (p->line[p->i])
	{
		p->i = put_option(p, q);
		
		while (p->line[p->i] == ' ' || p->line[p->i] == '\t' || p->line[p->i] == '\n')
			p->i++;
	}
	q = q->next;
	//====> q;
	//abel - boooooooooooooooo
	return(p);
} */

/* m_list	*goto_last(m_list *m)
{
	if (!m)
		return (0);
	while (m->next != NULL)
		m = m->next;
	return (m);
}

b_list	*go_b(b_list *q)
{
	if (!q)
		return (0);
	while (q->nextt != NULL)
		q = q->nextt;
	return (q);
}

void	addlast_node(m_list **m, m_list *new)
{
	if (*m == NULL)
		*m = new;
	else
	{
		*m = goto_last(*m);
		(*m)->next = new;
	}
}

void	b_last(b_list **q, b_list *new)
{
	if (*q == NULL)
		*q = new;
	else
	{
		*q = go_b(*q);
		(*q)->nextt = new;
	}
}

b_list	*b_node(void)
{
	b_list *q;
	q = malloc(sizeof(b_list));
	return (q);
}

m_list	*new_node(char *str, int type)
{
	m_list *m;
	
	m = malloc(sizeof(m_list));
	m->value = ft_strdup(str);
	m->next = NULL;
	return (m);
}

void	*list_init(b_list *q, char **str, int ind)
{
	int	i;
	
	i = 0;
	if (ind == 1)
	{
		while (str[i])
			i++;
		q = malloc(sizeof(b_list));
	}
	if (ind == 2)
	{
		while (str[i])
			i++;
		printf("%d\n", i);
		//q->m = (struct m_list *)malloc(sizeof(m_list));
		return(q->m);
		//q->m = new_node(q->m, "", 2);
	}
	return(q);
}

void the_test(m_list *m)
{
	printf("\n \n ###########################\n");
	while(m->next)
	{
		printf("%s\n", m->value);
		m = m->next;
		sleep(1);
	}
	
} */

/* int	main()
{
	t_data		*p;
	b_list	*q;
	m_list 	*tmp;
	b_list 	*pmt;
	int	i;
	int	j;

	i = 0;
	p = malloc(sizeof(t_data));
	while (1)
	{
		i = 0;
		j = 0;
		p->line = ft_splito(readline("\x1B[1;31m➜  mshell\x1B[37m "), '|');
		while(p->line[i])
			i++;
		q = b_node();
		pmt = q;
		i = 0;
		q->m = new_node("", 0);
	 	while (p->line[i])
		{
			tmp = q->m;
			j = 0;
			p->lil = ft_splito(p->line[i], ' ');
			while (p->lil[j])
				addlast_node(&q->m, new_node(p->lil[j++], 1));
			b_last(&q, b_node());
			q->m = tmp;
			q = q->nextt;
			free(tmp);
			i++;
		}
		//q->m = q->m->next;
		printf("1111111\n");
		q = pmt;
		while(q->nextt)
		{
			//q->m = q->m->next;
			printf("##########\n");
			while(q->m)
			{
				printf("value = %s\n", q->m->value);
				q->m = q->m->next;
				sleep(1);
			}
			q = q->nextt;
		}
		printf("i = %d\n", i);
		j = 0;
		while (j < i)
			free(p->line[j++]);
	}
} */

/* int	grep_tokenL(char *str, int i)
{
	if (str[i] == '<')
	{
		if (str[i + 1] == '>')
		{
			i = skip_space(str, i);
			if (str[i] == '<' || str[i] == '>' || str[i] == ';' || str[i] == '/')
				return (ERRORR);
			else
				return(JTCREAT);
		}
		else if (str[i + 1] == '<')
		{
			i = skip_space(str, i);
			if (str[i] == '<' || str[i] == '>' || str[i] == ';' || str[i] == '/')
				return (ERRORR);
			else
				return (HEARDOC);
		}
		else if (str[i + 1] == ' ' || str[i + 1] == '\t')
		{
			i = skip_space(str, i);
			if (str[i] == '<' || str[i] == '>' || str[i] == ';' || str[i] == '/')
				return (ERRORR);
			else
				return (SKIPP);
		}
		else
			return (SKIPP);
	}
	return (0);
}

int	grep_tokenR(char *str, int i)
{
	if (str[i] == '>')
	{
		if (str[i + 1] == '<')
				return (ERRORR);
		else if (str[i + 1] == '>')
		{
			i = skip_space(str, i);
			if (str[i] == '<' || str[i] == '>' || str[i] == ';' || str[i] == '/')
				return (ERRORR);
			else
				return (ADDTO);
		}
		else if (str[i + 1] == ' ' || str[i + 1] == '\t')
		{
			i = skip_space(str, i);
			if (str[i] == '<' || str[i] == '>' || str[i] == ';' || str[i] == '/')
				return (ERRORR);
			else
				return (DELNADD);
		}
		else
			return (DELNADD);
	}
	return (0);
} */

/* int	grep_token(char *str, int i)
{
	char	c;

	c = str[i];
	while (str[i] && (str[i] == '<' || str[i] == '>'))
	{
		if   (c == '<')
		{
			if (str[i + 1] == '<')
				return (HEARDOC);
			else
				return (INFILEE);
		}
		else if   (c == '>')
		{
			if (str[i + 1] == '>')
				return (ADDTO);
			else
				return (DELCR);
		}
		i++;
	}
	return (ERRORR);
} */




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

static int	skip_quots(char *str, int i, char sign)
{
	if (str[i] == sign)
	{
		i++;
		while(str[i] != sign && str[i])
			i++;
		i++;
	}
	return (i);
}

static int	ft_wnb(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			i = skip_quots(str, i, str[i]);
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

m_list	*new_node(void)
{
	m_list *m;
	
	m = malloc(sizeof(m_list));
	m->next = NULL;
	return (m);
}

char	*ft_charjoin(char  *s, char c)
{
	char	*str;
	int		len;
	int		i;

	//printf("{%s}\n",s);
	if (s)
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
		if (c == '<' || c == '>' || c == '|' || c == ';')
			return (0);
	}
	if (i == 2)
	{
		if(c == ' ' || c == '\t' || c == '\n' || c == '\0' 
			|| c == '<' || c == '>' || c == '|' || c == ';')
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
			while(check_cmd(p->line[p->i], 2) && p->line[p->i])
			{
				if(p->line[p->i] == '"' || p->line[p->i] == '\'')
				{
					c = p->line[p->i++];
					while (p->line[p->i] != c && p->line[p->i])
						p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
					p->i++;
					p->m->j++;
				}
				p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
			}
			p->m->j++;
		}
		p->i = skip_space(p->line, p->i);
		if (p->line[p->i] == '-')
		{
			while(check_cmd(p->line[p->i], 2) && p->line[p->i])
				p->m->value[p->m->j] = ft_charjoin(p->m->value[p->m->j], p->line[p->i++]);
			p->m->j++;
		}
		p->i = skip_space(p->line, p->i);
	}
	//p->m->value[p->m->j] = NULL;
	return (p);
}

b_list	*grep_token(b_list *p)
{
	int	i;

	i = 0;
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

b_list	*struct_init(b_list *p)
{
	int	wn;
	int pi;

	p->line = readline("\x1B[1;31m➜  minishell\x1B[37m ");
	qts_check(p->line);
	wn = ft_wnb(p->line, ' ') + 1;
	pi = ft_wnb(p->line, '|');
	printf("wn = %d\n", wn);
	p->m = malloc(sizeof(m_list));
	p->m->value = malloc(sizeof(char *) * wn + 1);
	return (p);
}

int main()
{
	b_list	*p;
	
	while (1)
	{
		p = malloc(sizeof(b_list));		
		p = struct_init(p);
		p->i = 0;
	/* 	p->line = readline("\x1B[1;31m➜  minishell\x1B[37m ");
		qts_check(p->line);
		wn = ft_wnb(p->line, ' ') + 1;
		pi = ft_wnb(p->line, '|');
		printf("wn = %d\n", wn);
		p->m = malloc(sizeof(m_list));
		p->m->value = NULL;
		p->m->value = malloc(sizeof(char *) * wn + 1);
		p->i = 0; */
		while (p->line[p->i])
		{
			p->i = skip_space(p->line, p->i);
			if (p->line[p->i] != '<' && p->line[p->i] != '>' && p->line[p->i] != '|')
			{
				p = grep_command(p);
				int k = 0;
				while(k < p->m->j)
				{
					printf("%s\n", p->m->value[k++]);
				}
			}
			if (p->line[p->i] == '<' || p->line[p->i] == '>')
			{
				p = grep_token(p);
			}
			if (p->line[p->i] == ';')
				p->i++;
			if(p->line[p->i] == '|')
			{
				p->m = addlast_node(&p->m, new_node());
				p->i++;
			}
		}
		free(p);
	}
}