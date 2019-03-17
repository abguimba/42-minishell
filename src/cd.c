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

void				ft_cd_go_home(t_env **env)
{
	t_env			*tmp;
	char			*home;
	char			*hold;

	tmp = *env;
	home = env_home_search(env);
	while (tmp)
	{
		if (!(ft_strcmp("PWD", tmp->key)))
		{
			hold = tmp->value;
			tmp->value = ft_strdup(home);
			chdir(tmp->value);
		}
		if (!(ft_strcmp("OLDPWD", tmp->key)))
		{
			ft_strdel(&tmp->value);
			tmp->value = ft_strdup(hold);
		}
		tmp = tmp->next;
	}
	ft_strdel(&hold);
}

void				ft_cd_env_path_modif(char *path, t_env **env)
{
	t_env			*tmp;
	char			*hold;

	tmp = *env;
	while (tmp)
	{
		if (!(ft_strcmp("PWD", tmp->key)))
		{
			hold = tmp->value;
			tmp->value = ft_strdup(path);
			chdir(tmp->value);
		}
		if (!(ft_strcmp("OLDPWD", tmp->key)))
		{
			ft_strdel(&tmp->value);
			tmp->value = ft_strdup(hold);
		}
		tmp = tmp->next;
	}
	ft_strdel(&hold);
}

int					ft_cd_rights_checker(char *path)
{
	int				result;
	struct stat		path_stat;

	stat(path, &path_stat);
	if ((result = access(path, F_OK)) == -1)
	{
		cd_rights_error(0, path);
		return (result);
	}
	if ((result = access(path, R_OK)) == -1)
	{
		cd_rights_error(1, path);
		return (result);
	}
	if ((result = access(path, W_OK)) == -1)
		cd_rights_error(2, path);
	if ((result = access(path, X_OK)) == -1)
		cd_rights_error(3, path);
	if ((result = S_ISDIR(path_stat.st_mode)) == 0)
	{
		cd_rights_error_2(5, path);
		return (-1);
	}
	return (0);
}

char				*ft_cd_path_parser(char *path, t_env **env)
{
	char			*memory;
	t_env			*tmp;

	tmp = *env;
	memory = path;
	while (tmp && (ft_strcmp("PWD", tmp->key)))
		tmp = tmp->next;
	if (!(ft_first_letter_search(path, '/')))
		path = relative_path_maker(path, tmp->value);
	else
		path = absolute_path_parser(path);
	if (single_dot_path_counter(path) + double_dot_path_counter(path) > 0)
	{
		ft_strdel(&memory);
		memory = path;
		path = ft_cd_path_parser_alloc(path);
	}
	ft_strdel(&memory);
	return (path);
}

void				ft_cd(t_args **arg, t_env **env)
{
	char			*path;
	t_args			*tmp;

	tmp = *arg;
	if (args_len(arg) > 2)
		cd_args_error();
	if (args_len(arg) == 1)
		ft_cd_go_home(env);
	if (args_len(arg) > 2 || args_len(arg) == 1)
		return ;
	if (args_checker(arg, 1))
	{
		path = args_picker(arg, 1);
		if (!(ft_strcmp(path, "-")))
			return (ft_cd_go_oldpwd(path, env));
		path = ft_cd_path_parser(path, env);
		if ((ft_cd_rights_checker(path)) == -1)
			return (ft_strdel(&path));
		ft_cd_env_path_modif(path, env);
		return (ft_strdel(&path));
	}
	cd_args_error();
}
