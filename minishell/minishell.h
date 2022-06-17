/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:08:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/06/17 11:07:58 by zwalad           ###   ########.fr       */
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

typedef struct big_list
{
	char				*ss;
	struct big_list		*nextt;
	struct mini_list	*m;
}big_list;

typedef struct mini_list
{
	char			*value;
	int				type; //char*
	struct mini_list	*next;
	
}mini_list;

typedef struct data
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
}	t_zero;



#endif