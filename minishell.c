/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:01:14 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/17 15:01:32 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *valueOf$(char *str, t_env *env)
{
	if(!str)
		return NULL;
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
	return NULL;
}

char *expend_add(char *str, t_env *env)
{
	char* s1;
	char* s2;
	int	i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if(str[i] = '$' && !str[i + 1])
		{
			s1 = ft_substr(&str[0], 0, i);
			i++;
			j = i;
			while(str[i++]);
			s2 = ft_substr(&str[j], 0, i - j);
			s2 = valueOf$(s2, env);
			s1 = ft_strjoin(s1, s2);
			free(str);
			return s1;
		}
		i++;
	}
	return str;
}
char **command_string(char *command, t_env *env)
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
	while(command[i])
	{
		if (command[i] == '\'' || command[i] == '"')
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
				if (c = '"')
					str = expend_add(str, env);
				tmp = ft_lstnew(str);
				i++;
				if (command[i] == ' ' || !command[i])
					tmp->type = 0;
				else
					tmp->type = 1;
				ft_lstadd_back(&list_command, tmp);
				str = NULL;
				tmp = NULL;
		}
		else
		{
			if (command[i] == ' ')
				i++;
			j = i;
			while (command [i] && command[i] != ' ' && command[i] != '"' && command[i] !='\'')
				i++;
			str = ft_substr(&command[j], 0, i - j);
			str = expend_add(str, env);
			tmp = ft_lstnew(str);
			if (command[i] == '\'' || command[i] == '"')
				tmp->type = 1;
			else
				tmp->type = 0;
			ft_lstadd_back(&list_command, tmp);
			str = NULL;
			tmp = NULL;
		}
	}
	return NULL;
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
		frealltab(str);
		free(str);
		i++;
	}
}
int main(int argc, char **argv, char **envp)
{
	char 	*command;
	char	**s;
	t_env *env;
	int i;

	command = NULL;
	env = convert_env(envp);
	s = NULL;
	i = -1;
	if (argc != 1)
		exit(1);
	
	while(1)
	{
		command = readline("minishell > ");
		s = command_string(command, env);
	}
}

