/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:01:14 by akhouya           #+#    #+#             */
/*   Updated: 2022/07/22 17:57:57 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char **command_string(char *command)
{
	char	**s;
	int i;
	
	s = ft_split(command, ' ');
	i = -1;
	return s;
}

int main(int argc, char **argv)
{
    char    *command;
	char	**s;
	int i;
    if(argc != 1)
        exit(1);

    while(1)
    {
		command = readline("minishell > ");
        printf("%s\n", command);
		
		s = command_string(command);
		i = -1;
		while(s[++i] != 0)
			printf("%s\n", s[i]);
		frealltab(s);
		free(s);
		free(command);
    }
}