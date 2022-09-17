/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:20:48 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/04 22:33:41 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(t_env *node)
{
	free(node->key);
	free(node->value);
}

void	env_del(t_env *lst)
{
	free_env(lst);
	free(lst);
}

void	env_clear(t_env *lst)
{
	t_env	*tmp;

	while (lst != 0)
	{
		free_env(lst);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	env_size(t_env *lst)
{
	int		i;
	t_env	*pointer;

	i = 0;
	pointer = lst;
	while (pointer != NULL)
	{
		pointer = pointer->next;
		i++;
	}
	return (i);
}

t_env	*env_last(t_env *lst)
{
	int	i;

	i = env_size(lst);
	while (i > 1)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}
