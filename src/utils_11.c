/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		last_one_com_maker(t_com **com)
{
	t_com	*tmp;

	tmp = *com;
	while (tmp->next)
		tmp = tmp->next;
	tmp->last = 1;
}

int			len_command(char *line, int nb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < nb)
	{
		if (line[i] == ';')
			j++;
		i++;
	}
	if (nb != 0)
		i++;
	j = 0;
	while (line[i] != '\0' && line[i] != ';')
	{
		j++;
		i++;
	}
	return (j);
}

void		free_com(t_com **com)
{
	t_com	*tmp;
	t_com	*hold;

	tmp = *com;
	while (tmp)
	{
		hold = tmp->next;
		ft_strdel(&tmp->line);
		tmp->place = 0;
		tmp->last = 0;
		free(tmp);
		tmp = NULL;
		tmp = hold;
	}
	*com = NULL;
}

int			is_setenv_add(t_env **env, t_args **arg, char *k, char *v)
{
	t_env	*tmp;

	if (ft_setenv_search(arg) && args_checker(arg, 1) && args_checker(arg, 2))
	{
		k = args_picker(arg, 1);
		v = args_picker(arg, 2);
		tmp = *env;
		while (tmp->next && ft_strcmp(k, tmp->key))
			tmp = tmp->next;
		if (tmp)
		{
			if (setenv_adding_check(k, v, 0, 0))
			{
				ft_strdel(&k);
				ft_strdel(&v);
				return (1);
			}
		}
		ft_strdel(&k);
		ft_strdel(&v);
	}
	return (0);
}

int			setenv_add_len_calc(char *newvalue)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (newvalue[i] != '\0' && newvalue[i] != ':')
		i++;
	while (newvalue[i] != '\0' && (!(is_this_a_space(newvalue, i))))
	{
		j++;
		i++;
	}
	return (j + 1);
}
