/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:29:17 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/04 10:46:16 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	test_list(t_env *env)
{
	while (env)
	{
		printf("key: %s, value: %s\n", env->key, env->value);
		env = env->next;
	}
}

void	test_list_t(t_list *env)
{
	while (env)
	{
		printf("string: %s, value: %d\n", env->content, env->type);
		env = env->next;
	}
}

void	test_list_file(t_files *env)
{
	if (!env)
	{
		printf("walo\n");
	}
	while (env)
	{
		printf("	file: %s, value: %d\n", env->name, env->type);
		env = env->next;
	}
}

void	test_list_minishell(t_minishell *env)
{
	int	i;

	i = 0;
	while (env)
	{
		printf("commands: ");
		i = 0;
		if (env->command != NULL)
		{
			while (env->command[i])
				printf("%s, ", env->command[i++]);
		}
		printf("\nfiles in:\n");
		test_list_file(env->in);
		printf("\nfiles out:\n");
		test_list_file(env->out);
		printf("\n---PIPE---\n");
		env = env->next;
	}
}
