/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:16 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:06:21 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	if (!*lst)
	{
		ft_lstadd_front_env(lst, new);
		return ;
	}
	ft_lstlast_env(*lst)->next = new;
}