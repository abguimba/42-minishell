/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stdin_error(void)
{
	ft_putendl_fd("error: stdin not avalaible/non géré", 2);
	exit(0);
}

void	setenv_args_error(void)
{
	ft_putendl_fd("error: Bad usage/too many arguments!", 2);
}

void	unsetenv_not_found(char *s)
{
	ft_putstr_fd("error: env variable: ", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(" not found!", 2);
}

void	quotes_error(void)
{
	ft_putendl_fd("error: close your quotes...", 2);
}

void	cd_args_error(void)
{
	ft_putstr_fd("cd error: too many arguments/bad usage or ", 2);
	ft_putendl_fd("spaces in filenames not supported", 2);
}
