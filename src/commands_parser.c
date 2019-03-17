/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			checking_if_coms(t_com **com, int place)
{
	if (!com)
		return (0);
	if (place >= com_len(com))
		return (0);
	return (1);
}

void		more_commands_help(t_com **com, char *line)
{
	t_com	*tmp;
	int		i;

	if (!(tmp = (t_com*)malloc(sizeof(t_com))))
		return ;
	if (!(tmp->line = (char*)malloc(sizeof(char) * len_command(line, 0) + 1)))
		return ;
	i = 0;
	while (line[i] != ';')
	{
		tmp->line[i] = line[i];
		i++;
	}
	tmp->line[i] = '\0';
	tmp->last = 0;
	tmp->place = 0;
	tmp->next = NULL;
	*com = tmp;
}

void		more_commands(t_com **com, char *line, int place)
{
	t_com	*new;
	t_com	*tmp;

	if (place == 0)
		return (more_commands_help(com, line));
	tmp = *com;
	while (tmp->next)
		tmp = tmp->next;
	if (!(new = (t_com*)malloc(sizeof(t_com))))
		return ;
	new->line = command_filler(line, place);
	new->last = 0;
	new->place = place;
	new->next = NULL;
	tmp->next = new;
}

void		one_command(t_com **com, char *line, t_com *new)
{
	if (!(new = (t_com*)malloc(sizeof(t_com))))
		return ;
	new->line = ft_strdup(line);
	new->last = 1;
	new->place = 0;
	new->next = NULL;
	*com = new;
}

void		com_format(t_com **com, char *line)
{
	t_com	*new;
	t_com	*tmp;
	int		i;

	if (!(line))
		return ;
	new = NULL;
	if (letter_counter(line, ';') < 1)
		return (one_command(com, line, new));
	i = 0;
	tmp = *com;
	while (letter_counter(line, ';') - i >= 0)
	{
		more_commands(com, line, i);
		i++;
	}
	last_one_com_maker(com);
}
