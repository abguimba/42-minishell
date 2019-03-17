/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:47:01 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:47:02 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *biggie;
	const char *small;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		biggie = big;
		small = little;
		while (*small != '\0' && *biggie == *small)
		{
			small++;
			biggie++;
		}
		if (*small == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
