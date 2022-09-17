/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:34:53 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/07 18:42:19 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_herdoc(t_minishell *lst, t_env *env)
{
	int	size;

	size = herdoc_childs(lst);
	if (size > 16)
	{
		write(2, "maximum here-document count exceeded\n", 37);
		exit(2);
	}
	if (!parcours_file(lst, env, size))
		return (0);
	return (1);
}

t_minishell	*parsing(char *command, t_env *env)
{
	t_list		*s;
	t_minishell	*list;

	s = command_string(command, env);
	free(command);
	if (!s)
		return (NULL);
	s = concatnate_strings(s);
	s = lexer_list(s);
	if (!s)
		return (NULL);
	list = parser_job(s);
	ft_lstclear(&s);
	if (!check_herdoc(list, env))
	{
		ft_lstclear_minishell(&list);
		return (NULL);
	}
	return (list);
}
