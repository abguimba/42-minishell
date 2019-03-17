/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_exec(char *line, char **tab)
{
	DIR				*dir;
	struct dirent	*dirent;
	char			*str;

	if (!(dir = opendir(line)))
	{
		exec_error_open_dir(line);
		return (0);
	}
	while ((dirent = readdir(dir)))
	{
		if (!ft_strcmp(dirent->d_name, tab[0]))
		{
			str = join_char(line, tab[0], '/');
			tab[0] = realloc_str(tab[0], str);
			ft_strdel(&str);
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

int		find_exec(char **tab, t_env **env, int i, int mode)
{
	t_env	*tmp;
	char	**array;

	if (!env)
		return (0);
	tmp = *env;
	while (tmp && ft_strcmp(tmp->key, "PATH"))
		tmp = tmp->next;
	if (tmp && (mode == 1 || mode == 3))
	{
		array = ft_strsplit(tmp->value, ':');
		while (array[++i])
		{
			if (get_exec(array[i], tab))
			{
				free_tab(array);
				return (1);
			}
		}
		free_tab(array);
	}
	if (existence_check(tab[0], 0) != -1 && execute_check(tab[0], 0) != -1 &&
		(mode == 2 || mode == 3) && dir_check(tab[0], 0) == -1)
		return (2);
	return (0);
}

void	ft_pid_high_than_zero(int pid, int status)
{
	(void)pid;
	wait(&status);
}

void	ft_exec_norme(char **tab, t_env **env, int mode, int mode2)
{
	int		pid;
	char	**envtab;

	if (find_exec(tab, env, -1, mode))
	{
		envtab = envlist_to_tab(env);
		if ((pid = fork()) == 0)
		{
			if (execute_check(tab[0], mode2) != -1)
				if (execve(tab[0], tab, envtab) != -1)
					ft_putchar('\n');
			exit(0);
		}
		else if (pid >= 0)
			ft_pid_high_than_zero(pid, 0);
		else
			exec_fork_error();
		free_tab(envtab);
	}
	else if (mode == 2)
		exec_mode_helper(tab[0], mode);
	else if (mode == 1)
		exec_command_not_found(tab[0]);
}

void	ft_exec(t_args **arg, t_env **env)
{
	char	**tab;

	if (args_len(arg) < 1)
		return ;
	tab = args_to_tab(arg);
	if (args_len(arg) > 1)
	{
		if (ft_exec_is_path_check(tab))
		{
			ft_strdel(&tab[0]);
			tab[0] = args_picker(arg, 0);
			tab[0] = ft_cd_path_parser(tab[0], env);
			ft_exec_norme(tab, env, 2, 0);
		}
		else
			ft_exec_norme(tab, env, 1, 0);
	}
	else
		ft_exec_part_2(arg, env, tab);
	free_tab(tab);
}
