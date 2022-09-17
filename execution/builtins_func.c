/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:38:10 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/10 15:39:53 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	input_builtins(t_files *in)
{
	t_files	*tmp;

	tmp = in;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->type == IN && access(tmp->name, R_OK) == -1)
		{
			perror("ERROR");
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	duplicate_fd(int *ret, int fd)
{
	*ret = dup(1);
	dup2(fd, 1);
	close(fd);
}

int	output_builtins(t_files *out)
{
	t_files	*tmp;
	int		fd;
	int		ret;

	ret = 0;
	tmp = out;
	if (!tmp)
		return (-2);
	while (tmp)
	{
		if ((tmp->type == OUT || tmp->type == OUTP) && out_fd_assign(tmp, &fd))
		{
			if (tmp->next)
				close(fd);
			else
				duplicate_fd(&ret, fd);
		}
		else
			return (-1);
		tmp = tmp->next;
	}
	return (ret);
}

int	open_files(int *fd, t_minishell *list)
{
	if (!input_builtins(list->in))
	{
		g_glb.ex = 1;
		return (0);
	}
	*fd = output_builtins(list->out);
	if (*fd == -1)
	{
		g_glb.ex = 1;
		return (0);
	}
	return (1);
}

void	exec_builtins(t_minishell *list, t_env **env)
{
	int	fd;

	if (!open_files(&fd, list))
		return ;
	if (ft_cmp(list->command[0], "unset"))
		ft_unset(env, list->command);
	else if (ft_cmp(list->command[0], "export"))
		ft_export(env, list->command);
	else if (ft_cmp(list->command[0], "cd"))
		ft_cd(env, list->command);
	else if (ft_cmp(list->command[0], "echo"))
		ft_echo(list->command);
	else if (ft_cmp(list->command[0], "pwd"))
		ft_pwd(*env);
	else if (ft_cmp(list->command[0], "exit"))
		ft_exit(list->command);
	else if (ft_cmp(list->command[0], "env"))
		ft_env(env, list->command);
	if (fd != -2)
	{
		dup2(fd, 1);
		close(fd);
	}
}
