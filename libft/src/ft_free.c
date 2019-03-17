/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:43:51 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/02 17:43:52 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(int nb, ...)
{
	va_list	ap;
	void	**tmp;

	va_start(ap, nb);
	while (nb--)
	{
		if ((tmp = va_arg(ap, void **)))
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	va_end(ap);
}
