/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:08:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/02 16:10:53 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<readline/readline.h>


typedef enum
{
	CMD,
	ARGG,
	FILEE,
	APPENDD,
	HEARDOC,
	OUTFILEE,
	INFILEE
	
}t_token;

typedef struct m_list
{
	char			**value;
	t_token			*type;
	struct m_list	*next;
	int				j;
}m_list;

typedef struct b_list
{
	char			*line;
	struct b_list	*nextt;
	struct m_list	*m;
	int 			i;
	int				wn;
}b_list;

int		ft_wnb2(char *str, char c);
int		ft_strlenn(char *s);
int		ft_wnbb(char *str, char c);
m_list	*goto_last(m_list *m);
m_list	*addlast_node(m_list **m, m_list *new);
m_list	*new_node(b_list *p);
char	*ft_charjoin(char  *s, char c);
int		skip_space(char *str, int i);
int		check_cmd(char c, int i);
b_list	*grep_command(b_list *p);
b_list	*grep_token(b_list *p);
int		single_inqts(char *line);
int		double_inqts(char *line);
void	qts_check(char *line);
b_list	*struct_init(b_list *p);
b_list	*grep_token(b_list *p);
b_list	*grep_cmarg(b_list *p);
b_list	*grep_cmddd(b_list *p);
b_list	*grep_cmdqts(b_list *p);
b_list	*north_face(b_list *p);
b_list	*south_face(b_list *p);
b_list  *north_errors(b_list *p);
b_list  *south_errors(b_list *p);
b_list	*grep_file(b_list *p);
int		ft_strlen(char *str);
char	*ft_strdup( char *s1);
b_list	*pipe_pipe(b_list *p);

#endif