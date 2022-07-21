/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:46 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:06:48 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	int		i;
	int		j;
	t_list	*l;
	t_list	*h;

	i = ft_lstsize(lst);
	j = 0;
	h = NULL;
	while (j < i)
	{
		l = ft_lstnew(f(lst->content));
		if (!l)
		{
			ft_lstclear(&h);
			return (NULL);
		}
		ft_lstadd_back(&h, l);
		lst = lst->next;
		j++;
	}
	return (h);
}
