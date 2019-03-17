/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:39:57 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:39:59 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_length(int value)
{
	int		len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0)
		len += 1;
	while (value)
	{
		value /= 10;
		len++;
	}
	return (len);
}

static char		*ft_inttochar(int value)
{
	int		neg;
	int		len;
	char	*nbr;

	neg = 0;
	len = get_length(value);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (value < 0)
	{
		neg = 1;
		value *= -1;
	}
	while (--len)
	{
		nbr[len] = value % 10 + '0';
		value /= 10;
	}
	if (neg)
		nbr[len] = '-';
	else
		nbr[len] = value % 10 + '0';
	return (nbr);
}

char			*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (ft_inttochar(n));
}
