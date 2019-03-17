/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:46:26 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:46:27 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, size_t len,\
			char const *s3)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if ((ret = (char*)malloc(sizeof(char)
		* ft_strlen(s1) + len + ft_strlen(s3) + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strncat(ret, s2, len);
		ft_strcat(ret, s3);
	}
	return (ret);
}
