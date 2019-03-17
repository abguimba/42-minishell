/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:41:45 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:41:46 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*strdest;
	const char		*strsrc;

	strdest = dst;
	strsrc = src;
	while (n > 0)
	{
		*strdest++ = *strsrc++;
		n--;
	}
	return (dst);
}
