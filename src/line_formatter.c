/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_formatter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			env_home_tab(t_args **arg, t_env **env)
{
	t_args		*tmp;
	int			i;

	tmp = *arg;
	while (tmp)
	{
		i = 0;
		while (tmp && tmp->value && tmp->value[i] != '\0')
		{
			if (tmp && tmp->value && tmp->value[i] == '~' &&
				tmp->value[0] != '\"' && tmp->value[0] != '\'')
				tmp->value = env_home_tab_change(tmp->value, env);
			i++;
		}
		if (!tmp)
		{
			if (*arg)
				tmp = *arg;
		}
		else if (tmp->next)
			tmp = tmp->next;
		else
			return ;
	}
}

static char		*env_change(char *arg, char *clean, t_env **env, t_args **args)
{
	t_env		*tmp;
	char		*key;
	char		*value;

	key = NULL;
	value = NULL;
	tmp = *env;
	while (tmp)
	{
		if (!(ft_strcmp(clean, tmp->key)))
		{
			arg = env_var_tab_change_2(arg, tmp->value, ft_strlen(clean));
			return (arg);
		}
		tmp = tmp->next;
	}
	if (!(is_setenv_add(env, args, key, value)))
		arg = ft_clean_one_list(clean, arg, args);
	return (arg);
}

static char		*env_cmp(char *arg, t_env **env, int place, t_args **args)
{
	int			i;
	char		*clean;
	int			len;
	char		*tmp;

	tmp = arg;
	len = 0;
	i = place;
	while (ft_isprint(tmp[place]) && tmp[place] != '\'' && tmp[place] != '\"' &&
		tmp[place] != '\0' && tmp[place] != ' ')
	{
		place++;
		len++;
	}
	clean = line_format_help(tmp, place, i, len);
	arg = env_change(arg, clean, env, args);
	ft_strdel(&clean);
	return (arg);
}

void			env_var_tab(t_args **arg, t_env **env)
{
	t_args		*tmp;
	int			i;

	tmp = *arg;
	while (tmp)
	{
		i = 0;
		while (tmp && tmp->value && tmp->value[i] != '\0')
		{
			if (tmp && tmp->value && tmp->value[i] == '$')
				tmp->value = env_cmp(tmp->value, env, i + 1, arg);
			i++;
		}
		if (!tmp)
		{
			if (*arg)
				tmp = *arg;
		}
		else if (tmp->next)
			tmp = tmp->next;
		else
			return ;
	}
}

void			line_format(char *line, t_env **env, t_args **arg)
{
	if (!(line))
		return ;
	if ((search_double_quotes(line) % 2) != 0)
		return (quotes_error());
	if ((search_single_quotes(line) % 2) != 0)
		return (quotes_error());
	ft_strsplit_minishell(line, arg);
	env_var_tab(arg, env);
	env_home_tab(arg, env);
	last_one_list_checker(arg);
}
