/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:40:22 by abguimba          #+#    #+#             */
/*   Updated: 2019/01/16 21:05:14 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"

typedef struct		s_com
{
	char			*line;
	int				place;
	int				last;
	struct s_com	*next;
}					t_com;

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_args
{
	char			*value;
	int				place;
	int				space;
	int				lastword;
	struct s_args	*next;
}					t_args;

/*
** MAIN.C
*/

void				get_input(char **input);
void				command_commander(t_args *arg, t_env *env, char *line);

/*
** COMMANDS_PARSER.c
*/

void				com_format(t_com **com, char *line);
void				one_command(t_com **com, char *line, t_com *new);
void				more_commands(t_com **com, char *line, int place);
void				more_commands_help(t_com **com, char *line);
int					checking_if_coms(t_com **com, int place);

/*
** FT_STRSPLIT_MINISHELL.C
*/

void				ft_strsplit_minishell(const char *s, t_args **arg);
int					ft_count_words_minishell(const char *s);
int					ft_strsplit_checker_minishell(const char *s);
int					ft_find_word_minishell(const char *s, char **args);
int					ft_strsplit_advance(const char *s);

/*
** SETENV.C
*/

void				ft_setenv(t_args **arg, t_env **env);
int					setenv_arg_len(char *arg);
void				setenv_check(char *key, char *value, t_env **env);
int					setenv_adding_check(char *key, char *value, int i, int j);
char				*setenv_add_to_existing(char *newvalue, char *value);

/*
** SETENV_2.C
*/

t_env				*setenv_new(char *key, char *value);
char				*setenv_exists(char *value);

/*
** UNSETENV.C
*/

void				ft_unsetenv(t_args **arg, t_env **env);
void				unsetenv_del(char *key, t_env **env);
void				unsetenv_del_first(t_env **env);

/*
** ERRORS.C
*/

void				stdin_error();
void				setenv_args_error();
void				unsetenv_not_found(char *s);
void				quotes_error();
void				cd_args_error();

/*
** ERRORS_2.C
*/

void				cd_rights_error(int mode, char *path);
void				exec_fork_error(void);
void				exec_command_not_found(char	*command);
void				exec_error_open_dir(char *dir);
void				cd_rights_error_2(int mode, char *path);

/*
** ERRORS_3.C
*/

void				error_exec_this_is_dir(char *path);

/*
** CD.C
*/

void				ft_cd(t_args **arg, t_env **env);
int					ft_cd_rights_checker(char *path);
void				ft_cd_env_path_modif(char *path, t_env **env);
void				ft_cd_go_home(t_env **env);
char				*ft_cd_path_parser(char *path, t_env **env);

/*
** CD_2.C
*/

void				ft_cd_go_oldpwd(char *path, t_env **env);
char				*ft_cd_path_parser_alloc(char *path);
int					ft_cd_previous_path_count(char *path, int place);
char				*ft_cd_backward_path(char *newpath, char *path, int place);
int					ft_cd_len_calculator_path(char *path, int mode, int place);

/*
** ENV.C
*/

void				ft_env(t_env **env);

/*
** EXIT.C
*/

void				ft_exit(char *line, t_args **arg, t_env **env, t_com **com);
void				ft_exit_extra(t_args **arg, t_com **com);
void				ft_exit_extra_2(t_com **com);

/*
** ECHO.C
*/

void				ft_echo(t_args **arg);

/*
** EXEC.C
*/

int					get_exec(char *line, char **tab);
int					find_exec(char **tab, t_env **env, int i, int mode);
void				ft_pid_high_than_zero(int pid, int status);
void				ft_exec(t_args **arg, t_env **env);
void				ft_exec_norme(char **tab, t_env **env, int mode, int mode2);

/*
** EXEC_2.C
*/

int					ft_exec_is_path_check(char **tab);
void				ft_exec_part_2(t_args **arg, t_env **env, char **tab);
void				ft_exec_part_3(t_args **arg, t_env **env, char **tab);
void				ft_exec_part_4(t_args **arg, t_env **env, char **tab);

/*
** BOE.C
*/

void				boe(char *line, t_env **env, t_args **argt, t_com **com);

/*
** BUILTIN_SEARCHERS.C
*/

int					ft_echo_search(t_args **arg);
int					ft_exit_search(t_args **arg);
int					ft_env_search(t_args **arg);
int					ft_setenv_search(t_args **arg);
int					ft_unsetenv_search(t_args **arg);

/*
** BUILTIN_SEARCHERS_2.C
*/

