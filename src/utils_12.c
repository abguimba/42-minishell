/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_12.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exec_mode_helper(char *path, int mode)
{
	if (mode == 2)
	{
		if (existence_check(path, 1) == -1)
			return ;
		else if (execute_check(path, 1) == -1)
			return ;
		else if (dir_check(path, 1) == -1)
			return ;
	}
}

void		print_com(t_com **com)
{
	t_com	*tmp;

	ft_putendl("PRINTING COM:");
	tmp = *com;
	while (tmp)
	{
		ft_putstr("place: ");
		ft_putnbr(tmp->place);
		ft_putchar('\n');
		ft_putstr(tmp->line);
		ft_putendl("DEBUG");
		ft_putstr("last?: ");
		ft_putnbr(tmp->last);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

char		*com_to_line(char *line, t_com **com, int place)
{
	t_com	*tmp;

	tmp = *com;
	while (tmp && tmp->place < place)
		tmp = tmp->next;
	ft_strdel(&line);
	return (ft_strdup(tmp->line));
}

int			com_len(t_com **com)
{
	t_com	*tmp;
	int		i;

	tmp = *com;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char		*command_filler(char *line, int place)
{
	int		i;
	int		j;
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * len_command(line, place) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (j < place)
	{
		if (line[i] == ';')
			j++;
		i++;
	}
	j = 0;
	while (line[i] != '\0' && line[i] != ';')
	{
		new[j] = line[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}
