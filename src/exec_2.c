/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_part_4(t_args **arg, t_env **env, char **tab)
{
	ft_strdel(&tab[0]);
	tab[0] = args_picker(arg, 0);
	tab[0] = ft_cd_path_parser(tab[0], env);
	if (existence_check(tab[0], 0) == -1)
	{
		ft_strdel(&tab[0]);
		tab[0] = args_picker(arg, 0);
		exec_command_not_found(tab[0]);
	}
	else
	{
		ft_strdel(&tab[0]);
		tab[0] = args_picker(arg, 0);
		cd_rights_error_2(7, tab[0]);
	}
}

void		ft_exec_part_3(t_args **arg, t_env **env, char **tab)
{
	if (ft_strcmp("..", tab[0]) != 0 &&
		(ft_strcmp(".", tab[0]) != 0 && find_exec(tab, env, -1, 1)))
	{
		ft_strdel(&tab[0]);
		tab[0] = args_picker(arg, 0);
		return (ft_exec_norme(tab, env, 1, 1));
	}
	else
	{
		ft_strdel(&tab[0]);
		tab[0] = args_picker(arg, 0);
		tab[0] = ft_cd_path_parser(tab[0], env);
		if (existence_check(tab[0], 0) != -1 && dir_check(tab[0], 0) == 0)
		{
			arg_extra_cd(arg);
			ft_cd(arg, env);
			return ;
		}
	}
	ft_strdel(&tab[0]);
	tab[0] = args_picker(arg, 0);
	ft_exec_part_4(arg, env, tab);
}

void		ft_exec_part_2(t_args **arg, t_env **env, char **tab)
{
	if (ft_exec_is_path_check(tab))
	{
		ft_strdel(&tab[0]);
		tab[0] = args_picker(arg, 0);
		tab[0] = ft_cd_path_parser(tab[0], env);
		if (existence_check(tab[0], 1) != -1)
		{
			if (dir_check(tab[0], 0) == 0)
			{
				arg_extra_cd(arg);
				ft_cd(arg, env);
			}
			else
			{
				if (execute_check(tab[0], 1) != -1)
					ft_exec_norme(tab, env, 2, 0);
			}
		}
	}
	else
		ft_exec_part_3(arg, env, tab);
}

int			ft_exec_is_path_check(char **tab)
{
	int		i;

	i = 0;
	while (tab[0][i] != '\0')
	{
		if (tab[0][i] == '/')
			return (1);
		i++;
	}
	return (0);
}
