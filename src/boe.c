/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		boe(char *line, t_env **env, t_args **arg, t_com **com)
{
	if (ft_echo_search(arg))
		ft_echo(arg);
	else if (ft_exit_search(arg))
		ft_exit(line, arg, env, com);
	else if (ft_setenv_search(arg))
		ft_setenv(arg, env);
	else if (ft_env_search(arg))
		ft_env(env);
	else if (ft_cd_search(arg))
		ft_cd(arg, env);
	else if (ft_unsetenv_search(arg))
		ft_unsetenv(arg, env);
	else
		ft_exec(arg, env);
}
