/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*setenv_add_to_existing(char *newvalue, char *value)
{
	char	*new;
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(value) + setenv_add_len_calc(newvalue);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (value[len] != '\0')
	{
		new[j] = value[len];
		j++;
		len++;
	}
	new[j] = ':';
	len = last_apparition_char(newvalue, ':');
	while (newvalue[len] != '\0')
	{
		new[j] = newvalue[len];
		j++;
		len++;
	}
	new[j] = '\0';
	return (new);
}

int			setenv_adding_check(char *key, char *value, int i, int j)
{
	if (letter_counter(value, '$') != 1 || letter_counter(value, ':') != 1)
		return (0);
	while (value[i] != '$')
	{
		if (value[i] && value[i] != ' ' && value[i] != '\n' &&
			value[i] != '\t' && value[i] != '\v' &&
			value[i] != '\f' && value[i] != '\r' &&
			value[i] != '\'' && value[i] != '\"')
			return (0);
		i++;
		if (value[i] == '\0')
			return (0);
	}
	i++;
	while (key[j] != '\0')
	{
		if (key[j] != value[i])
			return (0);
		j++;
		i++;
	}
	if (value[i] && value[i] == ':' && (!(is_this_a_space(value, i))))
		return (1);
	return (0);
}

void		setenv_check(char *key, char *value, t_env **env)
{
	t_env	*tmp;
	t_env	*new;
	char	*memory;

	tmp = *env;
	while (tmp->next && ft_strcmp(key, tmp->key))
		tmp = tmp->next;
	if (!(ft_strcmp(key, tmp->key)))
	{
		memory = tmp->value;
		if (setenv_adding_check(key, value, 0, 0))
			tmp->value = setenv_add_to_existing(value, tmp->value);
		else
			tmp->value = setenv_exists(value);
		ft_strdel(&memory);
	}
	else
	{
		new = setenv_new(key, value);
		tmp->next = new;
	}
}

int			setenv_arg_len(char *arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i] && (arg[i] == '\'' || arg[i] == '\"'))
		i++;
	while (arg[i] && (arg[i] != '\'' && arg[i] != '\"'))
	{
		i++;
		j++;
	}
	return (j);
}

void		ft_setenv(t_args **arg, t_env **env)
{
	char	*key;
	char	*value;

	if (args_checker(arg, 1))
	{
		if (args_checker(arg, 2))
		{
			key = args_picker(arg, 1);
			value = args_picker(arg, 2);
			setenv_check(key, value, env);
			ft_strdel(&key);
			return (ft_strdel(&value));
		}
	}
	setenv_args_error();
}
