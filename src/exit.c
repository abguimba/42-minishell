/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exit_extra_2(t_com **com)
{
	t_com	*hold;
	t_com	*memory;

	hold = *com;
	while (hold)
	{
		memory = hold;
		ft_strdel(&hold->line);
		hold = hold->next;
		free(memory);
		memory = NULL;
	}
	com = NULL;
}

void		ft_exit_extra(t_args **arg, t_com **com)
{
	t_args	*hold;
	t_args	*memory;

	hold = *arg;
	while (hold)
	{
		memory = hold;
		ft_strdel(&hold->value);
		hold = hold->next;
		free(memory);
		memory = NULL;
	}
	arg = NULL;
	ft_exit_extra_2(com);
}

void		ft_exit(char *line, t_args **arg, t_env **env, t_com **com)
{
	t_env	*hold;
	t_env	*memory;

	hold = *env;
	while (hold)
	{
		memory = hold;
		ft_strdel(&hold->key);
		ft_strdel(&hold->value);
		hold = hold->next;
		free(memory);
		memory = NULL;
	}
	env = NULL;
	ft_exit_extra(arg, com);
	ft_strdel(&line);
	exit(0);
}
