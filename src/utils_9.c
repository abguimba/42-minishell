/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_prompt_pwd(void)
{
	char	*cwd;
	char	buff[4096 + 1];

	ft_putchar('\n');
	cwd = getcwd(buff, 4096);
	ft_putstr(ANSI_COLOR_BLUE);
	ft_putstr(cwd);
	ft_putchar(' ');
	ft_putstr(ANSI_COLOR_DEFAULT);
	ft_putstr(ANSI_COLOR_GREEN "$/> " ANSI_COLOR_DEFAULT);
}

void		ft_clean_one_list_2(char *arg, char *new, char *clean)
{
	while (*arg)
	{
		if (*arg == '$')
			arg += ft_strlen(clean) + 1;
		*new = *arg;
		new++;
		arg++;
	}
	*new = '\0';
}

void		env_struct_picker_2(char *new, t_env *tmp)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (tmp->key[i] != '\0')
	{
		new[nb] = tmp->key[i];
		nb++;
		i++;
	}
	new[nb] = '=';
	nb++;
	i = 0;
	while (tmp->value[i] != '\0')
	{
		new[nb] = tmp->value[i];
		nb++;
		i++;
	}
	new[nb] = '\0';
}

char		*single_dot_path_maker(char *newpath)
{
	int		len;

	if ((len = last_apparition_char(newpath, '/')) == 0)
		return (ft_strdup("/"));
	return (ft_strdup(newpath));
}

int			last_apparition_char(char *str, char c)
{
	int		i;
	int		hold;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				hold = i;
			i++;
		}
		if (hold == 0)
			return (1);
		return (hold);
	}
	return (0);
}
