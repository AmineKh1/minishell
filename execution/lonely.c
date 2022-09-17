/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:36:25 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/04 22:36:26 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lonely_functions(t_minishell *cmd)
{
	if (ft_cmp(cmd->command[0], "cd"))
		return (1);
	else if (ft_cmp(cmd->command[0], "exit"))
		return (1);
	else if (ft_cmp(cmd->command[0], "export"))
		return (1);
	else if (ft_cmp(cmd->command[0], "unset"))
		return (1);
	else if (ft_cmp(cmd->command[0], "pwd"))
		return (1);
	else if (ft_cmp(cmd->command[0], "echo"))
		return (1);
	return (0);
}
