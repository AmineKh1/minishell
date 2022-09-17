/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:31:25 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/07 18:45:12 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lord_save_me(void)
{
	printf("\n");
	return (1);
}

void	ft_pwd(t_env *env)
{
	char	*p;
	t_env	*tmp;

	tmp = env;
	p = getcwd(NULL, 0);
	if (p)
	{
		printf("%s\n", p);
		free(p);
	}
	else
	{
		while (tmp)
		{
			if (ft_cmp(tmp->key, "PWD"))
			{
				printf("%s\n", tmp->value);
				break ;
			}
			tmp = tmp->next;
		}
	}
	g_glb.ex = 0;
}
