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
#include "minishell.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
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
t_env	*ft_lstnew_env(char *key, char *value)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->key = key;
	lst->value = value;
	lst->next = NULL;
	return (lst);
}