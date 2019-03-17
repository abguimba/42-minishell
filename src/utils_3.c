/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_clean_one_list(char *clean, char *arg, t_args **args)
{
	char	*memory;
	t_args	*tmp;
	char	*new;
	int		len;
	char	*head;

	memory = arg;
	tmp = *args;
	new = NULL;
	head = NULL;
	len = ft_strlen(arg) - (ft_strlen(clean) - 1);
	while (tmp && ft_strcmp(arg, tmp->value))
		tmp = tmp->next;
	if (!(ft_strcmp(arg, tmp->value)))
	{
		if (!(new = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		head = new;
		ft_clean_one_list_2(arg, new, clean);
	}
	ft_strdel(&memory);
	return (head);
}

void		args_set(t_args **arg, int place)
{
	t_args	*tmp;

	tmp = *arg;
	tmp->space = 0;
	tmp->place = place;
	tmp->lastword = 0;
}

int			ft_next_quote(const char *s, char c)
{
	int		j;

	j = 1;
	s++;
	while (*s != c)
	{
		s++;
		j++;
	}
	return (j + 1);
}

void		print_args(t_args **arg)
{
	t_args		*tmp;

	ft_putendl("PRINTING LIST:");
	tmp = *arg;
	while (tmp)
	{
		ft_putstr("place: ");
		ft_putnbr(tmp->place);
		ft_putchar('\n');
		ft_putstr(tmp->value);
		ft_putendl("DEBUG");
		ft_putstr("space: ");
		ft_putnbr(tmp->space);
		ft_putchar('\n');
		ft_putstr("lastword: ");
		ft_putnbr(tmp->lastword);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		free_args(t_args **arg)
{
	t_args		*tmp;
	t_args		*hold;

	tmp = *arg;
	while (tmp)
	{
		hold = tmp->next;
		ft_strdel(&tmp->value);
		tmp->space = 0;
		tmp->place = 0;
		tmp->lastword = 0;
		free(tmp);
		tmp = NULL;
		tmp = hold;
	}
	*arg = NULL;
}
