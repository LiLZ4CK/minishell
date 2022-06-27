/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:08:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/22 23:19:15 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<readline/readline.h>
# include	"./libft/libft.h"

/* typedef struct data
{
	char	**line;
	char	**lil;
	int		i;
	
}t_data;

typedef struct t_zero
{
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	int		fd1;
	int		fd2;
}	t_zero; */

typedef enum
{
	CMD,
	HEARDOC, 
	ADDTO,
	RIGHT,
	ERRORR,
	INFILEE,
	SKIPP,
	DELCR,
	
}t_token;

typedef struct m_list
{
	char			**value;
	t_token			type;
	struct m_list	*next;
	int				j;
}m_list;

typedef struct b_list
{
	char			*line;
	struct b_list	*nextt;
	struct m_list	*m;
	int 			i;
}b_list;

#endif