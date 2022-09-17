/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatinate_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:19:23 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/07 18:42:50 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f' || c == '\n')
		return (0);
	return (1);
}

static void	del_list_job(t_list *list)
{
	t_list	*del_list;

	del_list = NULL;
	list->next->content = ft_strjoin(list->content, list->next->content);
	del_list = list;
	list = list->next;
	free(del_list);
}

static t_list	*concatinate_job(t_list *tmp, t_list *parc, t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->type == 1 && lst->next != NULL)
		{
			del_list_job(lst);
			lst = lst->next;
			continue ;
		}
		else if (tmp == NULL)
		{
			tmp = lst;
			parc = tmp;
		}
		else
		{
			parc->next = lst;
			parc = parc->next;
		}
		lst = lst->next;
	}
	return (tmp);
}

t_list	*concatnate_strings(t_list *lst)
{
	t_list	*tmp;
	t_list	*parc;

	tmp = NULL;
	parc = NULL;
	if (!lst)
		return (NULL);
	return (concatinate_job(tmp, parc, lst));
}

void	init_value(t_quote *q)
{
	q->i = 0;
	q->j = 0;
	q->tmp = NULL;
	q->list_cmd = NULL;
	q->ss = NULL;
}
