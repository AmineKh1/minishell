/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:32:28 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/10 15:40:18 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_error(char *c)
{
	write(2, "env: ", 5);
	write(2, c, ft_strlen(c));
	write(2, ": No such file or directory\n", 28);
}

void	ft_env(t_env **env, char **arg)
{
	t_env	*tmp;

	tmp = *env;
	if (!get_env_node(env, "PATH"))
	{
		write(2, "env: No such file or directory\n", 31);
		g_glb.ex = 1;
		return ;
	}
	if (arg[1])
	{
		g_glb.ex = 127;
		print_env_error(arg[1]);
		return ;
	}
	while (tmp)
	{
		if (tmp->dx == 0 || tmp->dx == 2)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	g_glb.ex = 0;
}
