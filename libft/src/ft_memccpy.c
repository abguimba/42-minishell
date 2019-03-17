/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:41:55 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:41:56 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*strdst;
	char			*strsrc;

	strdst = (char *)dst;
	strsrc = (char *)src;
	while (n > 0 && *strsrc != c)
	{
		*strdst++ = *strsrc++;
		n--;
	}
	if (n > 0)
	{
		*strdst++ = *strsrc++;
		return ((void *)strdst);
	}
	else
		return (NULL);
}
