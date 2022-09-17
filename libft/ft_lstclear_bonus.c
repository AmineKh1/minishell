/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:26 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:06:28 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*l;
	t_list	*next;

	l = *lst;
	if (!lst)
		return ;
	while (l != NULL)
	{
		next = l -> next;
		ft_lstdelone(l);
		l = next;
	}
	*lst = NULL;
}

void	ft_lstclear_files(t_files **lst)
{
	t_files	*l;
	t_files	*next;

	l = *lst;
	if (!lst)
		return ;
	while (l != NULL)
	{
		next = l -> next;
		ft_lstdelone_files(l);
		l = next;
	}
	*lst = NULL;
}

void	ft_lstclear_minishell(t_minishell **lst)
{
	t_minishell	*l;
	t_minishell	*next;

	l = *lst;
	if (!lst)
		return ;
	while (l != NULL)
	{
		next = l->next;
		ft_lstdelone_minishell(l);
		l = next;
	}
	*lst = NULL;
}
