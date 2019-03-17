/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:45:12 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:45:13 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		sig_int_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		print_prompt_pwd();
		signal(SIGINT, sig_int_handler);
	}
}
