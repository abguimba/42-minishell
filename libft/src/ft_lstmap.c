/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:41:03 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:41:04 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	if (lst != NULL)
	{
		fresh = (t_list *)malloc(sizeof(f(lst)));
		if (fresh == NULL)
			return (NULL);
		fresh = f(lst);
		fresh->next = ft_lstmap(lst->next, f);
		return (fresh);
	}
	return (NULL);
}
