/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:45:19 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:45:20 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*source;
	size_t		n;
	size_t		dlen;

	dest = dst;
	source = src;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	dlen = dest - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(source));
	while (*source != '\0')
	{
		if (n != 1)
		{
			*dest++ = *source;
			n--;
		}
		source++;
	}
	*dest = '\0';
	return (dlen + (source - src));
}
