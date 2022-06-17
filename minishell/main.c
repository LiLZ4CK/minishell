/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:03:14 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/17 13:32:56 by zwalad           ###   ########.fr       */
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
	write(STDOUT_FILENO, "➜ minishell  ", 13);
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

mini_list	*goto_last(mini_list *m)
{
	if (!m)
		return (0);
	while (m->next != NULL)
		m = m->next;
	return (m);
}

void addlast_node(mini_list **m, mini_list *new)
{
	if (*m == NULL)
		*m = new;
	else
	{
		*m = goto_last(*m);
		(*m)->next = new;
	}
}

mini_list	*new_node(char *str, int type)
{
	mini_list *m;
	
	m = malloc(sizeof(mini_list));
	m->value = ft_strdup(str);
	m->type = type;
	m->next = NULL;
	return (m);
}

void	*list_init(big_list *q, char **str, int ind)
{
	int	i;
	
	i = 0;
	if (ind == 1)
	{
		while (str[i])
			i++;
		q = malloc(sizeof(big_list));
	}
	if (ind == 2)
	{
		while (str[i])
			i++;
		printf("%d\n", i);
		//q->m = (struct mini_list *)malloc(sizeof(mini_list));
		return(q->m);
		//q->m = new_node(q->m, "", 2);
	}
	return(q);
}

void the_test(mini_list *m)
{
	printf("\n \n ###########################\n");
	while(m->next)
	{
		printf("%s\n", m->value);
		m = m->next;
		sleep(1);
	}
	
}

int	main(void)
{
	t_data		*p;
	big_list	*q;
	mini_list 	*tmp;
	int	i;
	int	j;

	i = 0;
	p = malloc(sizeof(t_data));
	while (!i)
	{
		i = 0;
		p->line = ft_splito(readline("\x1B[1;31m➜  minishell\x1B[37m "), '|');
		q = malloc(sizeof(big_list));
		q->m = new_node("", 0);
		tmp = q->m;
	 	while (p->line[i])
		{
			j = 0;
			printf("SPLIT 1[%d] : %s.\n", i, p->line[i]);
			p->lil = ft_splito(p->line[i], ' ');
			while (p->lil[j])
			{
				printf("In %d\n", j);
				printf("SPLIT 2[%d][%d] : %s\n", i, j, p->lil[j]);
				printf("sssssssssss\n");
				addlast_node(&q->m, new_node(p->lil[j], 1));
				j++;
			}
			i++;
			//q = q->nextt;
		}
		//printf("%s\n", q->m->next->next->next->next->next->next->next->next->value);
		q->m = tmp->next;
		while(q->m)
		{
			printf("%s\n", q->m->value);
			q->m = q->m->next;
			sleep(1);
		}
		free(tmp);
		//goto_last(q->m)->next = NULL;
		//the_test(q->m);
		//lexer_init(p);	
		j = 0;
		while (j < i)
			free(p->line[j++]);
		//p->line = readline("\x1B[1;31m➜  minishell\x1B[37m ");*/
	}
}
