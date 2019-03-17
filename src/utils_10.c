/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					is_this_a_space(char *str, int place)
{
	if (str[place] && str[place] != ' ' && str[place] != '\n' &&
		str[place] != '\t' && str[place] != '\v' &&
		str[place] != '\f' && str[place] != '\r' &&
		str[place] != '\'' && str[place] != '\"')
		return (0);
	return (1);
}

void				arg_extra_cd(t_args **arg)
{
	t_args			*tmp;
	t_args			*new;

	if (!(new = (t_args*)malloc(sizeof(t_args) * 2)))
		return ;
	tmp = *arg;
	new->value = ft_strdup("cd");
	new->place = 0;
	new->space = 1;
	new->lastword = 0;
	new->next = tmp;
	tmp->place = 1;
	*arg = new;
}

int					dir_check(char *path, int mode)
{
	int				result;
	struct stat		path_stat;

	stat(path, &path_stat);
	if ((result = S_ISDIR(path_stat.st_mode)) == 0)
	{
		if (mode == 1)
			error_exec_this_is_dir(path);
		return (-1);
	}
	return (0);
}

int					existence_check(char *path, int mode)
{
	int				result;

	if ((result = access(path, F_OK)) == -1)
	{
		if (mode == 1)
			cd_rights_error(0, path);
		return (result);
	}
	return (0);
}

int					execute_check(char *path, int mode)
{
	int				result;

	if ((result = access(path, X_OK)) == -1)
	{
		if (mode == 1)
			cd_rights_error_2(6, path);
		return (result);
	}
	return (0);
}
