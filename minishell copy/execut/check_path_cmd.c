/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:25:20 by abdessamad        #+#    #+#             */
/*   Updated: 2022/07/07 23:06:00 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	*find_path(char **env)
// {
//     int     i;
// 	char	*line_path;

//     i = 0;
//     while (env[i] && strncmp(env[i], "PATH", 4))
//         i++;
//     if (env[i] == NULL)
//         ft_err("Error : There is problem in unset PATH\n");
//     line_path = &env[i][5];
// 	return (line_path);
// }

// void	*check_cmd(t_var **var, char *cmd)
// {
// 	int	i;
    
// 	var->split_cmd = ft_split(cmd, ' ');
// 	i = 0;
// 	while (var->paths[i])
// 	{
// 		var->paths[i] = ft_strjoin(var->paths[i], "/");
// 		var->path_cmd = ft_strjoin(var->paths[i], var->split_cmd[0]);
// 		if (access(var->path_cmd, F_OK) == 0)
// 			return (var->path_cmd);
// 		i++;
// 	}
// 	cmd = var->split_cmd[0];
// 	return (cmd);
// }