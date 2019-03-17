/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:44:47 by abguimba          #+#    #+#             */
/*   Updated: 2018/12/02 17:37:20 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s2;

	if (s1)
	{
		len = ft_strlen(s1);
		s2 = (char *)malloc(sizeof(char) * len + 1);
		if (s2 == NULL)
			return (NULL);
		i = 0;
		while (len > 0)
		{
			s2[i] = s1[i];
			i++;
			len--;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
