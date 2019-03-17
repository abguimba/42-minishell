/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_echo(t_args **arg)
{
	t_args	*tmp;
	int		i;

	tmp = *arg;
	tmp = tmp->next;
	while (tmp)
	{
		i = 0;
		while (tmp && tmp->value[0] == '\0')
			tmp = tmp->next;
		if (!(tmp))
			break ;
		while (tmp->value[i] != '\0')
		{
			if (tmp->value[i] != '\"' && tmp->value[i] != '\'')
				ft_putchar(tmp->value[i]);
			i++;
		}
		if (tmp->space == 1)
			ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
