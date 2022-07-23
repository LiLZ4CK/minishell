/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:48:55 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/04 01:07:10 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_putstr(char *str)
{
    int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;	
	}
	write(2, "\n", 1);
}

void    ft_err(char *msg)
{
    ft_putstr(msg);
	//exit(1);
}