/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:05:52 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/11 16:16:43 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_size_list(t_minishell *list)
{
	int			cnt;
	t_minishell	*tmp;

	tmp = list;
	cnt = 0;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

void	tab_slash(char **path)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = path[i];
		path[i] = libft_strjoin(path[i], "/");
		free(tmp);
		i++;
	}
}

void	child_work(t_minishell	*cmd, t_env **env, t_extra ptr)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	input_commande(cmd->in, ptr, cmd->command);
	output_commande(cmd->out, ptr);
	close_back(ptr.tube, ptr.size);
	if (cmd->command)
		fct_exec(ptr.path, cmd, env, ptr.envp);
	else
		exit (0);
}

void	clean_and_wait(t_extra ptr)
{
	int	i;
	int	status;

	free_tab(ptr.path);
	free_tab(ptr.envp);
	close_back(ptr.tube, ptr.size);
	i = 0;
	while (i <= ptr.size)
	{
		waitpid(ptr.pid[i], &status, 0);
		if (WIFSIGNALED(status))
			g_glb.ex = 128 + WTERMSIG(status);
		else
			g_glb.ex = WEXITSTATUS(status);
		i++;
	}
	free(ptr.pid);
}

void	execution(t_minishell **list, t_env **env)
{
	t_extra		ptr;
	t_minishell	*cmd;
	t_env		*tmp;

	cmd = *list;
	ptr.i = 0;
	ptr.size = ft_size_list(*list) - 1;
	ptr.tube = builtins_tube(list, env, ptr.size);
	if (!ptr.tube)
		return ;
	ptr_allocation(&ptr, &tmp, env);
	while (ptr.i <= ptr.size)
	{
		ptr.pid[ptr.i] = fork();
		if (!ptr.pid[ptr.i])
			child_work(cmd, env, ptr);
		ptr.i++;
		cmd = cmd->next;
	}
	clean_and_wait(ptr);
}
