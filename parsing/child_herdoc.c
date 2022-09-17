/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_herdoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:45:19 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/07 22:45:32 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	child_herdoc(t_env *env, t_files *tmp, t_extra *si)
{
	signal(SIGINT, SIG_DFL);
	herdoc(tmp, env);
	write(si->tube[si->i][1], tmp->name, ft_strlen(tmp->name));
	close_back(si->tube, si->size);
	exit(0);
}

int	return_child(int ret, t_extra *si)
{
	if (ret)
	{
		g_glb.ex = 1;
		g_glb.er = 69;
		close_back(si->tube, si->size);
		return (0);
	}
	return (1);
}

int	block_herdoc(t_files *block, t_extra *si, t_env *env)
{
	t_files	*tmp;
	int		pid;
	int		status;

	tmp = block;
	while (tmp)
	{
		if (tmp->type == HERDOC || tmp->type == HERDOCX)
		{
			pid = fork();
			if (!pid)
				child_herdoc(env, tmp, si);
			waitpid(pid, &status, 0);
			if (!return_child(WIFSIGNALED(status), si))
				return (0);
			g_glb.ex = 0;
			close(si->tube[si->i][1]);
			free(tmp->name);
			tmp->name = read_fd(si->tube[si->i][0]);
			si->i++;
			tmp->type = HERDOC;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	parcours_file(t_minishell *lst, t_env *env, int size)
{
	t_extra		si;
	t_minishell	*t;

	si.i = 0;
	si.size = size;
	si.tube = alloc_tube(si.size);
	open_pipes(si.tube, si.size);
	t = lst;
	while (t)
	{
		if (!block_herdoc(t->in, &si, env))
			return (0);
		t = t->next;
	}
	close_back(si.tube, si.size);
	return (1);
}

int	herdoc_childs(t_minishell *lst)
{
	int			cnt;
	t_minishell	*tmp;
	t_files		*fl;

	tmp = lst;
	cnt = 0;
	while (tmp)
	{
		fl = tmp->in;
		while (fl)
		{
			if (fl->type == HERDOC || fl->type == HERDOCX)
				cnt++;
			fl = fl->next;
		}
		tmp = tmp->next;
	}
	return (cnt);
}
