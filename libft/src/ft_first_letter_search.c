/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_letter_search.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:38:17 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:38:20 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first_letter_search(char *str, char c)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
							str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
			i++;
		if (str[i] == c)
			return (1);
	}
	return (0);
}
