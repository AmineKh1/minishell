/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:29:33 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/07 18:46:14 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtins(char	*cmd)
{
	if (ft_cmp(cmd, "unset"))
		return (1);
	else if (ft_cmp(cmd, "export"))
		return (1);
	else if (ft_cmp(cmd, "cd"))
		return (1);
	else if (ft_cmp(cmd, "echo"))
		return (1);
	else if (ft_cmp(cmd, "pwd"))
		return (1);
	else if (ft_cmp(cmd, "exit"))
		return (1);
	else if (ft_cmp(cmd, "env"))
		return (1);
	return (0);
}

void	command_not_found(char **arg, char *mes, int ret)
{
	write(2, arg[0], ft_strlen(arg[0]));
	write(2, mes, ft_strlen(mes));
	exit(ret);
}

void	fct_exec(char **path, t_minishell	*list, t_env **env, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	if (there_is_slash(list->command[0]))
		slash_exec(list->command, envp);
	if (is_builtins(list->command[0]))
	{
		free_tab(envp);
		exec_builtins(list, env);
		exit(g_glb.ex);
	}
	else
	{
		while (get_env_node(env, "PATH") && path[i])
		{
			tmp = libft_strjoin(path[i], list->command[0]);
			if (execve(tmp, list->command, envp) == -1)
			{
				i++;
				free(tmp);
			}
		}
	}
	command_not_found(list->command, ": command not found\n", 127);
}

int	**builtins_tube(t_minishell **list, t_env **env, int size)
{
	int			**tube;
	t_minishell	*cmd;

	cmd = *list;
	if (size == 0 && cmd->command && lonely_functions(cmd))
	{
		exec_builtins(cmd, env);
		return (NULL);
	}
	tube = alloc_tube(size);
	if (!open_pipes(tube, size) || !tube)
	{
		write(2, "ERROR : open_pipe ou allocation\n", 32);
		g_glb.ex = -1;
		close_back(tube, size);
		return (NULL);
	}
	return (tube);
}
