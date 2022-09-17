/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:31 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:06:33 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->content);
	free(lst);
}

void	ft_lstdelone_files(t_files *lst)
{
	if (!lst)
		return ;
	free(lst->name);
	free(lst);
}

void	ft_lstdelone_minishell(t_minishell *lst)
{
	if (!lst)
		return ;
	if (lst->command != NULL)
	{
		frealltab(lst->command);
		free(lst->command);
	}
	ft_lstclear_files(&lst->in);
	ft_lstclear_files(&lst->out);
	free(lst);
}
