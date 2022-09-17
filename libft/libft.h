/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:22:30 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/15 18:24:39 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# define PIPE 1
# define IN 2
# define OUT 3
# define HERDOC 4
# define OUTP 5
# define STRING 6

typedef struct s_list
{
	char			*content;
	int				type;
	struct s_list	*next;
}	t_list;

typedef struct s_env {
	char			*key;
	char			*value;
	int				dx;
	struct s_env	*next;
}	t_env;

typedef struct s_files {
	char			*name;
	int				type;
	struct s_files	*next;
}	t_files;

typedef struct s_minishell {
	char				**command;
	t_files				*in;
	t_files				*out;
	struct s_minishell	*next;
}	t_minishell;

typedef struct t_extra
{
	int		i;
	int		size;
	int		*pid;
	int		**tube;
	char	**path;
	char	**envp;
}	t_extra;

int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strrchr(char *s, int c);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(char *s, int c);
void		*ft_memset(void *buf, int ch, size_t count);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
void		*ft_calloc(size_t nmemb, size_t size);
void		frealltab(char **str);
void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(char *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *));
t_env		*ft_lstnew_env(char *key, char *value);
void		ft_lstadd_front_env(t_env **lst, t_env *new);
void		ft_lstadd_back_env(t_env **lst, t_env *new);
t_env		*ft_lstlast_env(t_env *lst);
t_files		*ft_lstlast_files(t_files *lst);
void		ft_lstadd_back_files(t_files **lst, t_files *new);
t_minishell	*ft_lstlast_minishell(t_minishell *lst);
t_minishell	*ft_lstnew_minishell(char **command, t_files *in, t_files *out);
t_files		*ft_lstnew_file(char *name, int type);
void		ft_lstadd_front_minishell(t_minishell **lst, t_minishell *new);
void		ft_lstadd_back_minishell(t_minishell **lst, t_minishell *new);
void		ft_lstadd_front_files(t_files **lst, t_files *new);
void		ft_lstdelone_minishell(t_minishell *lst);
void		ft_lstdelone_files(t_files *lst);
void		ft_lstclear_minishell(t_minishell **lst);
void		ft_lstclear_files(t_files **lst);
#endif