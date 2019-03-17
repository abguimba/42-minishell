/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*cd_calc_helper(char *newpath, char *path, int place)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(newpath) + ft_cd_len_calculator_path(path, 1, place + 1);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (newpath && newpath[i] != '\0' && ft_strlen(newpath) > 1)
	{
		new[i] = newpath[i];
		i++;
	}
	new[i] = path[place];
	i++;
	place++;
	while (path[place] != '/' && path[place] != '\0')
	{
		new[i] = path[place];
		i++;
		place++;
	}
	new[i] = '\0';
	return (new);
}

char		*absolute_path_parser(char *path)
{
	char	*new;
	int		i;
	int		nb;
	int		count;

	i = 0;
	new = NULL;
	nb = 0;
	count = letter_counter(path, '/');
	i = last_apparition_char(path, '/');
	if (!(str_printable_lookup(path, i)))
		return (ft_strdup(path));
	if (!(new = (char*)malloc(sizeof(char) * ((ft_strlen(path) - 1) + 1))))
		return (NULL);
	i = -1;
	while (path[++i] != '\0')
	{
		if (path[i] == '/' && str_printable_lookup(path, i))
			break ;
		new[i] = path[i];
	}
	new[i] = '\0';
	return (new);
}

int			str_printable_lookup(char *str, int place)
{
	place++;
	while (str[place] != '\0')
	{
		if (str[place] != ' ' && str[place] != '\n' && str[place] != '\t' &&
			str[place] != '\v' && str[place] != '\f' && str[place] != '\r')
			return (0);
		place++;
	}
	if (place != 1)
		return (1);
	return (0);
}

char		*env_struct_picker(t_env **env, int nb)
{
	char	*new;
	t_env	*tmp;

	tmp = *env;
	while (nb > 0)
	{
		tmp = tmp->next;
		nb--;
	}
	nb = ft_strlen(tmp->value) + ft_strlen(tmp->key) + 1;
	if (!(new = malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	env_struct_picker_2(new, tmp);
	return (new);
}

int			env_struct_len(t_env **env)
{
	t_env	*tmp;
	int		i;

	tmp = *env;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
