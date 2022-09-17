/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:30:24 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/04 22:31:05 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	all_n(char	*tab)
{
	if (*tab != '-')
		return (0);
	tab++;
	while (*tab)
	{
		if (*tab != 'n')
			return (0);
		tab++;
	}
	return (1);
}

void	print_arguments(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i + 1])
			printf("%s ", arg[i]);
		else
			printf("%s", arg[i]);
		i++;
	}
}

void	ft_echo(char **arg)
{
	int	i;
	int	no_line;

	i = 1;
	g_glb.ex = 0;
	if (!arg[1])
	{
		printf("\n");
		return ;
	}
	if (all_n(arg[1]))
		no_line = 1;
	else
		no_line = 0;
	if (no_line)
		i++;
	print_arguments(&arg[i]);
	if (!no_line)
		printf("\n");
}
