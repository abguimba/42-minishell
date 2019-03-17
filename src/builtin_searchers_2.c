/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_searchers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd_search(t_args **arg)
{
	t_args	*tmp;
	char	*cd;
	int		i;

	cd = "cd";
	tmp = *arg;
	i = 0;
	while (tmp->value[i] && (tmp->value[i] == '\'' || tmp->value[i] == '\"'))
		i++;
	while (*cd && *cd == tmp->value[i])
	{
		cd++;
		i++;
	}
	if (tmp->value[i] == '\0' && *cd == '\0')
		return (1);
	return (0);
}
