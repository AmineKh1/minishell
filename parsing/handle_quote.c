/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:26:32 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/22 11:16:16 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list *command_string(char *command, t_env *env)
{
	t_list *tmp;
	t_list *list_command;
	char **s;
	char *str;
	char **strings;
	int i;
	int j;
	char c;
	int incri;
	char *tm;
	i = 0;
	j = 0;
	tmp = NULL;
	list_command = NULL;
	strings = NULL;
	if(!command)
		return NULL;
	while(command[i])
	{
		if (command[i] == '|')
		{
			j = i;
			i++;
			str = ft_substr(&command[j], 0, i - j);
			tmp = ft_lstnew(str);
			tmp->type = 0;
			ft_lstadd_back(&list_command, tmp);
			str = NULL;
		}
		else if (command[i] == '<')
		{
			j = i;
			i++;
			if (command[i] == '<')
				i++;
			str = ft_substr(&command[j], 0, i - j);
			tmp = ft_lstnew(str);
			tmp->type = 0;
			ft_lstadd_back(&list_command, tmp);
			str = NULL;
		}
		else if (command[i] == '>')
		{
			j = i;
			i++;
			if (command[i] == '>')
				i++;
			str = ft_substr(&command[j], 0, i - j);
			tmp = ft_lstnew(str);
			tmp->type = 0;
			ft_lstadd_back(&list_command, tmp);
			str = NULL;
		}
		else if (command[i] == '\'' || command[i] == '"')
		{
			j = i + 1;
			c = command[i];
			i++;
			while (command[i] && command[i] != c)
				i++;
			
				if (command[i] == '\0')
				{
					printf("minishell: syntax error need end `%c`\n", c);
					ex = 258;
					ft_lstclear(&list_command);
					return NULL;
				}
				str = ft_substr(&command[j], 0, i - j);
				if (c == '"' && (list_command == NULL || ft_memcmp(tmp->content, "<<", 3) != 0))
					str = expend_add(str, env);
				if (list_command != NULL && ft_memcmp(tmp->content, "<<", 3) == 0)
					tmp->type = HERDOCX;
				tmp = ft_lstnew(str);
				
				i++;
				if (command[i] == ' ' || !command[i] || command[i] == '<' || command[i] == '|' || command[i] == '>')
					tmp->type = -1;
				else
					tmp->type = 1;
				
				ft_lstadd_back(&list_command, tmp);
				str = NULL;
		}
		else
		{
			if (command[i] == ' ')
				i++;
			j = i;
			while (command [i] && command[i] != ' ' && command[i] != '"' && command[i] !='\'' && command[i] != '<' && command[i] != '|' && command[i] != '>')
				i++;
			str = ft_substr(&command[j], 0, i - j);
			if (list_command == NULL || ft_memcmp(tmp->content, "<<", 3) != 0)
				str = expend_add(str, env);
			strings = ft_split(str, ' ');
			incri = 0;
			while(strings[incri] != 0)
			{
				tmp = ft_lstnew(strings[incri]);
				if ((command[i] == '\'' || command[i] == '"') && strings[incri + 1] == 0)
					tmp->type = 1;
				else
					tmp->type = 0;
				ft_lstadd_back(&list_command, tmp);
				incri++;
			}
			free(strings);
			free(str);
			str = NULL;
			
		}
	}
	ex = 0;
	return list_command;
}

t_list *concatnate_strings(t_list *lst)
{
	t_list *tmp;
	t_list *list;
	t_list *delList;
	t_list *parc;
	if(!lst)
		return NULL;
	tmp = NULL;
	delList = NULL;
	list = lst;
	parc = NULL;
	while(list != NULL)
	{
		if(list->type == 1 && list->next != NULL)
		{
			list->next->content = ft_strjoin(list->content, list->next->content);
			delList = list;
			list = list->next;
			free(delList);
			continue ;
			
		}
		else
		{
			if(tmp == NULL)
			{
				tmp = list;
				parc = tmp;
			}
			else
			{
				parc->next = list;
				parc = parc->next;
			}
		}
		list = list->next;
	}
	return tmp;
}
