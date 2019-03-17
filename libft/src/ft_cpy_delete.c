/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:38:26 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:38:28 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cpy_delete(char *s, int i)
{
	int		j;
	char	*new;
	int		len;
	int		ihold;

	ihold = i;
	len = ft_strlen(s) - i;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i <= (len - ihold))
	{
		new[i] = s[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
