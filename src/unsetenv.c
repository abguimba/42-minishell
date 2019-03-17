/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		unsetenv_del_first(t_env **env)
{
	t_env	*hold;
	t_env	*tmp;
	t_env	*head;

	head = *env;
	tmp = *env;
	hold = tmp->next;
	*env = tmp->next;
	ft_strdel(&tmp->key);
	ft_strdel(&tmp->value);
	free(tmp);
	tmp = NULL;
}

void		unsetenv_del(char *key, t_env **env)
{
	t_env	*tmp;
	t_env	*hold;

	tmp = *env;
	if (!(ft_strcmp(tmp->key, key)))
	{
		unsetenv_del_first(env);
		return ;
	}
	while (tmp)
	{
		if (!(tmp->next))
			return (unsetenv_not_found(key));
		hold = tmp;
		tmp = tmp->next;
		if (!(ft_strcmp(tmp->key, key)))
		{
			hold->next = tmp->next;
			ft_strdel(&tmp->key);
			ft_strdel(&tmp->value);
			free(tmp);
			tmp = NULL;
			return ;
		}
	}
}

void		ft_unsetenv(t_args **arg, t_env **env)
{
	char	*key;
	t_args	*tmp;

	tmp = *arg;
	if (args_len(arg) != 2)
		return (setenv_args_error());
	if (tmp->next->next)
	{
		setenv_args_error();
		return ;
	}
	if (args_checker(arg, 1))
	{
		key = args_picker(arg, 1);
		unsetenv_del(key, env);
		ft_strdel(&key);
		return ;
	}
	setenv_args_error();
}
