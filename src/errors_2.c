/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_rights_error_2(int mode, char *path)
{
	if (mode == 5)
	{
		ft_putstr_fd("error: file ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(" is not a dir.", 2);
	}
	else if (mode == 6)
	{
		ft_putstr_fd("error: no execute rights to file: ", 2);
		ft_putendl_fd(path, 2);
	}
}

void	cd_rights_error(int mode, char *path)
{
	if (mode == 0)
	{
		ft_putstr_fd("error: file/dir ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(" doesn't exist.", 2);
	}
	else if (mode == 1)
	{
		ft_putstr_fd("error: no read rights to file: ", 2);
		ft_putendl_fd(path, 2);
	}
	else if (mode == 2)
	{
	}
	else if (mode == 3)
	{
	}
}

void	exec_command_not_found(char *command)
{
	ft_putstr_fd("error: command ", 2);
	ft_putstr_fd(command, 2);
	ft_putendl_fd(" not found.", 2);
}

void	exec_fork_error(void)
{
	ft_putendl_fd("error: couldn't fork", 2);
}

void	exec_error_open_dir(char *dir)
{
	ft_putstr_fd("error: directory ", 2);
	ft_putstr_fd(dir, 2);
	ft_putendl_fd(" couldn't be opened.", 2);
}
