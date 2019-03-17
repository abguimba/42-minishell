/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:42:03 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:42:03 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n > 0 && *str != (unsigned char)c)
	{
		str++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else
		return (str);
}