int					ft_cd_search(t_args **arg);

/*
** LINE_FORMATTER.C
*/

void				line_format(char *line, t_env **env, t_args **arg);
void				env_var_tab(t_args **arg, t_env **env);
void				env_home_tab(t_args **arg, t_env **env);

/*
** LINE_FORMATTER_2.C
*/

char				*env_home_tab_change(char *s, t_env **env);
char				*env_home_tab_change_2(char *s, char *value);
char				*env_var_tab_change_2(char *s, char *value, int longeur);
void				env_var_tab_change_3(char *s, char *new, char *me, int len);

/*
** CREATE_ENV.C
*/

void				env_format(char **envp, t_env **env);
void				env_alloc(char **envp, t_env **env, int i, t_env *tmp);
void				env_alloc_key(char *envp, char **key);
void				env_alloc_value(char *envp, char **value);

/*
** SIGNAL_HANDLERS.C
*/

void				sig_int_handler(int signo);

/*
** UTILS.C
*/

void				print_env_list(t_env **env);
void				free_tab(char **tab);
void				print_tab(char **tab);
void				tab_to_line(char **tab, char **line);
char				*tab_to_line_2(char *newline, char **tab);

/*
** UTILS_2.c
*/

int					search_double_quotes(char *s);
int					search_single_quotes(char *s);
void				ft_clean_one_tab(char *s, char ***tab);
int					tab_len(char **tab);
char				*no_quotes_line(char *s);

/*
** UTILS_3.c
*/

void				print_args(t_args **arg);
void				free_args(t_args **arg);
int					ft_next_quote(const char *s, char c);
void				args_set(t_args **arg, int place);
char				*ft_clean_one_list(char *clean, char *arg, t_args **args);

/*
** UTILS_4.c
*/

void				last_one_list_checker(t_args **arg);
int					args_len(t_args **arg);
char				*args_picker(t_args **arg, int nb);
int					args_checker(t_args **arg, int nb);
char				*relative_path_maker(char *path, char *pwd);

/*
** UTILS_5.c
*/

char				*env_home_search(t_env **env);
int					single_dot_path_checker(char *path, int place);
int					double_dot_path_checker(char *path, int place);
int					double_dot_path_counter(char *path);
int					single_dot_path_counter(char *path);

/*
** UTILS_6.c
*/

char				**args_to_tab(t_args **arg);
int					letter_counter(char *str, char c);
char				*realloc_str(char *str, char *newstr);
char				*join_char(char *str, char *str2, char c);
char				**envlist_to_tab(t_env **env);

/*
** UTILS_7.c
*/

int					env_struct_len(t_env **env);
char				*env_struct_picker(t_env **env, int nb);
int					str_printable_lookup(char *str, int place);
char				*absolute_path_parser(char *path);
char				*cd_calc_helper(char *newpath, char *path, int place);

/*
** UTILS_8.c
*/

int					ft_strsplit_helper(const char *s, int len, char **arg);
char				*line_format_help(char *tmp, int place, int i, int len);
void				clean_one_tab_help(char **newtab, char **tmp, int i, int j);
int					args_checker_equal_help(char c);
int					args_checker_different_help(char c, int mode);

/*
** UTILS_9.c
*/

int					last_apparition_char(char *str, char c);
char				*single_dot_path_maker(char *newpath);
void				env_struct_picker_2(char *new, t_env *tmp);
void				ft_clean_one_list_2(char *arg, char *new, char *clean);
void				print_prompt_pwd();

/*
** UTILS_10.c
*/

int					existence_check(char *path, int mode);
int					dir_check(char *path, int mode);
int					execute_check(char *path, int mode);
void				arg_extra_cd(t_args **arg);
int					is_this_a_space(char *str, int place);

/*
** UTILS_11.c
*/

int					setenv_add_len_calc(char *newvalue);
int					is_setenv_add(t_env **env, t_args **arg, char *k, char *v);
void				free_com(t_com **com);
int					len_command(char *line, int nb);
void				last_one_com_maker(t_com **com);

/*
** UTILS_12.c
*/

char				*command_filler(char *line, int place);
int					com_len(t_com **com);
char				*com_to_line(char *line, t_com **com, int place);
void				print_com(t_com **com);
void				exec_mode_helper(char *path, int mode);

/*
** UTILS_13.c
*/

void				free_env(t_env **env);
void				print_user_prompt(t_env **env);

/*
** FT_STRJOIN_MINISHELL.c
*/

char				*ft_strjoin_minishell(char const *s1, char const *s2);

#endif
