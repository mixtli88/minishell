/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:10:25 by fwu               #+#    #+#             */
/*   Updated: 2024/12/30 15:54:27 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_ilist
{
	int				content;
	struct s_ilist	*next;
}	t_ilist;

# define INT_MAX_STR "2147483647"
# define INT_MIN_STR "-2147483648"

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
bool 	ft_isaspace(char c);
bool	ft_isint(char *str);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	**ft_split(char const *str, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(void *content);
t_ilist	*ft_ilstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_ilstadd_front(t_ilist **lst, t_ilist *new);
int		ft_lstsize(t_list *lst);
int		ft_ilstsize(t_ilist *lst);
t_list	*ft_lstlast(t_list *lst);
t_ilist	*ft_ilstlast(t_ilist *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_ilstadd_back(t_ilist **lst, t_ilist *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_ilstdelone(t_ilist *lst, void (*del)(int));
void	ft_lstrm_last(t_list **lst, void (*del)(void*));
void	ft_ilstrm_last(t_ilist **lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_ilstclear(t_ilist **lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_ilstiter(t_ilist *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// funcion mike para minishell
char *ft_strcat(char **dest, const char *src);
bool ft_isaspace(char c);
#endif // LIBFT_H