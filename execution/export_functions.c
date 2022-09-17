/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:24:51 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/04 22:25:26 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	export_equal(t_env **env, char *exp, int index)
{
	t_env	*new;

	if (!check_env_value(*env, exp, index))
	{
		new = env_new();
		new->key = ft_substr(exp, 0, index);
		new->value = ft_substr(exp, index + 1, ft_strlen(exp) - index - 1);
		new->dx = 2;
		env_add_back(env, new);
	}
	else
		change_env_value(env, exp, index);
}

void	export_no_equal(t_env **env, char *exp)
{
	t_env	*new;

	new = env_new();
	new->key = ft_strdup(exp);
	new->value = ft_strdup("");
	new->dx = 1;
	env_add_back(env, new);
}

int	check_existance(t_env **env, char *exp)
{
	t_env	*tmp;

	tmp = *env;
	if (!env)
		return (0);
	while (tmp)
	{
		if (ft_cmp(tmp->key, exp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	t_env_size(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		if (tmp->dx == 1 || tmp->dx == 2)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
