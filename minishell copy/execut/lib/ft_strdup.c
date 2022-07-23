/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:10:22 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/23 18:58:51 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strdup(char *s1)
{
	char	*p;
	size_t	i;

	p = malloc((ft_strlen(s1) * sizeof(char) + 1));
	if (!p)
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
