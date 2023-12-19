/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:34:27 by yuske             #+#    #+#             */
/*   Updated: 2023/04/07 03:17:49 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//atoi(), itoa(), putnbr_fd()
# define POSITIVE (1)
# define NEGATIVE (-1)

# include <unistd.h>//write()
# include <stdio.h>//NULL
# include <stdlib.h>//malloc(), free()
# include <string.h>//size_t
# include <limits.h>//LONG_MIN, LONG_MAX, SIZE_MAX

//1. ctype
int		ft_isascii(int chr);
int		ft_isprint(int chr);
int		ft_isdigit(int chr);
int		ft_isalpha(int chr);
int		ft_isalnum(int chr);
int		ft_toupper(int chr);
int		ft_tolower(int chr);

//utils: additional
int		ft_isupper(int chr);
int		ft_islower(int chr);
int		ft_isspace(int chr);
char	*ft_strndup(const char *str, size_t n);

//8.
size_t	ft_strlen(const char *str);
void	*ft_memset(void *mem, int chr, size_t n_set);
void	ft_bzero(void *mem, size_t n_zero);

//11.
void	*ft_memcpy(void *dst, const void *src, size_t n_cpy);
void	*ft_memmove(void *dst, const void *src, size_t n_move);
void	*ft_memchr(const void *mem, int chr, size_t n_chk);
int		ft_memcmp(const void *mem1, const void *mem2, size_t n_cmp);

//15.
size_t	ft_strlcpy(char *dst, const char *src, size_t l_cpy);
size_t	ft_strlcat(char *dst, const char *src, size_t l_cat);
char	*ft_strchr(const char *str, int chr);
char	*ft_strrchr(const char *str, int chr);
char	*ft_strnstr(const char *str_l, const char *str_s, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n_cmp);

//21.
int		ft_atoi(const char *from_ascii);
void	*ft_calloc(size_t nbr, size_t size);
char	*ft_strdup(const char *str);
char	*ft_itoa(int from_integer);

//25.
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str, char const *trimmers);
char	**ft_split(char const *str, char splitter);

//29
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);

//33.
void	ft_striteri(char *str, void (*fnc)(unsigned int, char*));
char	*ft_strmapi(char const *str, char (*fnc)(unsigned int, char));

//bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *stuff);
t_list	*ft_lstlast(t_list *node);
int		ft_lstsize(t_list *node);
void	ft_lstadd_front(t_list **node, t_list *new_node);
void	ft_lstadd_back(t_list **node, t_list *new_node);
void	ft_lstdelone(t_list *node, void (*f_del)(void*));
void	ft_lstclear(t_list **node, void (*f_del)(void*));
void	ft_lstiter(t_list *node, void (*f_proc)(void *));
t_list	*ft_lstmap(t_list *node, void *(*f_proc)(void*), void (*f_del)(void*));
//43 functions

#endif