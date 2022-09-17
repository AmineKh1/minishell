/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:10:48 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/05 09:47:02 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# define PIPE 1
# define IN 2
# define OUT 3
# define HERDOC 4
# define HERDOCX 7
# define OUTP 5
# define STRING 6
# define ERROR_NEWLINE "minishell: syntax error near unexpected token`newline"
# define ERROR_TOKEN "minishell: syntax error near unexpected token`"

typedef struct ex_er
{
	int	ex;
	int	er;
}	t_exer;

typedef struct s_quote{
	t_list	*tmp;
	t_list	*list_cmd;
	char	*str;
	char	**ss;
	int		i;
	int		j;
	char	c;
	int		icr;
}	t_quote;

typedef struct s_parser
{
	t_minishell	*list;
	t_minishell	*tmpm;
	char		**command;
	t_files		*in;
	t_files		*out;
	t_files		*tmpf;
}	t_parser;

typedef struct s_expend{
	char	*s1;
	char	*ret;
	int		i;
	int		j;
}	t_expend;

typedef struct s_export{
	char	*exp;
	int		dx;
}	t_export;

t_exer	g_glb;

void		exit_code(char *str, t_expend *x);
void		expend_number(char *str, t_expend *x, t_env *env);
void		expend_envp(char *str, t_expend *x, t_env *env);
char		*value_ofd(char *str, t_env *env);
int			is_endd(char c);
t_list		*lexer_list(t_list *lexer);
t_list		*put_token(t_list *lexer);
char		**ft_strplit(char *env);
t_env		*convert_env(char **env);
t_list		*command_string(char *command, t_env *env);
char		*expend_add(char *str, t_env *env);
t_minishell	*parser_job(t_list *lst);
void		test_list_minishell(t_minishell *env);
void		test_list_files(t_files *env);
int			check_herdoc(t_minishell *lst, t_env *env);
void		herdoc(t_files *lst, t_env *env);
char		*ft_strjoin_heredoc(char *s1, char *s2);
void		test_list_t(t_list *env);
void		test_list(t_env *env);
t_list		*concatnate_strings(t_list *lst);
t_minishell	*parsing(char *command, t_env *env);
t_env		*get_env_node(t_env **env, char *key);
int			is_space(char c);
void		init_value(t_quote *q);
int			ft_cmp(const char *s1, char *s2);
void		handler_herdoc(int sign);
int			parcours_file(t_minishell *lst, t_env *env, int size);
void		herdoc(t_files *lst, t_env *env);
int			herdoc_childs(t_minishell *lst);

#endif
