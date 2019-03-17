/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		args_checker_different_help(char c, int mode)
{
	if (c != ' ' && c != '\n' && c != '\t' && c != '\v' && c != '\f' &&
		c != '\r' && c != '\'' && c != '\"')
	{
		if (mode == 0)
			return (1);
		return (0);
	}
	return (0);
}

int		args_checker_equal_help(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
		c == '\r' || c == '\'' || c == '\"')
		return (1);
	return (0);
}

void	clean_one_tab_help(char **newtab, char **tmp, int i, int j)
{
	while (tmp[i])
	{
		newtab[j] = ft_strdup(tmp[i]);
		i++;
		j++;
	}
	newtab[j] = NULL;
}

int		ft_strsplit_helper(const char *s, int len, char **arg)
{
	int		len2;
	int		nb;

	nb = 0;
	len2 = 0;
	while (*s != '\0')
	{
		if (*s && (*s != ' ' && *s != '\n' && *s != '\t' &&
							*s != '\v' && *s != '\f' && *s != '\r'))
			nb = 1;
		if (*s != ' ' && *s != '\n' && *s != '\t' &&
							*s != '\v' && *s != '\f' && *s != '\r')
			break ;
		s++;
		len2++;
	}
	if (!(*arg = (char*)malloc(sizeof(char) * (len + 1))))
		return (-1);
	ft_strncpy(*arg, s - (len + len2), len);
	if (nb == 1 && len2 > 0)
		return (1);
	return (0);
}

char	*line_format_help(char *tmp, int place, int i, int len)
{
	int		j;
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	j = 0;
	place = i;
	while (ft_isprint(tmp[place]) && tmp[place] != '\'' && tmp[place] != '\"' &&
		tmp[place] != '\0' && tmp[place] != ' ')
	{
		new[j] = tmp[place];
		place++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
