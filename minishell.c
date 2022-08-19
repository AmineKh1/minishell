/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:01:14 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/19 13:06:21 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *valueOf$(char *str, t_env *env)
{
	if(!str)
		return ft_strdup("");
	int len;
	len = ft_strlen(str);
	while(env)
	{
		if (ft_memcmp(str, env->key, len + 1) == 0)
		{
			free(str);
			str = ft_strdup(env->value);
			return str;
		}
		env = env->next;
	}
	free(str);
	return ft_strdup("");
}
int	is_end$(char c)
{
	if(c == '\'' || c == '\0' || c == ' ' || c == '$')
		return 0;
	return 1;
}
char *expend_add(char *str, t_env *env)
{
	char* s1;
	char *ret;
	int	i;
	int j;

	i = 0;
	j = i;
	ret =ft_strdup("");
	s1 = NULL;
	while(str[i])
	{
		if (str[i] == '$' && is_end$(str[i + 1]) == 1)
		{
			s1 = ft_substr(&str[j], 0, i - j);
			i++;
			ret = ft_strjoin(ret, s1);
			j = i;
			while (is_end$(str[i]) != 0)
				i++;
			s1 = ft_substr(&str[j], 0, i - j);

			j = i;
			// printf("'%s'\n", s1);
			s1 = valueOf$(s1, env);
			// printf("%s, %s\n",ret, s1);
			ret = ft_strjoin(ret, s1);
			continue;
		}
		i++;
	}
	s1 = ft_substr(&str[j], 0, i - j + 1);
	ret = ft_strjoin(ret, s1);
	// system("leaks minishell");
	free(str);
	return ret;
}

t_list *command_string(char *command, t_env *env)
{
	t_list *tmp;
	t_list *list_command;
	char **s;
	char *str;
	int i;
	int j;
	char c;
	
	i = 0;
	j = 0;
	tmp = NULL;
	list_command = NULL;
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
					perror("syntax error");
					exit(1);
				}
				str = ft_substr(&command[j], 0, i - j);
				//im gonna add expend her
				if (c == '"' && (list_command == NULL || ft_memcmp(tmp->content, "<<", 3) != 0))
				{
					// printf("quote %s\n", str);
					str = expend_add(str, env);
					// printf("%s", str);
				}
					
				tmp = ft_lstnew(str);
				i++;
				if (command[i] == ' ' || !command[i])
					tmp->type = -1;
				else
					tmp->type = 1;
				ft_lstadd_back(&list_command, tmp);
				str = NULL;
				// tmp = NULL;
		}
		else
		{
			if (command[i] == ' ')
				i++;
			j = i;
			while (command [i] && command[i] != ' ' && command[i] != '"' && command[i] !='\'' && command[i] != '<' && command[i] != '|' && command[i] != '>')
				i++;
			str = ft_substr(&command[j], 0, i - j);
			// printf("space %s\n", str);
		
			if (list_command == NULL || ft_memcmp(tmp->content, "<<", 3) != 0)
			{
			
				// 	exit(0);
					// system("leaks minishell");
				str = expend_add(str, env);
			}
			// printf("%s", str);
			
			tmp = ft_lstnew(str);
			
			if (command[i] == '\'' || command[i] == '"')
				tmp->type = 1;
			else
				tmp->type = 0;
			ft_lstadd_back(&list_command, tmp);
			str = NULL;
			// tmp = NULL;
			// system("leaks minishell");
			
		}
	}
	return list_command;
}

char **ft_strplit(char *env)
{
	int i;
	char **str;
	int len;

	str = NULL;
	i = -1;
	len = ft_strlen(env);
	while(env[++i] && env[i] != '=');
	str = malloc(sizeof(char *) * 3);
	str[0] = ft_substr(&env[0], 0, i);
	if(!env[i])
		str[1] = ft_strdup("");
	else
		str[1] = ft_substr(&env[i], 1, len);
	str[2] = 0;
	return str;
}

t_env	*convert_env(char **env)
{
	char **str;
	int i;
	t_env *envp;
	t_env *tmp;

	i = 0;
	str = NULL;
	envp = 0;
	while(env[i])
	{
		str = ft_strplit(env[i]);
		tmp = ft_lstnew_env(str[0], str[1]);
		ft_lstadd_back_env(&envp, tmp);
		// frealltab(str);
		free(str);
		// str = NULL;
		i++;
	}
		// 	frealltab(str);
		// free(str);
	return (envp);
}
void test_list(t_env *env)
{
	while(env)
	{
		printf("key: %s, value: %s\n", env->key, env->value);
		env = env->next;
	}
}

// void token_list(t_list *env)
// {
// 	while(env)
// 	{
// 		if(env->value == -1)
// 		{}
// 		env = env->next;
// 	}
// }

void test_list_t(t_list *env)
{
	while(env)
	{
		printf("string: %s, value: %d\n", env->content, env->type);
		env = env->next;
	}
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
	// ft_lstclear(&lst);
	return tmp;
}

int main(int argc, char **argv, char **envp)
{
	char 	*command;
	t_list *s;
	t_env *env;
	int i;

	command = NULL;
	env = convert_env(envp);
	// test_list(env);
	// system("leaks minishell");
	s = NULL;
	i = -1;
	if (argc != 1)
		exit(1);
	
	while(1)
	{
		command = readline("minishell > ");
		s = command_string(command, env);
		s = concatnate_strings(s);
		s = lexer_list(s);
		// test_list_t(s);
		ft_lstclear(&s);
		free(command);
		// system("leaks minishell");
		
	}
}

