/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expender.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:02:10 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/22 11:16:05 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	if(ft_isalnum(c) == 0 && c != '_')
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
		if (str[i] == '$' && str[i + 1] == '?')
		{
			s1 = ft_substr(&str[j], 0, i - j);
			i++;
			ret = ft_strjoin(ret, s1);
			i++;
			j = i;
			s1 = ft_itoa(ex);
			ret = ft_strjoin(ret, s1);
		}
		else if (str[i] == '$' && ft_isdigit(str[i + 1]) == 1)
		{
			s1 = ft_substr(&str[j], 0, i - j);
			i++;
			ret = ft_strjoin(ret, s1);
			j = i;
			i++;
			s1 = ft_substr(&str[j], 0, i - j);
			j = i;
			s1 = valueOf$(s1, env);
			ret = ft_strjoin(ret, s1);
			continue;
		}
		else if (str[i] == '$')
		{
			s1 = ft_substr(&str[j], 0, i - j);
			i++;
			ret = ft_strjoin(ret, s1);
			j = i;
			while (is_end$(str[i]) != 0)
				i++;
			s1 = ft_substr(&str[j], 0, i - j);

			j = i;
			s1 = valueOf$(s1, env);
			ret = ft_strjoin(ret, s1);
			continue;
		}
		i++;
	}
	s1 = ft_substr(&str[j], 0, i - j + 1);
	ret = ft_strjoin(ret, s1);
	free(str);
	return ret;
}