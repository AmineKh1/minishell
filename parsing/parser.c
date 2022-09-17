/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:05:35 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/04 13:44:58 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	init_string(char **str, char *s, char **ret)
{
	int	i;

	i = -1;
	while (str[++i])
		ret[i] = ft_strdup(str[i]);
	ret[i++] = ft_strdup(s);
	ret[i] = 0;
	frealltab(str);
	free(str);
}

static char	**string_table_push(char **str, char *s)
{
	int		i;
	char	**ret;

	i = 0;
	ret = NULL;
	if (str == NULL)
	{
		ret = malloc(sizeof(char *) * 2);
		if (!ret)
			return (NULL);
		ret[0] = ft_strdup(s);
		ret[1] = 0;
		return (ret);
	}
	while (str[i++])
		;
	ret = malloc((i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	init_string(str, s, ret);
	return (ret);
}

void	parse_list(t_list *lst, t_parser *p)
{
	while (lst)
	{
		if (lst->type == STRING)
			p->command = string_table_push(p->command, lst->content);
		else if (lst->type == IN || lst->type == HERDOC || lst->type == HERDOCX)
		{
			p->tmpf = ft_lstnew_file(lst->content, lst->type);
			ft_lstadd_back_files(&p->in, p->tmpf);
		}
		else if (lst->type == OUT || lst->type == OUTP)
		{
			p->tmpf = ft_lstnew_file(lst->content, lst->type);
			ft_lstadd_back_files(&p->out, p->tmpf);
		}
		else
		{
			p->tmpm = ft_lstnew_minishell(p->command, p->in, p->out);
			ft_lstadd_back_minishell(&p->list, p->tmpm);
			p->in = NULL;
			p->out = NULL;
			p->command = NULL;
		}
		lst = lst->next;
	}
}

t_minishell	*parser_job(t_list *lst)
{
	t_parser	p;

	p.list = NULL;
	p.command = NULL;
	p.in = NULL;
	p.out = NULL;
	p.tmpf = NULL;
	p.tmpm = NULL;
	parse_list(lst, &p);
	p.tmpm = ft_lstnew_minishell(p.command, p.in, p.out);
	ft_lstadd_back_minishell(&p.list, p.tmpm);
	return (p.list);
}
