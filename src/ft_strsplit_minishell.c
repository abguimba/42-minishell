/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_minishell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:46:50 by abguimba          #+#    #+#             */
/*   Updated: 2018/12/02 17:33:51 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strsplit_advance(const char *s)
{
	int		spaces;
	int		len;

	spaces = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' ||
							*s == '\v' || *s == '\f' || *s == '\r')
	{
		spaces++;
		s++;
	}
	len = 0;
	while (*s && *s != ' ' && *s != '\n' && *s != '\t' &&
							*s != '\v' && *s != '\f' && *s != '\r' &&
							*s != '\'' && *s != '\"')
	{
		s++;
		len++;
	}
	if (*s && (*s == '\'' || *s == '\"') && len == 0)
	{
		len += ft_next_quote(s, *s);
		s += len;
	}
	return (spaces + len);
}

int		ft_strsplit_checker_minishell(const char *s)
{
	int		k;

	k = 0;
	while (s[k] && (s[k] == ' ' || s[k] == '\n' || s[k] == '\t' ||
							s[k] == '\v' || s[k] == '\f' || s[k] == '\r'))
		k++;
	if (s[k] && (s[k] != ' ' && s[k] != '\n' && s[k] != '\t' &&
							s[k] != '\v' && s[k] != '\f' && s[k] != '\r'))
		return (1);
	return (0);
}

int		ft_count_words_minishell(const char *s)
{
	int		words;
	int		counter;

	words = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' ||
							*s == '\v' || *s == '\f' || *s == '\r')
		s++;
	while (*s)
	{
		counter = 0;
		while (*s && *s != ' ' && *s != '\n' && *s != '\t' &&
								*s != '\v' && *s != '\f' &&
								*s != '\r' && *s != '\'' && *s != '\"')
		{
			s++;
			counter++;
		}
		if ((*s == '\'' || *s == '\"') && (counter == 0))
			s += ft_next_quote(s, *s) + 1;
		while (*s && (*s == ' ' || *s == '\n' || *s == '\t' ||
								*s == '\v' || *s == '\f' || *s == '\r'))
			s++;
		words++;
	}
	return (words);
}

int		ft_find_word_minishell(const char *s, char **arg)
{
	int		nb;
	int		len;

	nb = 0;
	len = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' ||
							*s == '\v' || *s == '\f' || *s == '\r')
		s++;
	while (*s && *s != ' ' && *s != '\n' && *s != '\t' &&
							*s != '\v' && *s != '\f' && *s != '\r' &&
							*s != '\'' && *s != '\"')
	{
		s++;
		len++;
	}
	if (*s && (*s == '\'' || *s == '\"') && len == 0)
	{
		len += ft_next_quote(s, *s);
		s += len;
	}
	return (ft_strsplit_helper(s, len, arg));
}

void	ft_strsplit_minishell(const char *s, t_args **arg)
{
	int		i;
	t_args	*tmp;

	i = 0;
	if (!(*arg = (t_args*)malloc(sizeof(t_args))))
		return ;
	tmp = *arg;
	args_set(&tmp, i);
	if (ft_find_word_minishell(s, &tmp->value))
		tmp->space = 1;
	s += ft_strsplit_advance(s);
	while (*s && (ft_strsplit_checker_minishell(s) == 1))
	{
		i++;
		if (!(tmp->next = (t_args*)malloc(sizeof(t_args))))
			return ;
		tmp = tmp->next;
		args_set(&tmp, i);
		if (ft_find_word_minishell(s, &tmp->value))
			tmp->space = 1;
		s += ft_strsplit_advance(s);
	}
	tmp->lastword = 1;
	tmp->next = NULL;
}
