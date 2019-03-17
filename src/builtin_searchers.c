/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_searchers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo_search(t_args **arg)
{
	t_args	*tmp;
	char	*echo;
	int		i;

	echo = "echo";
	tmp = *arg;
	i = 0;
	while (tmp->value[i] && (tmp->value[i] == '\'' || tmp->value[i] == '\"'))
		i++;
	while (*echo && *echo == tmp->value[i])
	{
		echo++;
		i++;
	}
	if (tmp->value[i] == '\0' && *echo == '\0')
		return (1);
	return (0);
}

int		ft_exit_search(t_args **arg)
{
	t_args	*tmp;
	char	*str;
	int		i;

	str = "exit";
	tmp = *arg;
	i = 0;
	while (tmp->value[i] && (tmp->value[i] == '\'' || tmp->value[i] == '\"'))
		i++;
	while (*str && *str == tmp->value[i])
	{
		str++;
		i++;
	}
	if (*str == '\0' && tmp->value[i] == '\0')
		return (1);
	return (0);
}

int		ft_env_search(t_args **arg)
{
	t_args	*tmp;
	char	*env;
	int		i;

	env = "env";
	tmp = *arg;
	i = 0;
	while (tmp->value[i] && (tmp->value[i] == '\'' || tmp->value[i] == '\"'))
		i++;
	while (*env && *env == tmp->value[i])
	{
		env++;
		i++;
	}
	if (tmp->value[i] == '\0' && *env == '\0')
		return (1);
	return (0);
}

int		ft_setenv_search(t_args **arg)
{
	t_args	*tmp;
	char	*setenv;
	int		i;

	setenv = "setenv";
	tmp = *arg;
	i = 0;
	while (tmp->value[i] && (tmp->value[i] == '\'' || tmp->value[i] == '\"'))
		i++;
	while (*setenv && *setenv == tmp->value[i])
	{
		setenv++;
		i++;
	}
	if (tmp->value[i] == '\0' && *setenv == '\0')
		return (1);
	return (0);
}

int		ft_unsetenv_search(t_args **arg)
{
	t_args	*tmp;
	char	*unsetenv;
	int		i;

	unsetenv = "unsetenv";
	tmp = *arg;
	i = 0;
	while (tmp->value[i] && (tmp->value[i] == '\'' || tmp->value[i] == '\"'))
		i++;
	while (*unsetenv && *unsetenv == tmp->value[i])
	{
		unsetenv++;
		i++;
	}
	if (tmp->value[i] == '\0' && *unsetenv == '\0')
		return (1);
	return (0);
}
