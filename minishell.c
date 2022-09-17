/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:01:14 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/07 22:49:53 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int sig)
{
	(void)sig;
	printf("\n");
	if (errno == EINTR)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_glb.ex = 1;
	}
	return ;
}

char	*read_line(void)
{
	char	*command;

	command = readline("Mini_chikh > ");
	if (!command)
		exit(g_glb.ex);
	return (command);
}

void	signals_handling(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &handler);
}

int	main(int argc, char **argv, char **envp)
{
	char		*command;
	t_env		*env;
	t_minishell	*list;

	(void)argv;
	signals_handling();
	env = convert_env(envp);
	if (argc != 1)
		exit(1);
	while (1)
	{
		command = read_line();
		add_history(command);
		list = parsing(command, env);
		if (list != NULL)
			execution(&list, &env);
		ft_lstclear_minishell(&list);
	}
	return (0);
}
