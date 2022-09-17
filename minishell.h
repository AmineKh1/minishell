/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:00:06 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/10 15:37:42 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "parsing/parsing.h"
# include <signal.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

void	execution(t_minishell **list, t_env **env);
void	ft_echo(char **arg);
void	ft_pwd(t_env *env);
void	ft_env(t_env **env, char **arg);
void	ft_unset(t_env **env, char **unset);
void	ft_export(t_env **env, char **exp);
void	ft_cd(t_env **env, char **arg);
void	ft_exit(char **cmd);
t_env	*env_new(void);
void	env_add_back(t_env **alst, t_env *new);
t_env	*env_last(t_env *lst);
int		env_lstsize(t_env *lst);
void	env_clear(t_env *lst);
void	env_del(t_env *lst);
void	free_env(t_env *node);
int		**alloc_tube(int size);
int		open_pipes(int **tube, int size);
int		close_back(int **tube, int pos);
char	*libft_strjoin(char const *s1, char const *s2);
void	handler(int sig);
int		ft_strlen_tab(char **c);
void	change_env_value(t_env **env, char *exp, int index);
int		check_env_value(t_env *env, char *exp, int index);
int		condition_name(char *c);
void	export_error(char *exp);
int		ft_strcmp(char *s1, char *s2);
void	export_equal(t_env **env, char *exp, int index);
void	export_no_equal(t_env **env, char *exp);
int		check_existance(t_env **env, char *exp);
int		t_env_size(t_env *env);
void	ptr_allocation(t_extra *ptr, t_env **tmp, t_env **env);
void	fct_exec(char **path, t_minishell *list, t_env **env, char **envp);
int		**builtins_tube(t_minishell **list, t_env **env, int size);
void	tab_slash(char **path);
int		there_is_slash(char *arg);
void	free_tab(char **tab);
void	input_commande(t_files *in, t_extra ptr, char **cmd);
void	output_commande(t_files *out, t_extra ptr);
int		lonely_functions(t_minishell *cmd);
char	*read_fd(int fd);
char	*ft_strjoin_heredoc(char *s1, char *s2);
void	slash_exec(char **arg, char **envp);
void	command_not_found(char **arg, char *mes, int ret);
void	condition_dup(t_extra ptr);
int		out_fd_assign(t_files *tmp, int	*fd);
void	exec_builtins(t_minishell *list, t_env **env);
int		output_builtins(t_files *out);
int		input_builtins(t_files *in);
int		lord_save_me(void);
int		ft_strlen_export(t_export *p);

#endif
