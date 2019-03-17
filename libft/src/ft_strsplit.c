/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:46:50 by abguimba          #+#    #+#             */
/*   Updated: 2018/12/02 17:33:51 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_word(const char *s, char c, char **words, int i)
{
	int	len;
	int	spaces;

	spaces = 0;
	while (*s == c)
	{
		spaces++;
		s++;
	}
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(words[i] = (char*)malloc(sizeof(**words) * (len + 1))))
		return (0);
	if (!words[i])
		return (spaces + len);
	ft_strncpy(words[i], s, len);
	words[i][len] = '\0';
	return (spaces + len);
}

char			**ft_strsplit(const char *s, char c)
{
	int		word_count;
	char	**words;
	int		i;
	int		len;

	if (!s || !c)
		return (NULL);
	word_count = ft_count_words(s, c);
	words = (char**)malloc(sizeof(*words) * (word_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_find_word(s, c, words, i);
		s += len;
		i++;
	}
	words[word_count] = NULL;
	return (words);
}
