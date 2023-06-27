/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:56:20 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/05/25 17:31:22 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *block, size_t size);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *des, const void *src, size_t n);
void			*ft_memset(void *block, int c, size_t size);
void			*ft_memmove(void *str1, const void *str2, size_t n);

unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strchr(const char *string, int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

int				ft_tolower(int c);
int				ft_toupper(int c);

char			*ft_strdup(char *src);
void			*ft_calloc(size_t nitems, size_t size);

char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));

int				ft_printprct(void);
int				ft_printnbr(int n);
int				ft_printchar(int c);
int				ft_printstr(char *str);
int				ft_printf(const char *str, ...);
int				ft_printnbr_unsigned(unsigned int n);
int				ft_printptr(void *ptr);
int				ft_printhex(unsigned long n, const char c);
int				ft_processformat(const char c, va_list argl);

void			ft_putstr(char *str);
int				ft_putchar(char c);
int				ft_num_len(unsigned int n);
char			*ft_uitoa(unsigned int n);

char			*get_next_line(int fd);
char			*ft_strchr_gnl(const char *s, int c);
void			*ft_calloc_gnl(size_t count, size_t size);
int				ft_strlen_gnl(const char *s);
char			*ft_strjoin_gnl(char *s1, char *s2);

int				ft_abs(int n);
long int		ft_atol(const char *str);
void			ft_free_str_array(char **array);
void			ft_swap(int *a, int *b);
int				ft_strcmp(char *s1, char *s2);

#endif
