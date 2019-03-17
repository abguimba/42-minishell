/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2018/11/21 09:40:07 by abe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		get_input(char **input)
{
	int		ret;
	char	buf;
	int		i;
	int		count;

	*input = ft_strnew(1);
	count = 1;
	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc(*input, count, count + 1);
		count++;
	}
	*(*input + i) = '\0';
	if (!ret)
		free(*input);
}

void		command_commander(t_args *arg, t_env *env, char *line)
{
	t_com	*com;
	int		i;

	while (42)
	{
		i = 0;
		signal(SIGINT, sig_int_handler);
		print_prompt_pwd();
		get_input(&line);
		com_format(&com, line);
		while (checking_if_coms(&com, i))
		{
			line = com_to_line(line, &com, i);
			line_format(line, &env, &arg);
			if (arg)
				boe(line, &env, &arg, &com);
			ft_strdel(&line);
			free_args(&arg);
			i++;
		}
		free_com(&com);
	}
}

int			main(int ac, char **av, char **envp)
{
	t_env	*env;
	t_args	*arg;
	char	*line;

	(void)ac;
	if (write(0, av[0], 0) == -1)
		stdin_error();
	env = NULL;
	arg = NULL;
	line = NULL;
	if (envp[0])
		env_format(envp, &env);
	command_commander(arg, env, line);
	if (env)
		free_env(&env);
	return (0);
}
