/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:42:18 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:42:18 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1tr;
	unsigned char *s2tr;

	s1tr = (unsigned char *)s1;
	s2tr = (unsigned char *)s2;
	while (n > 0 && *s1tr == *s2tr)
	{
		s1tr++;
		s2tr++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*s1tr - *s2tr);
}
