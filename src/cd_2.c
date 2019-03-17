/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd_go_oldpwd(char *path, t_env **env)
{
	t_env	*tmp;
	t_env	*save;
	char	*hold;

	tmp = *env;
	while (tmp)
	{
		if (!(ft_strcmp("PWD", tmp->key)))
		{
			save = tmp;
			hold = tmp->value;
		}
		if (!(ft_strcmp("OLDPWD", tmp->key)))
		{
			save->value = tmp->value;
			chdir(save->value);
			tmp->value = (hold);
		}
		tmp = tmp->next;
	}
	ft_strdel(&path);
}

int			ft_cd_len_calculator_path(char *path, int mode, int place)
{
	int		i;

	i = 0;
	if (mode == 1 && place != 1)
	{
		i++;
		while (path[place] != '/' && path[place])
		{
			place++;
			i++;
		}
		return (i);
	}
	else
	{
		while (path[i] != '\0')
			i++;
		if (path[i - 1] == '/')
			i = i - 2;
		else
			i = i - 1;
		while (path[i] != '/')
			i--;
		return (i);
	}
}

char		*ft_cd_backward_path(char *newpath, char *path, int place)
{
	char	*new;
	int		count;
	int		i;
	int		len;

	count = 0;
	i = 0;
	if (single_dot_path_checker(path, place))
		return (single_dot_path_maker(newpath));
	else if (double_dot_path_checker(path, place))
	{
		if ((len = last_apparition_char(newpath, '/')) == 0)
			return (ft_strdup("/"));
		if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (len > 0)
		{
			new[i] = newpath[i];
			i++;
			len--;
		}
		new[i] = 0;
		return (new);
	}
	return (cd_calc_helper(newpath, path, place));
}

int			ft_cd_previous_path_count(char *path, int place)
{
	int		i;

	place = place - 1;
	i = 1;
	while (path[place] != '/')
	{
		place--;
		i++;
	}
	return (i + 2);
}

char		*ft_cd_path_parser_alloc(char *path)
{
	char	*memory;
	char	*new;
	char	*pathhold;
	size_t	i;
	size_t	j;

	i = 0;
	new = NULL;
	pathhold = ft_strdup(path);
	j = ft_strlen(pathhold);
	while (i < j)
	{
		if (pathhold[i] == '/')
		{
			memory = new;
			new = ft_cd_backward_path(new, pathhold, i);
			ft_strdel(&memory);
		}
		i++;
	}
	ft_strdel(&pathhold);
	return (new);
}
