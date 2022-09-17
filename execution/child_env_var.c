/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_env_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:26:42 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/07 22:50:34 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	size_env(t_env	**env)
{
	t_env	*tmp;
	int		cnt;

	if (!env)
		return (0);
	cnt = 0;
	tmp = *env;
	while (tmp)
	{
		if (tmp->dx == 2 || tmp->dx == 0)
			cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

char	**env_to_envp(t_env **env)
{
	char	**envp;
	t_env	*tmp;
	char	*fr;
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	envp = malloc(sizeof(char *) * (size_env(env) + 1));
	tmp = *env;
	while (tmp)
	{
		if (tmp->dx == 2 || tmp->dx == 0)
		{
			fr = libft_strjoin(tmp->key, "=");
			envp[i] = libft_strjoin(fr, tmp->value);
			free(fr);
			i++;
		}
		tmp = tmp->next;
	}
	envp[i] = 0;
	return (envp);
}

void	ptr_allocation(t_extra *ptr, t_env **tmp, t_env **env)
{
	t_env	*mis;

	*tmp = get_env_node(env, "PATH");
	mis = *tmp;
	ptr->envp = env_to_envp(env);
	if (mis)
	{
		ptr->path = ft_split(mis->value, ':');
		tab_slash(ptr->path);
	}
	ptr->pid = malloc(sizeof(int) * (ptr->size + 1));
}

void	slash_exec(char **arg, char **envp)
{
	struct stat	m;

	if (stat(arg[0], &m) == -1)
		return ;
	if (S_ISDIR(m.st_mode))
		command_not_found(arg, ": is a directory\n", 126);
	else if (access(arg[0], X_OK) == -1)
		command_not_found(arg, ": Permission denied\n", 126);
	execve(arg[0], arg, envp);
}
