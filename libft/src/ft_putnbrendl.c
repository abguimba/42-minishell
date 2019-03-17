/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:43:31 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:43:32 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_2(int n)
{
	if (n > 2147483647 || n < -2147483648)
		return ;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_2(n / 10);
		ft_putnbr_2(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void			ft_putnbrendl(int n)
{
	ft_putnbr_2(n);
	ft_putchar('\n');
}
