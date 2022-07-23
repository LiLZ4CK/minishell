/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:25 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/05 19:59:09 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_pwd(void)
{
	char	cmd[4096];

	if (!getcwd(cmd, sizeof(cmd)))
		return (NULL);
	// printf("%s\n", cmd);
	return (getcwd(cmd, sizeof(cmd)));
}