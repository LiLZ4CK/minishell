/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:40:36 by abdessamad        #+#    #+#             */
/*   Updated: 2022/07/23 19:23:32 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_strncmppp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < (n - 1) && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

char	*find_path(t_var **var)
{
	t_var	*tmp;	

	tmp = *var; 
	while (ft_strncmppp((*var)->split_env[0] , "PATH", 4))
		*var = (*var)->next;
	*var = tmp;
	return ((*var)->split_env[1]);
}

char	*cmdwpath(t_var **var, b_list *b)
{
	char	*path;
	char	**paths;
	int		i;
	char	*str;
	char	*sstr;

	i = 0;
	if (!access(b->m->value[0], F_OK))
		return (b->m->value[0]);
	path = find_path(var);
	paths = ft_split(path, ':');
	while (paths[i])
	{
		str = ft_strjoin("/", b->m->value[0]);
		sstr = ft_strjoin(paths[i], str);
		if (!access(sstr, F_OK))
		{
			free(path);
			return (one_line(path, str, sstr));
		}
		free(sstr);
		free(str);
		i++;
	}
	return (b->m->value[0]);
}

void	abelbou_zaml(t_var **var, b_list *b)
{
	char	*cmdpt;
	int		pid;
	
	cmdpt = cmdwpath(var, b);
	printf("IM OUT\n");
	pid = fork();
	if (pid == -1)
	{
		execve(cmdpt, b->m->value, NULL);
	}
}

void	builtins(t_var **var, b_list *b)
{
	while (b->m)
	{
		if (!b->m->value[0])
			printf("\n");
		else if (!strcmp(b->m->value[0], "echo"))
			ft_echo(b);
		else if (!strcmp(b->m->value[0], "cd"))
		 	ft_cd(b, var);
		else if (!strcmp(b->m->value[0], "pwd"))
			printf("%s\n", ft_pwd());
		else if (!strcmp(b->m->value[0], "env"))
			ft_env(var);
		else if (!strcmp(b->m->value[0], "exit"))
			ft_exit();
		else if (!strcmp(b->m->value[0], "unset"))
			ft_unset(var, b);
		else if (!strcmp(b->m->value[0], "export"))
			ft_export(var, b);
		else
			printf("cmd not found !\n");
			//abelbou_zaml(var, b);
		b->m = b->m->next;
	}
	
}

// int	main(int ac, char **av, char  **env)
// {
// 	t_var **var;
// 	var = NULL;
// 	var = cpy_env(var, env);
// 	// (void)ac;
// 	// (void)av;
// 	// (void)env;

// 	//char *input;
// 	//while(1)
// 	//{
// 	//	printf("Minishell>");
// 	//	input = readline("");
// 	builtins(var, ac, av, env);
// 	//free_list(var);
// 	//system("leaks minishell");
// 	//}
// }