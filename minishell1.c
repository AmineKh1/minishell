/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:27:56 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/17 13:33:24 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **concatnate_strings(t_list *lst)
{
	char **str;
	int count;
	t_list *tmp;
	str = NULL;
	count = 0;
	if(!lst)
		return NULL;
	tmp = lst;
	while(tmp->next != NULL)
	{
		if(tmp->type == 0)
			count++;
		
		if(tmp->type == 1)
			tmp->next->content = ft_strjoin(tmp->content, tmp->next->content);
		tmp = tmp->next;
	}
	str = malloc(sizeof(char*) * (count + 1));
	str[count] = 0;
	count = 0;
	while(lst)
	{
		if(lst->type == 0)
			str[count++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	return str;
}
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
	s = NULL;
	list_command = NULL;
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
			if (command[i] == '\0')
				exit(1);
			str = ft_substr(&command[j],0, i - j);
			tmp = ft_lstnew(str);
			i++;
			if(command[i] == ' ' || !command[i])
				tmp->type = 0;
			else
				tmp->type = 1;
			ft_lstadd_back(&list_command, tmp);
			str = NULL;
			count++;
			tmp = NULL;
			
		}
		else
		{
			if(command[i]  == ' ')
				i++;
			j = i;
			while (command[i]  != ' ' && command[i] && command[i] != '"' && command[i] != '\'')
				i++;
			str = ft_substr(&command[j],0, i - j);
			tmp = ft_lstnew(str);
			if(command[i] == '\'' || command[i] == '"')
				tmp->type = 1;
			else
				tmp->type = 0;
			ft_lstadd_back(&list_command, tmp);
			count++;
			str = NULL;
			tmp = NULL;
		}
	}
	s = concatnate_strings(list_command);
	return s;
}

// char	**ft_get_env(char **envp)
// {
// 	int i;
// 	char **ret;

// 	i = 0;
// 	ret = malloc(...)
// 	return (ret);
// }


int main(int argc, char **argv, char **env)
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
		// frealltab(s);
		// free(s);
		// free(command);
    }
}