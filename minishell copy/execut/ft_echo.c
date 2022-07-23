/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:25:44 by abdessamad        #+#    #+#             */
/*   Updated: 2022/07/05 16:04:02 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_utils_echo(b_list *b)
{
	int	count;
	int	i;
	int	j;

	count = 1;
	j = 1;
	while (b->m->value[j])
	{
		if (!strncmp(b->m->value[j], "-n", 2))
		{
			i = 1;
			while (b->m->value[j][i])
			{
				if (b->m->value[j][i] != 'n')
					return (count);
				else
					i++;
			}
			if (!b->m->value[j++][i])
				count++;
		}
		else
			return (j);
	}
	return (count);
}

int	without_arg(b_list *b)
{
	if (b->wn == 2)
	{
		printf("\n");
		return (0);
	}
	return (-1);
}

void	ft_echo(b_list *b)
{
	int	i;

	if (!without_arg(b))
		return ;
	i = ft_utils_echo(b);
	if (ft_utils_echo(b) == 1)
	{
		while (b->m->value[i])
		{
			printf("%s", b->m->value[i++]);
			if (i < b->wn - 1)
				printf(" ");
		}
		printf("\n");
	}
	else
	{
		while (b->m->value[i])
		{
			printf("%s", b->m->value[i++]);
			if (i < b->wn)
				printf(" ");
		}
	}
}
