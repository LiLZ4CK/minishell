/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:09:13 by abel-bou          #+#    #+#             */
/*   Updated: 2022/07/22 19:44:34 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sort_env(t_var **t_exp)
{
	int		i;
	int		len;
	char	*swap;
	t_var	*tmp;
	t_var	*tmp1;

	i = 0;
	tmp = *t_exp;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (ft_strcmp(tmp->content, tmp1->content) > 0)
			{
				swap = tmp->content;
				tmp->content = tmp1->content;
				tmp1->content = swap;
			}
			tmp1 = tmp1->next;
		}
		if (ft_strchr(tmp->content, '='))
		{
			len = ft_strlen(ft_strchr(tmp->content, '='));
			tmp->key = ft_substr(tmp->content, 0, ft_strlen(tmp->content) - len);
			tmp->value = ft_substr(tmp->content, ft_strlen(tmp->content) - len + 1, ft_strlen(tmp->content));
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		}
		else
			printf("declare -x %s\n", tmp->content);
		tmp = tmp->next;
	}
}

int	existed_in_env(t_var **t_env, char *key)
{
    t_var	*tmp;

	tmp = *t_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		 	return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	existed_in_exp(t_var **t_exp, char *key)
{
    t_var	*tmp;

	tmp = *t_exp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
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
		return (-1);
	}
	while (key[i])
	{
		if (key[i] != '=' && key[i] != '_' && ft_isalphanum(key[i]) == 0)
		{
			ft_err("export : not a valid identifier");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	key_no_value(char *key, t_var **t_exp)
{
	if (check_name_key(key))
		return (-1);
	if (!existed_in_exp(t_exp, key))
		ft_lstadd_back(t_exp, ft_lstnew(key));
	return (0);
}

void	write_again_in_env(t_var **t_env, char *key, char *value)
{
    t_var	*tmp;

	tmp = *t_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			tmp->content = key;
			tmp->content = ft_strjoin(tmp->content, "=");
			tmp->content = ft_strjoin(tmp->content, value);
			return ;
		}
		tmp = tmp->next;
	}
}

void	write_again_in_exp(t_var **t_exp, char *key, char *value)
{
    t_var	*tmp;

	tmp = *t_exp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			tmp->content = key;
			tmp->content = ft_strjoin(tmp->content, "=");
			tmp->content = ft_strjoin(tmp->content, value);
			return ;
		}
		tmp = tmp->next;
	}
}

void	search_key_in_exp(t_var **t_exp, char *key_val)
{
    t_var	*tmp;
	char	*key;
	char	*value;
	int		len;

	tmp = *t_exp;
	len = ft_strlen(key_val) - ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, len - 1);
	value = ft_substr(key_val, len + 1, ft_strlen(key_val));
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			tmp->content = ft_strjoin(tmp->content, value);
			break;
		}
		tmp = tmp->next;
	}
}

void	search_key_in_env(t_var **t_env, char *key_val)
{
    t_var	*tmp;
	char	*key;
	char	*value;
	int		len;

	tmp = *t_env;
	len = ft_strlen(key_val) - ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, len - 1);
	value = ft_substr(key_val, len + 1, ft_strlen(key_val));
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			tmp->content = ft_strjoin(tmp->content, value);
			break;
		}
		tmp = tmp->next;
	}
}

void	key_value(t_var **t_env, t_var **t_exp, char *key_val)
{
	int		i;
	int		len;
	char	*key;
	char	*value;

	len = ft_strlen(ft_strchr(key_val, '='));
	key = ft_substr(key_val, 0, ft_strlen(key_val) - len);
	value = ft_substr(key_val, ft_strlen(key_val) - len + 1, ft_strlen(key_val));
	i = 1;
	while (key_val[i])
	{
		if (key_val[i] == '=')
		{
			if (check_name_key(key))
				return ;
			if (!existed_in_env(t_env, key))
				ft_lstadd_back(t_env, ft_lstnew(key_val));
			else
				write_again_in_env(t_env, key, value);

			if (!existed_in_exp(t_exp, key))
				ft_lstadd_back(t_exp, ft_lstnew(key_val));
			else
				write_again_in_exp(t_exp, key, value);
			return ;
		}
		else if (key_val[i] == '+' && key_val[i + 1] == '=')
		{
			key = ft_substr(key_val, 0, ft_strlen(key_val) - len - 1);
			if (check_name_key(key))
				return ;
			if (!existed_in_exp(t_exp, key))
			{
				key = ft_strjoin(key, "=");
				key_val = ft_strjoin(key, value);
				ft_lstadd_back(t_exp, ft_lstnew(key_val));
			}
			else
		 		search_key_in_exp(t_exp, key_val);
			if (!existed_in_env(t_env, key))
			{
				key_val = ft_strjoin(key, value);
				ft_lstadd_back(t_env, ft_lstnew(key_val));
			}
			else
				search_key_in_env(t_env, key_val);
			return ;
		}
		i++;
	}
}

void	exec(t_var **t_env, t_var **t_exp, char *av)
{
	if (!ft_strchr(av, '='))
		key_no_value(av, t_exp);
	else
		key_value(t_env, t_exp, av);
	return ;
}

void	 ft_export(t_var **t_env, t_var **t_exp, b_list *b)
{
	int	i;

	t_var *tmp;
	tmp = *t_exp;
	if (b->wn >= 3)
	{
	 	i = 1;
	 	while (b->m->value[i])
	 	{
			ft_split_env(t_env);
			spliti_export(t_exp);
			exec(t_env, t_exp, b->m->value[i]);
			i++;
	 	}
	}
	else
	 	sort_env(t_exp);
}
