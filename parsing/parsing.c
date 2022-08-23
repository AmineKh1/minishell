/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:34:53 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/22 13:01:52 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_minishell    *parsing(char *command, t_env *env)
{
    t_list *s;
    t_minishell *list;
    
    s = command_string(command, env);
		free(command);
		if (ex != 0)
			return NULL;
		s = concatnate_strings(s);
		s = lexerList(s);
		if (ex != 0)
			return NULL;
		// test_list_t(s);
		list = parser_job(s);
		ft_lstclear(&s);
		check_herdoc(list, env);
		test_list_minishell(list);
		ft_lstclear_minishell(&list);
		s = NULL;
		list = NULL;
        return list;
}