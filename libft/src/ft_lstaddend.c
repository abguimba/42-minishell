/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:40:17 by abguimba          #+#    #+#             */
/*   Updated: 2018/10/31 12:40:18 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstaddend(t_list **alst, t_list *new)
{
	if ((*alst)->next != NULL)
		ft_lstaddend(&(*alst)->next, new);
	else
	{
		(*alst)->next = new;
	}
}
