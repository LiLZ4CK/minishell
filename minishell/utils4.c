/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:27:58 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/29 17:11:29 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"
#include	"libft/libft.h"

b_list	*struct_init(b_list *p)
{
	int pi;

	//p->line = ft_splito(readline("\x1B[1;31m➜  minishell\x1B[37m "), ';');
	p->line = readline("\x1B[1;31m➜  minishell\x1B[37m ");
	//check_tokens(p.line);
	qts_check(p->line);
	p->wn = ft_wnb2(p->line, ' ');
	pi = ft_wnbb(p->line, '|') + 1;
	printf("wn = %d\n", p->wn);
	p->m = malloc(sizeof(m_list));
	p->m->value = malloc(sizeof(char *) * p->wn + 1);
	p->m->next = NULL;
	return (p);
}
