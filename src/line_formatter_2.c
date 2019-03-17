/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_formatter_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_var_tab_change_3(char *s, char *new, char *me, int len)
{
	while (*s != '\0')
	{
		new[len] = *s;
		len++;
		s++;
	}
	new[len] = '\0';
	ft_strdel(&me);
}

char	*env_var_tab_change_2(char *s, char *value, int longeur)
{
	char	*memory;
	char	*new;
	int		len;

	memory = s;
	len = (ft_strlen(s) - (1 + longeur)) + ft_strlen(value);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	while (*s != '$')
	{
		new[len] = *s;
		s++;
		len++;
	}
	s++;
	s += longeur;
	while (*value)
	{
		new[len] = *value;
		value++;
		len++;
	}
	env_var_tab_change_3(s, new, memory, len);
	return (new);
}

char	*env_home_tab_change_2(char *s, char *value)
{
	char	*memory;
	char	*new;
	int		len;
	int		i;

	memory = s;
	len = (ft_strlen(value) + (ft_strlen(s) - 1));
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (value[i] != '\0')
	{
		new[i] = value[i];
		i++;
	}
	len = 1;
	while (s[len] != '\0')
	{
		new[i] = s[len];
		len++;
		i++;
	}
	new[i] = '\0';
	ft_strdel(&memory);
	return (new);
}

char	*env_home_tab_change(char *s, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!(ft_strcmp("HOME", tmp->key)))
		{
			s = env_home_tab_change_2(s, tmp->value);
			return (s);
		}
		tmp = tmp->next;
	}
	return (s);
}
