/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:08:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/07/23 03:26:29 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<string.h>
# include	<readline/readline.h>
# include	<readline/history.h>

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

typedef struct s_var
{
	char	*env_line;
	char	**split_env;
	char	*exp;
	char	**split_exp;
	struct s_var *next;
}   t_var;

typedef struct m_list
{
	char			**inf;
	char			**ouf;
	char			**value;
	t_token			*otype;
	struct m_list	*next;
	char			**herdo;
	int				j;
	int				oo;
	int				ii;
	int				hr;
}m_list;

typedef struct b_list
{
	char			*line;
	char			*line2;
	struct b_list	*nextt;
	struct m_list	*m;
	int 			i;
	int 			doll;
	int				wn;
	char			**dollar;
	char			**env;
	char			*valo;
	t_var 			*var;
}b_list;


int		pr_wnb2(char *str, char c);
int		pr_wnbb(char *str, char c);
m_list	*goto_last(m_list *m);
m_list	*addlast_node(m_list **m, m_list *new);
m_list	*new_node(b_list *p);
char	*pr_charjoin(char  *s, char c);
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
int		pr_strlen(char *str);
char	*pr_strdup( char *s1);
b_list	*pipe_pipe(b_list *p);
b_list	*s_quote(b_list *p);
b_list	*d_quotes(b_list *p);
int		pr_counterr(char *str, char c);
int		pr_isalnum(int c);
b_list	*grep_dollar(b_list *p);
int		pr_strncmpp(char *str1, char *str2);
int		check_dollar(b_list *p, char *dollo);
b_list	*parser(t_var *var);
b_list	*dollar_init(b_list *p);

//I'm here =============>

//void	*find_path(char **env);
//void	*check_cmd(t_var **var, char *cmd);

t_var	*cpy_env(t_var **var, char **env);
void    update_env_exp(t_var **var);
void	ft_update_old_exp(t_var **var);
void	ft_update_exp(t_var **var);

void	ft_echo(b_list *b);
void   	ft_cd(b_list *b, t_var **var);
char	*ft_pwd();
void	ft_env(t_var **var);
void	ft_exit();
void	ft_unset(t_var **var, b_list *b);
void	ft_export(t_var **var, b_list *b);
void	spliti_export(t_var **var);
void	ft_split_env(t_var **var);

void    ft_err(char *msg);
int		ft_isalpha(int c);
int		ft_isalphanum(int c);
char	**ft_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_len(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);


t_var	*ft_lstnew(char *content);
void	ft_lstadd_back(t_var **lst, t_var *new);
void	ft_lstadd_front(t_var **lst, t_var *new);
t_var	*ft_lstlast(t_var *lst);
int		ft_lstsize(t_var *list);
void	delete_node(t_var **var, char *key);
//void	free_list(t_var **var);

void	builtins(t_var **var, b_list *tmp);
void	the_free(char **str);
int		herror(char *str);
char	*ft_access(char **str);
char	*one_line(char	*path, char *str, char *sstr);

#endif