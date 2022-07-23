/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:13 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/07 23:56:14 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sort_env(t_var **var)
{
	int		i;
	t_var	*tmp;
	t_var	*tmp1;
	char	*swap;

	i = 0;
	tmp = *var;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (ft_strcmp(tmp->exp, tmp1->exp) > 0)
			{
				swap = tmp->exp;
				tmp->exp = tmp1->exp;
				tmp1->exp = swap;
			}
			tmp1 = tmp1->next;
		}
		tmp->split_exp = ft_split(tmp->exp, '=');
		printf("%s\n", tmp->exp);
		tmp = tmp->next;
	}
}

int	existed(t_var **var, char *key)
{
	char	**key_val;
    t_var	*tmp;

	tmp = *var;

	key_val = ft_split(key, '=');
	while (tmp)
	{
		if (!strcmp(tmp->split_exp[0], key_val[0]))
		 	return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_name_key(char *key)
{
	int	i;

	i = 1;
	if (key[0] != '_' && ft_isalpha(key[0]) == 0)
	{
		ft_err("export : not a valid identifier");
		//printf("export : '%s':not a valid identifier\n", key);
		return (-1);
	}
	while (key[i])
	{
		if (key[i] != '_' && ft_isalphanum(key[i]) == 0)
		{
			ft_err("export : not a valid identifier");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	key_no_value(char *key, t_var **var)
{
	if (check_name_key(key))
		return (-1);
	if (!existed(var, key))
		ft_lstadd_back(var, ft_lstnew(key));
	return (0);
}

void	write_again(t_var **var, char **key_val)
{
    t_var	*tmp;

	tmp = *var;
	while (var)
	{
		if (!strcmp(tmp->split_exp[0], key_val[0]))
		{
			tmp->exp = key_val[0];
			tmp->exp = ft_strjoin(tmp->exp, "=");
			tmp->exp = ft_strjoin(tmp->exp, key_val[1]);
			return ;
		}
		tmp = tmp->next;
	}
}

void	search_key(t_var **var, char **key_val)
{
    t_var	*tmp;

	tmp = *var;
	while (tmp)
	{
		if (!strcmp(tmp->split_exp[0], key_val[0]))
		{
			tmp->exp = ft_strjoin(tmp->exp, key_val[1]);
			break;
		}
		tmp = tmp->next;
	}
}

void	key_value(t_var **var, char *key_val)
{
	int		i;
	char	**spl_k_v;
	char	*cp_k_v;

	spl_k_v = ft_split(key_val, '=');
	cp_k_v = malloc(sizeof(char) * ft_strlen(key_val) + 4);
	cp_k_v = key_val;
	i = 1;
	while (key_val[i])
	{
		if (key_val[i] == '+' && key_val[i + 1] == '=')
		{
			spl_k_v[0] = ft_substr(spl_k_v[0], 0, ft_strlen(spl_k_v[0]) - 1);
			if (check_name_key(spl_k_v[0]))
				return ;
			if (!existed(var, spl_k_v[0]))
			{
				cp_k_v = ft_substr(cp_k_v, ft_strlen(spl_k_v[0]) + 1, ft_strlen(cp_k_v));
				// cp_k_v = ft_strjoin("=\"", cp_k_v);
				// cp_k_v = ft_strjoin(cp_k_v, "\"");
				key_val = ft_strjoin(spl_k_v[0], cp_k_v);
				ft_lstadd_back(var, ft_lstnew(key_val));
			}
			else
		 		search_key(var, spl_k_v);
			return ;
		}
		i++;
	}
	if (check_name_key(spl_k_v[0]))
		return ;
	if (!existed(var, spl_k_v[0]))
		ft_lstadd_back(var, ft_lstnew(key_val));
	else
		write_again(var, spl_k_v);
}

// void	dollar_variable(t_var **var, char *av)
// {
	
// }

void	without_dollar(t_var **var, char *av)
{
	char	**spl_av;

	spliti_export(var);
	spl_av = ft_split(av, '=');
	if (!spl_av[1])
		key_no_value(spl_av[0], var);
	else
		key_value(var, av);
}

void	ft_export(t_var **var, b_list *b)
{
	int	i;

	if (b->wn >= 3)
	{
	 	i = 1;
	 	while (b->m->value[i])
	 	{
			// if (b->m->value[i][0] == '$')
			// 	dollar_variable(var, b->m->value[i]);
			// else
			without_dollar(var, b->m->value[i]);
	 		i++;
	 	}
		//sort_env(var);
	}
	else
	 	sort_env(var);
}
