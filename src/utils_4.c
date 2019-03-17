/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*relative_path_maker(char *path, char *pwd)
{
	int		len;
	char	*new;
	int		i;
	int		j;

	len = ft_strlen(path) + ft_strlen(pwd);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (pwd[++i] != '\0')
		new[i] = pwd[i];
	if (i != 1)
		new[i++] = '/';
	j++;
	while (path[j] != '\0')
	{
		if (path[j] == '/' && str_printable_lookup(path, j))
			break ;
		new[i] = path[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

int			args_len(t_args **arg)
{
	t_args	*tmp;
	int		i;

	tmp = *arg;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		last_one_list_checker(t_args **arg)
{
	t_args	*tmp;
	t_args	*hold;

	tmp = *arg;
	hold = NULL;
	while (tmp)
	{
		if (tmp->value[0] != '\0')
			hold = tmp;
		tmp = tmp->next;
	}
	if (hold)
	{
		hold->lastword = 1;
		hold->space = 0;
	}
}

char		*args_picker(t_args **arg, int nb)
{
	char	*new;
	t_args	*tmp;
	int		i;

	tmp = *arg;
	while (nb > 0)
	{
		tmp = tmp->next;
		nb--;
	}
	nb = setenv_arg_len(tmp->value);
	if (!(new = malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	i = 0;
	nb = 0;
	while (tmp->value[i] && (tmp->value[i] == '\'' || tmp->value[i] == '\"'))
		i++;
	while (tmp->value[i] && (tmp->value[i] != '\'' && tmp->value[i] != '\"'))
	{
		new[nb] = tmp->value[i];
		i++;
		nb++;
	}
	new[nb] = '\0';
	return (new);
}

int			args_checker(t_args **arg, int nb)
{
	t_args	*tmp;
	int		i;

	tmp = *arg;
	while (nb > 0)
	{
		if (!(tmp->next))
			return (0);
		tmp = tmp->next;
		nb--;
	}
	i = 0;
	while (tmp->value[i] && args_checker_equal_help(tmp->value[i]))
		i++;
	if (tmp->value[i] && args_checker_different_help(tmp->value[i], 0))
		i++;
	while (tmp->value[i] && args_checker_equal_help(tmp->value[i]))
		i++;
	if (tmp->value[i] && args_checker_different_help(tmp->value[i], 1))
		return (0);
	return (1);
}
