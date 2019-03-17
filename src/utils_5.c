/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*env_home_search(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!(ft_strcmp("HOME", tmp->key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("Undefined");
}

int			single_dot_path_counter(char *path)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] && path[i] == '/' && path[i + 1] && path[i + 1] == '.')
		{
			if (path[i + 2] == '\0' || ((path[i + 2] && path[i + 2] == '/')))
			{
				i = i + 1;
				count = count + 1;
			}
		}
		i++;
	}
	return (count);
}

int			double_dot_path_counter(char *path)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] && path[i] == '/' && path[i + 1] && path[i + 1] == '.' &&
			path[i + 2] && path[i + 2] == '.')
		{
			if (path[i + 3] == '\0' || ((path[i + 3] && path[i + 3] == '/')))
			{
				i = i + 2;
				count = count + 1;
			}
		}
		i++;
	}
	return (count);
}

int			single_dot_path_checker(char *path, int place)
{
	if (path[place] && path[place] == '/' &&
		path[place + 1] && path[place + 1] == '.')
		if (path[place + 2] == '\0' || ((path[place + 2] &&
			path[place + 2] == '/')))
			return (1);
	return (0);
}

int			double_dot_path_checker(char *path, int place)
{
	if (path[place] && path[place] == '/' &&
		path[place + 1] && path[place + 1] == '.' &&
		path[place + 2] && path[place + 2] == '.')
		if (path[place + 3] == '\0' || ((path[place + 3] &&
			path[place + 3] == '/')))
			return (1);
	return (0);
}
