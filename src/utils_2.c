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

char	*no_quotes_line(char *s)
{
	char	*newline;
	int		len;
	int		i;

	len = 0;
	i = 0;
	len += ft_strlen(s);
	if (!(newline = malloc(sizeof(char) * len + 1)))
		return (NULL);
	len = 0;
	while (s[len])
	{
		while (s[len] && (s[len] == '\'' || s[len] == '\"'))
			len++;
		newline[i] = s[len];
		len++;
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

int		tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	ft_clean_one_tab(char *s, char ***tab)
{
	char	**tmp;
	char	**newtab;
	int		i;
	int		len;

	i = 0;
	tmp = *tab;
	len = tab_len(tmp);
	if (!(newtab = (char**)malloc(sizeof(char*) * len)))
		return ;
	len = 0;
	while (ft_strcmp(s, tmp[i]))
	{
		newtab[len] = ft_strdup(tmp[i]);
		i++;
		len++;
	}
	i++;
	if (tmp[i])
		clean_one_tab_help(newtab, tmp, i, len);
	free_tab(*tab);
	*tab = newtab;
}

int		search_single_quotes(char *s)
{
	int		counter;

	counter = 0;
	if (*s)
	{
		while (*s)
		{
			if (*s == '\'')
				counter++;
			s++;
		}
	}
	return (counter);
}

int		search_double_quotes(char *s)
{
	int		counter;

	counter = 0;
	if (*s)
	{
		while (*s)
		{
			if (*s == '\"')
				counter++;
			s++;
		}
	}
	return (counter);
}
