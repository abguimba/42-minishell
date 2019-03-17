/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*tab_to_line_2(char *newline, char **tab)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			newline[k] = tab[i][j];
			k++;
			j++;
		}
		i++;
	}
	newline[k] = '\0';
	return (newline);
}

void		tab_to_line(char **tab, char **line)
{
	char	*memory;
	char	*newline;
	int		i;
	int		len;

	memory = *line;
	i = 0;
	len = 0;
	while (tab[i])
	{
		len += ft_strlen(tab[i]);
		i++;
	}
	if (!(newline = (char*)malloc(sizeof(char) * len + 1)))
		return ;
	*line = tab_to_line_2(newline, tab);
	ft_strdel(&memory);
}

void		print_env_list(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		ft_putstr(tmp->key);
		ft_putchar('=');
		ft_putstr(tmp->value);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
	{
		ft_putstr(tab[i]);
		ft_putchar('a');
		ft_putchar('\n');
		i++;
	}
}

void		free_tab(char **tab)
{
	int		i;
	char	**head;

	i = 0;
	head = tab;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(head);
	head = NULL;
}
