/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:22 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:06:23 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_front_env(t_env **lst, t_env *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_front_files(t_files **lst, t_files *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_front_minishell(t_minishell **lst, t_minishell *new)
{
	new->next = *lst;
	*lst = new;
}
