/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:01:14 by akhouya           #+#    #+#             */
/*   Updated: 2022/07/23 14:14:09 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **command_string(char *command)
{
	char	**s;
	int i;
	int j;
	char c;
	int count;

	
	// s = ft_split(command, ' ');
	// while
	s =NULL;
	i = 0;
	j = 0;
	count = 0;
	while (command[i])
	{
		if (command[i] == '\''  || command[i] == '"')
		{
			j = i + 1;
			c = command[i];
			while (command[i]  != c && command[i])
				i++;
			// printf("%c\n", command[i]);
			if (!command[i])
				exit(1);
			if(command[i + 1] == ' ' || !command[i + 1])
				count++;
		}
		else if (command[i] == ' ' || i == 0)
		{
			j = i + 1;
			while (command[i]  != ' ' && command[i] && command[i] != '\'' && command[i] != '"')
				i++;
			// {
			// 	if (command[i] == '\'' || command[i] == '"')
			// 	{
			// 		c = command[i];
			// 		while (command[++i]  != c && command[i]);
			// 		if (!command[i])
			// 			exit(1);
			// 	}
			// }
			if (command[i] == ' ' || !command[i])
				count++;
		}
		i++;
	}
	s = malloc(sizeof(char*) * (count + 1));
	s[count] = 0;
	count = 0;
	i = -1;
	j = 0;
	while (command[i])
	{
		if (command[i] == '\''  || command[i] == '"')
		{
			j = i + 1;
			c = command[i];
			while (command[i]  != c && command[i])
				i++;
			// if (!command[i])
			// 	exit(1);
			if(command[i + 1] == ' ' || !command[i + 1])
				s[count++] = ft_substr(&command[j],0, i - j);
		}
		else if (command[i] == ' ' || i == 0)
		{
			j = i + 1;
			if (i == 0)
				j--;
			// while (command[++i]  != ' ' && command[i])
			// {
			// 	if (command[i] == '\'' || command[i] == '"')
			// 	{
			// 		c = command[i];
			// 		while (command[++i]  != c && command[i]);
			// 		if (!command[i])
			// 			exit(1);
			// 	}
			// }
			while (command[i]  != ' ' && command[i] && command[i] != '\'' && command[i] != '"')
				i++;
			if (command[i] == ' ' || !command[i])
				s[count++] = ft_substr(&command[j], 0, i - j);
			// printf("%d\n", i);
		}
		i++;
	}
	printf("%d\n", count);
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