/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 02:21:54 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/04 22:24:41 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_error(char *exp)
{
	write(2, "export : ", 9);
	write(2, exp, ft_strlen(exp));
	write(2, " : not a valid identifier\n", 26);
	g_glb.ex = 1;
}

int	condition_name(char *c)
{
	if (!(*c >= 'a' && *c <= 'z') && !(*c >= 'A' && *c <= 'Z') && *c != '_')
		return (0);
	while (*c && *c != '=')
	{
		if (!(*c >= 'a' && *c <= 'z') \
			&& !(*c >= 'A' && *c <= 'Z') && !(*c >= '0' && *c <= '9') \
			&& *c != '_')
			return (0);
		c++;
	}
	return (1);
}
