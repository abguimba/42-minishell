/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abguimba <abguimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:47:36 by abguimba          #+#    #+#             */
/*   Updated: 2019/01/16 21:06:14 by abguimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define ANSI_COLOR_BLUE	"\x1b[36m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_DEFAULT "\x1b[0m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"

# define BUFF_SIZE 42

# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r')
# define IS_SPACE_2(x) (x == '\n' || x == '\f' || x == '\v')

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);
char				*ft_strfill(char *s, char c, size_t size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_countwordslen(char const *s, char c);
int					ft_count_words(char const *s, char c);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				*ft_memcpy(void *dst, const void *src,
								size_t n);
void				*ft_memccpy(void *dst, const void *src,
								int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2,
								size_t n);
size_t				ft_strlcat(char *dst, const char *src,
								size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
																size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_only_digit(const char *s);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnjoin(char const *s1, char const *s2, size_t len,
								char const *s3);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_free(int nb, ...);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_swap(int *a, int *b);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstbubblesort(t_list *lst, int (*cmp)(void*, void*));
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_intlen(int n);
long long			ft_abs(long long n);
char				*ft_realloc_delete(char *s, int i);
char				*ft_cpy_delete(char *s, int i);
void				ft_putstr_debug(char const *s1, char const *s2);
void				ft_putnbrendl(int n);
int					ft_first_letter_search(char *str, char c);

#endif
