/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:10:48 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/22 11:22:22 by akhouya          ###   ########.fr       */
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
#include "../libft/libft.h"
#include "../printf/ft_printf.h"
# define PIPE 1
# define IN 2
# define OUT 3
# define HERDOC 4
# define HERDOCX 7
# define OUTP 5
# define STRING 6
int ex;
t_list *lexerList(t_list *lexer);
t_list *putToken(t_list *lexer);
char	*get_next_line(int fd);

char **ft_strplit(char *env);
t_env	*convert_env(char **env);
t_list *command_string(char *command, t_env *env);
char *expend_add(char *str, t_env *env);
char *valueOf$(char *str, t_env *env);
t_minishell *parser_job(t_list *lst);
void test_list_minishell(t_minishell *env);
void test_list_files(t_files *env);
void    check_herdoc(t_minishell *lst, t_env *env);
void	parcours_file(t_files *lst, t_env *env);
void	herdoc(t_files *lst, t_env *env);
char	*ft_strjoin_heredoc(char *s1, char *s2);
void test_list_t(t_list *env);
void test_list(t_env *env);
t_list *concatnate_strings(t_list *lst);
t_minishell    *parsing(char *command, t_env *env);
#endif