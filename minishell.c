/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:01:14 by akhouya           #+#    #+#             */
/*   Updated: 2022/07/23 23:43:44 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **command_string(char *command)
{
	char	**s;
	char *str;
	int i;
	int j;
	char c;
	int count;
	t_list *list_command;
	t_list *tmp;

	
	// s = ft_split(command, ' ');
	// while
	s = NULL;
	list_command = NULL;
	i = 0;
	j = 0;
	count = 0;
	// while (command[i])
	// {
	// 	if (command[i] == '\''  || command[i] == '"')
	// 	{
	// 		j = i + 1;
	// 		c = command[i];
	// 		while (command[i]  != c && command[i])
	// 			i++;
	// 		// printf("%c\n", command[i]);
	// 		if (!command[i])
	// 			exit(1);
	// 		if(command[i + 1] == ' ' || !command[i + 1])
	// 			count++;
	// 	}
	// 	else if (command[i] == ' ' || i == 0)
	// 	{
	// 		j = i + 1;
	// 		while (command[i]  != ' ' && command[i] && command[i] != '\'' && command[i] != '"')
	// 			i++;
	// 		// {
	// 		// 	if (command[i] == '\'' || command[i] == '"')
	// 		// 	{
	// 		// 		c = command[i];
	// 		// 		while (command[++i]  != c && command[i]);
	// 		// 		if (!command[i])
	// 		// 			exit(1);
	// 		// 	}
	// 		// }
	// 		if (command[i] == ' ' || !command[i])
	// 			count++;
	// 	}
	// 	i++;
	// }
	// s = malloc(sizeof(char*) * (count + 1));
	// s[count] = 0;
	count = 0;
	i = 0;
	j = 0;
	while (command[i])
	{
		if (command[i] == '\''  || command[i] == '"')
		{
			j = i + 1;
			c = command[i];
			i++;
			while (command[i]  != c && command[i])
				i++;
			// exit(0);
			if (!command[i])
				exit(1);
			str = ft_substr(&command[j],0, i - j);
			printf("%s\n", str);
			tmp = ft_lstnew(str);
			if(command[i + 1] != ' ' || !command[i + 1])
				tmp->type = 0;
			else
				tmp->type = 1;
			ft_lstadd_back(&list_command, tmp);
			free(str);
			count++;
		}
		else if (command[i] == ' ' || i == 0)
		{
			if(i == 0)
				j = i;
			else
				j = i + 1;
			while (command[i]  != ' ' && command[i] && command[i] != '"' && command[i] != '\'')
				i++;
			str = ft_substr(&command[j],0, i - j);
			printf("%s\n", str);
			tmp = ft_lstnew(str);
			if(command[i] == '\'' || command[i] == '"')
				tmp->type = 1;
			else
				tmp->type = 0;
			ft_lstadd_back(&list_command, tmp);
			
			count++;
			free(str);
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
	// 	while(s[++i] != 0)
	// 		printf("%s\n", s[i]);
	// 	frealltab(s);
	// 	free(s);
	// 	free(command);
    }
}