/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_13.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_user_prompt(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!(ft_strcmp("USER", tmp->key)))
		{
			ft_putstr(ANSI_COLOR_GREEN);
			ft_putstr("[");
			ft_putstr(ANSI_COLOR_DEFAULT);
			ft_putstr(ANSI_COLOR_MAGENTA);
			ft_putstr(tmp->value);
			ft_putstr(ANSI_COLOR_DEFAULT);
			ft_putstr(ANSI_COLOR_GREEN);
			ft_putstr("] ");
			ft_putstr(ANSI_COLOR_DEFAULT);
		}
		tmp = tmp->next;
	}
}

void		free_env(t_env **env)
{
	t_env		*tmp;
	t_env		*hold;

	tmp = *env;
	while (tmp)
	{
		hold = tmp->next;
		ft_strdel(&tmp->value);
		ft_strdel(&tmp->key);
		free(tmp);
		tmp = NULL;
		tmp = hold;
	}
	*env = NULL;
}
