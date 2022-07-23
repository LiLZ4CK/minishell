/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessamad <abdessamad@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:25 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/22 03:07:35 by abdessamad       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_pwd(void)
{
	char	*cmd;

	cmd = NULL;
	if (!getcwd(cmd, _PC_PATH_MAX))
		return (NULL);
	return (getcwd(cmd, _PC_PATH_MAX));
}