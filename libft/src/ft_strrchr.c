/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:46:41 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:46:42 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_oc;

	last_oc = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_oc = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (last_oc);
}
