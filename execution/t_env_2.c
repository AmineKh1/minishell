/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:26:26 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/04 22:26:36 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_add_back(t_env **alst, t_env *new)
{
	t_env	*last;

	if (!(*alst))
	{
		*alst = new;
		new->next = 0;
		return ;
	}
	last = env_last(*alst);
	last->next = new;
	new->next = NULL;
}

t_env	*env_new(void)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new == 0)
		return (0);
	new->next = NULL;
	return (new);
}

t_env	*get_env_node(t_env **env, char *key)
{
	t_env	*tmp;

	tmp = *env;
	if (!env)
		return (NULL);
	while (tmp)
	{
		if (ft_cmp(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int	check_env_value(t_env *env, char *exp, int index)
{
	char	*key;
	t_env	*tmp;

	tmp = env;
	if (!env)
		return (0);
	key = ft_substr(exp, 0, index);
	while (tmp)
	{
		if (ft_cmp(tmp->key, key))
		{
			free(key);
			return (1);
		}
		tmp = tmp->next;
	}
	free(key);
	return (0);
}

void	change_env_value(t_env **env, char *exp, int index)
{
	char	*key;
	char	*value;
	t_env	*tmp;

	if (!env)
		return ;
	key = ft_substr(exp, 0, index);
	value = ft_substr(exp, index + 1, ft_strlen(exp) - index - 1);
	tmp = *env;
	while (tmp)
	{
		if (ft_cmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = value;
			tmp->dx = 2;
			free(key);
			return ;
		}
		tmp = tmp->next;
	}
	free(key);
	free(value);
}
