/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**envlist_to_tab(t_env **env)
{
	t_env	*tmp;
	char	**tab;
	int		i;

	tmp = *env;
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (env_struct_len(env) + 1))))
		return (NULL);
	while (tmp)
	{
		tab[i] = env_struct_picker(env, i);
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char		*join_char(char *str, char *str2, char c)
{
	int		i;
	int		j;
	char	*newstr;

	i = ft_strlen(str);
	i = i + ft_strlen(str2);
	newstr = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = c;
	j = -1;
	while (str2[++j])
	{
		i++;
		newstr[i] = str2[j];
	}
	newstr[i + 1] = '\0';
	return (newstr);
}

char		*realloc_str(char *str, char *newstr)
{
	if (str)
		ft_strdel(&str);
	str = ft_strdup(newstr);
	return (str);
}

char		**args_to_tab(t_args **arg)
{
	t_args	*tmp;
	char	**tab;
	int		i;

	tmp = *arg;
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (args_len(arg) + 1))))
		return (NULL);
	while (tmp)
	{
		tab[i] = args_picker(arg, i);
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int			letter_counter(char *str, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}
