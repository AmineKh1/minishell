/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:06:51 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:06:53 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include "../lexer/lexer.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;
	int i;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	i = 0;
	if (ft_memcmp(content, "|", 2) == 0)
		lst->type = (int)PIPE;
	else if (ft_memcmp(content, ">>", 3) == 0)
		lst->type = (int)OUTP;
	else if (ft_memcmp(content, ">", 2) == 0)
		lst->type= (int)OUT;
	else if (ft_memcmp(content, "<", 2) == 0)
		lst->type = (int)IN;
	else if (ft_memcmp(content, "<<", 3) == 0)
		lst->type = (int)HERDOC;
	else
		lst->type = (int)STRING;
	lst->next = NULL;
	return (lst);
}
