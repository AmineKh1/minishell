/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expender.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:02:10 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/11 14:41:21 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*value_ofd(char *str, t_env *env)
{
	int	len;

	if (!str)
		return (ft_strdup(""));
	len = ft_strlen(str);
	while (env)
	{
		if (ft_memcmp(str, env->key, len + 1) == 0)
		{
			free(str);
			str = ft_strdup(env->value);
			return (str);
		}
		env = env->next;
	}
	free(str);
	return (ft_strdup(""));
}

int	is_endd(char c)
{
	if (ft_isalnum(c) == 0 && c != '_')
		return (0);
	return (1);
}

static void	last_after_expend(char *str, t_expend *x)
{
	x->s1 = ft_substr(&str[x->j], 0, x->i - x->j + 1);
	x->ret = ft_strjoin(x->ret, x->s1);
	free(str);
}

char	*expend_add(char *str, t_env *env)
{
	t_expend	x;

	x.i = 0;
	x.j = x.i;
	x.ret = ft_strdup("");
	x.s1 = NULL;
	while (str != NULL && str[x.i])
	{
		if (str[x.i] == '$' && str[x.i + 1] == '?')
			exit_code(str, &x);
		else if (str[x.i] == '$' && ft_isdigit(str[x.i + 1]) == 1)
		{
			expend_number(str, &x, env);
			continue ;
		}
		else if (str[x.i] == '$')
		{
			expend_envp(str, &x, env);
			continue ;
		}
		x.i++;
	}
	if (str != NULL)
		last_after_expend(str, &x);
	return (x.ret);
}
