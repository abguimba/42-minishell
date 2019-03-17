/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:17:17 by abguimba          #+#    #+#             */
/*   Updated: 2017/09/26 15:50:20 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_populator(char *chptr, char **line, char **str)
{
	char	*memory;

	*line = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(chptr));
	memory = *str;
	*str = ft_strsub(*str, ft_strlen(*line) + 1, ft_strlen(*str));
	ft_strdel(&memory);
	return (1);
}

static char		ft_terminator(char **line, char **str)
{
	if (ft_strlen(*str) > 0)
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t			ret;
	static char		*str = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*memory;
	char			*chptr;

	if (fd < 0 || !line)
		return (-1);
	memory = NULL;
	if ((chptr = ft_strchr(str, '\n')))
		return (ft_populator(chptr, line, &str));
	while ((ret = read(fd, buff, BUFF_SIZE)) != -1)
	{
		buff[ret] = '\0';
		if (ret == 0)
			break ;
		memory = str;
		str = ft_strjoin(str, buff);
		ft_strdel(&memory);
		if ((chptr = ft_strchr(buff, '\n')))
			return (ft_populator(chptr, line, &str));
	}
	if (ret == -1)
		return (-1);
	return (ft_terminator(line, &str));
}
