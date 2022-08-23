/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:01:14 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/23 10:15:44 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int argc, char **argv, char **envp)
{
	char 	*command;
	t_list *s;
	t_env *env;
	t_minishell *list;

	argv = NULL;
	command = NULL;
	ex = 0;
	env = convert_env(envp);
	s = NULL;
	if (argc != 1)
		exit(1);
	while(1)
	{
		command = readline("minishell > ");
		add_history(command);
		list = parsing(command, env);
		if (list == NULL)
			continue ;
		// system("leaks minishell");
		
		
	}
}

