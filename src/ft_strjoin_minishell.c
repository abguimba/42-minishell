/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:45:12 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:45:13 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_minishell(char const *s1, char const *s2)
{
	char		*s;

	if (!s1 && s2)
		return ((char*)s2);
	else if (s1 && s2 && (s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		free((void*)(s1));
		return (ft_strcat(ft_strcpy(s, s1), (char*)s2));
	}
	return (NULL);
}
